#include "merge.hpp"
using namespace std;

void Png_merge::allo(){
    for(int row=0;row<height;row++){
        str[row]=new Pixel[width];
    }
    SetPng::setpng(height,width,str);

}

void Png_merge::image(const char *filename){
    FILE*fs = fopen(filename, "wb");
     if (!fs) {
    fprintf(stderr, "could not open png file.\n");
    exit(1);
    }
    png_structp png_ptr;
    png_infop info_ptr;
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fprintf(stderr, "could not initialize png struct\n");
        exit(1);
    }
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        fclose(fs);
        exit(1);
    }

    png_init_io(png_ptr, fs);
    png_set_IHDR(png_ptr, info_ptr, width , height, COLOR_DEPTH,
                PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
                PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png_ptr, info_ptr);
    png_write_image(png_ptr, (png_byte **)str);

    /* clean up PNG-related data structures */
    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fs);
    for(int i = 0; i < height; i++) {
    delete[] str[i];
    }
}

void Png_merge::overlayImages(const char* largeImageFile, const char* smallImageFile,const char*filename) {
    // 큰 이미지 파일 열기
    FILE *largeFile = fopen(largeImageFile, "rb");
    if (!largeFile) {
        fprintf(stderr, "Error: Could not open %s\n", largeImageFile);
        return;
    }

    // 작은 이미지 파일 열기
    FILE *smallFile = fopen(smallImageFile, "rb");
    if (!smallFile) {
        fclose(largeFile);
        fprintf(stderr, "Error: Could not open %s\n", smallImageFile);
        return;
    }

    // 출력 파일 열기
    FILE *outputFile = fopen(filename, "wb");
    if (!outputFile) {
        fclose(largeFile);
        fclose(smallFile);
        fprintf(stderr, "Error: Could not create LOGO.png\n");
        return;
    }

    //png file header 세팅
    png_byte header[8];
    
    //큰 이미지의 정보 가져오기
    //파일 첫 8바이트 읽고 헤더 유효성 체크
    fread(header, 1, 8, largeFile);
    if(png_sig_cmp(header,0,8)){
        fprintf(stderr, "Error: 유효 PNG 파일 아님!\n");
        fclose(largeFile);
        return;
    }
    png_structp largeReadPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL); //libpng 구조체 생성
    if (!largeReadPtr) {
        fprintf(stderr, "could not initialize png struct\n");
        exit(1);
    }
    png_infop largeInfoPtr = png_create_info_struct(largeReadPtr); //libpng 정보 구조체 생성
    if (!largeInfoPtr) {
        png_destroy_write_struct(&largeReadPtr, (png_infopp)NULL);
        fclose(largeFile);
        exit(1);
    }

    png_init_io(largeReadPtr, largeFile); //libpng에 파일 연결
    png_set_sig_bytes(largeReadPtr,8);   
    png_read_info(largeReadPtr, largeInfoPtr); //png 파일 정보 읽기
    

    int largeWidth = png_get_image_width(largeReadPtr, largeInfoPtr);
    int largeHeight = png_get_image_height(largeReadPtr, largeInfoPtr);


    // 작은 이미지의 정보 가져오기

    //파일 첫 8바이트 읽고 헤더 유효성 체크
    fread(header, 1, 8, smallFile);
    if(png_sig_cmp(header,0,8)){
        fprintf(stderr, "Error: 유효 PNG 파일 아님!\n");
        fclose(smallFile);
        return;
    }
    png_structp smallReadPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!smallReadPtr) {
        fprintf(stderr, "could not initialize png struct\n");
        exit(1);
    }
    png_infop smallInfoPtr = png_create_info_struct(smallReadPtr);
    if (!smallInfoPtr) {
        png_destroy_write_struct(&smallReadPtr, (png_infopp)NULL);
        fclose(smallFile);
        exit(1);
    }

    png_init_io(smallReadPtr, smallFile);
    png_set_sig_bytes(smallReadPtr,8);
    png_read_info(smallReadPtr, smallInfoPtr);

    int smallWidth = png_get_image_width(smallReadPtr, smallInfoPtr);
    int smallHeight = png_get_image_height(smallReadPtr, smallInfoPtr);
   
    // 작은 이미지를 큰 이미지의 중앙에 배치하기 위한 좌표 계산 (좌상단 꼭짓점)
    int posX = (largeWidth - smallWidth) / 2;
    int posY = (largeHeight - smallHeight) / 2;

    // 출력 파일에 대한 PNG 구조체 생성
    png_structp writePtr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop writeInfoPtr = png_create_info_struct(writePtr);

    // 출력 파일에 대한 정보 설정
    png_init_io(writePtr, outputFile);
    png_set_IHDR(writePtr, writeInfoPtr, largeWidth, largeHeight, COLOR_DEPTH, 
                PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE, 
                PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(writePtr, writeInfoPtr);
    /* write image data to disk */

    // 큰 이미지 파일에서 행 별로 데이터 읽기 및 쓰기
    png_bytep largeRow = (png_bytep)malloc(sizeof(png_byte) * largeWidth * 4);
    png_bytep smallRow = (png_bytep)malloc(sizeof(png_byte) * smallWidth * 4);

    for (int row = 0; row < largeHeight; row++) {
        // 큰 이미지 파일에서 행 데이터 읽기
        png_read_row(largeReadPtr, largeRow, NULL);

        // 작은 이미지를 큰 이미지 위에 중앙에 배치하여 덮어쓰기
        if (row >= posY && row < posY + smallHeight) {
            png_read_row(smallReadPtr, smallRow, NULL);
            for (int col = 0; col < smallWidth; col++) {
            if (smallRow[col * 4 + 3] == 255) { // alpha 값 확인 (투명할 경우 복사x)
                memcpy(largeRow + ((posX + col) * 4), smallRow + (col * 4), 4);
                }
            }
        }

        // 파일에 행 데이터 쓰기
        png_write_row(writePtr, largeRow);
    }


    // 작업 완료 후 메모리 정리 및 파일 닫기
    png_write_end(writePtr, NULL);
    png_destroy_write_struct(&writePtr, &writeInfoPtr);
    png_destroy_read_struct(&largeReadPtr, &largeInfoPtr, NULL);
    png_destroy_read_struct(&smallReadPtr, &smallInfoPtr, NULL);

    fclose(largeFile);
    fclose(smallFile);
    fclose(outputFile);
    free(smallRow);
    free(largeRow);
}
