#include "main.h"

void show_animalList(int selected_menu) {
    // animal_list.txt를 읽기 모드로 염
    FILE* file = fopen("animal_list.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 파일의 정보를 저장하고 출력하는 변수
    char line[100];
    int index = 0;

    // line값이 NULL이 될때까지 루프
    while (fgets(line, sizeof(line), file) != NULL) {
        // 구조체의 정보가 담긴 변수들
        char type[20];
        int max_exp;
        char temperament[20];

        if (sscanf(line, "%s %d %s", type, &max_exp, temperament) == 3) {
            // x,y 좌표값 
            // 박스 ui가 4개를 넘어가면 y좌표가 바뀜, x좌표는 index를 4로 나눈값에 26을 곱해서 좌표를 지정(26칸마다 배치)
            int x = (index % 4) * 26;
            int y = (index < 4) ? 8 : 16;

            setColor(3);

            gotoxy(x + 8, y);
            printf("┌──────────────────────┐");
            for (int i = 1; i <= 5; i++) {
                gotoxy(x + 8, y + i);
                printf("│                      │");
            }
            gotoxy(x + 8, y+6);
            printf("└──────────────────────┘");

            setColor(7);

           // 글자 위치 출력을 위해 좌표가 재지정
            x = (index % 4) * 26;
            y = (index < 4) ? 10 : 18;

            // 분양가능 동물 출력
            gotoxy(x + 10, y);
            printf("종   류    : %s", type);
            gotoxy(x + 10, y + 1);
            printf("성   격    : %s", temperament);
            gotoxy(x + 10, y + 2);
            printf("최대 경험치: %d", max_exp);

            // 인덱스 변화를 위해 인덱스값 증가
            index++;
        }
    }

    // 파일 닫기
    fclose(file);

    // 현재 키값에 따라 선택되어있는 메뉴 강조
    gotoxy(10, 10);
    if (selected_menu == 0) {
        setColor(14);
        printf("종   류    : 강아지");
        setColor(7);
    }
    else printf("종   류    : 강아지");

    gotoxy(36, 10);
    if (selected_menu == 1) {
        setColor(14);
        printf("종   류    : 고양이");
        setColor(7);
    }
    else printf("종   류    : 고양이");

    gotoxy(62, 10);
    if (selected_menu == 2) {
        setColor(14);
        printf("종   류    : 족제비");
        setColor(7);
    }
    else printf("종   류    : 족제비");

    gotoxy(88, 10);
    if (selected_menu == 3) {
        setColor(14);
        printf("종   류    : 팬더");
        setColor(7);
    }
    else printf("종   류    : 팬더");

    gotoxy(10, 18);
    if (selected_menu == 4) {
        setColor(14);
        printf("종   류    : 토끼");
        setColor(7);
    }
    else printf("종   류    : 토끼");

    gotoxy(36, 18);
    if (selected_menu == 5) {
        setColor(14);
        printf("종   류    : 돌고래");
        setColor(7);
    }
    else printf("종   류    : 돌고래");

    gotoxy(62, 18);
    if (selected_menu == 6) {
        setColor(14);
        printf("종   류    : 펭귄");
        setColor(7);
    }
    else printf("종   류    : 펭귄");

    gotoxy(88, 18);
    if (selected_menu == 7) {
        setColor(14);
        printf("종   류    : 용");
        setColor(7);
    }
    else printf("종   류    : 용");
}