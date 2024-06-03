#include "main.h"

void animal_draw(char* filename, char* grow) {
    // 전달받은 인자값을 합쳐서 동물종류_성장상태.txt 문자열로 만듬
    char files[100];
    strcpy(files, filename);
    strcat(files, "_");
    strcat(files, grow);
    strcat(files, ".txt");

    // files값의 파일을 읽기 모드로 엶
    FILE* file = fopen(files, "r");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 파일의 끝까지 출력
    int i = 1;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        gotoxy(58, 0 + i);
        printf(line);
        i++;
    }

    //파일을 닫음
    fclose(file);
}