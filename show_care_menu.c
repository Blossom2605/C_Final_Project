#include "main.h";

void show_care_menu(int selected_menu, int flag) {
    // x,y 좌표 지정
    int x = 26, y = 6;

    // 플래그 값이 0일때 관련 메뉴 강조
    if (flag == 0) {
        gotoxy(x, y);
        if (selected_menu == 0) {
            setColor(14);
            printf("산책하기");
            gotoxy(x, y + 1);
            printf("포인트 : 0");
            gotoxy(x, y + 2);
            printf("획득 경험치 : 1 ~ 20");
            setColor(7);
        }
        else {
            printf("산책하기");
            gotoxy(x, y + 1);
            printf("포인트 : 0");
        }

        gotoxy(x, y + 4);
        if (selected_menu == 1) {
            setColor(14);
            printf("병원가기");
            gotoxy(x, y + 5);
            printf("포인트 : 100");
            gotoxy(x, y + 6);
            printf("획득 경험치 : -100 or 100");
            setColor(7);
        }
        else {
            printf("병원가기");
            gotoxy(x, y + 5);
            printf("포인트 : 100");
        }

        gotoxy(x, y + 8);
        if (selected_menu == 2) {
            setColor(14);
            printf("공 던져주기");
            gotoxy(x, y + 9);
            printf("포인트 : 500");
            gotoxy(x, y + 10);
            printf("획득 경험치 : 200 ~ 300");
            setColor(7);
        }
        else {
            printf("공 던져주기");
            gotoxy(x, y + 9);
            printf("포인트 : 500");
        }

        gotoxy(x, y + 12);
        if (selected_menu == 3) {
            setColor(14);
            printf("여행가기");
            gotoxy(x, y + 13);
            printf("포인트 : 1000");
            gotoxy(x, y + 14);
            printf("획득 경험치 : 500 ~ 1000");
            setColor(7);
        }
        else {
            printf("여행가기");
            gotoxy(x, y + 13);
            printf("포인트 : 1000");
        }
    }

    // 플래그 값이 1일때 선택된 메뉴 강조
    if (flag == 1) {
        gotoxy(x, y);
        if (selected_menu == 0) {
            setColor(14);
            printf("물");
            gotoxy(x, y + 1);
            printf("포인트 : 10");
            gotoxy(x, y + 2);
            printf("획득 경험치 : 20");
            setColor(7);
        }
        else {
            printf("물");
            gotoxy(x, y + 1);
            printf("포인트 : 10");
        }

        gotoxy(x, y + 4);
        if (selected_menu == 1) {
            setColor(14);
            printf("고등어");
            gotoxy(x, y + 5);
            printf("포인트 : 500");
            gotoxy(x, y + 6);
            printf("획득 경험치 : 200 ~ 300");
            setColor(7);
        }
        else {
            printf("고등어");
            gotoxy(x, y + 5);
            printf("포인트 : 500");
        }

        gotoxy(x, y + 8);
        if (selected_menu == 2) {
            setColor(14);
            printf("케이크");
            gotoxy(x, y + 9);
            printf("포인트 : 600");
            gotoxy(x, y + 10);
            printf("획득 경험치 : 200 ~ 400");
            setColor(7);
        }
        else {
            printf("케이크");
            gotoxy(x, y + 9);
            printf("포인트 : 600");
        }

        gotoxy(x, y + 12);
        if (selected_menu == 3) {
            setColor(14);
            printf("최고급 1++ 한우");
            gotoxy(x, y + 13);
            printf("포인트 : 1500");
            gotoxy(x, y + 14);
            printf("획득 경험치 : 1000 ~ 1500");
            setColor(7);
        }
        else {
            printf("최고급 1++ 한우");
            gotoxy(x, y + 13);
            printf("포인트 : 1500");
        }
    }
}