#include "main.h"

void ui_login() {
    gotoxy(57, 8);
    printf("로그인");
    gotoxy(40, 20);
    printf("q또는 Q를 입력하면 메인화면으로 돌아갑니다");
    gotoxy(37, 9);
    printf("┌─────────────────────────────────────────────┐");
    for (int i = 1; i <= 10; i++) {
        gotoxy(37, 9 + i);
        printf("│                                             │");
    }
    gotoxy(37, 19);
    printf("└─────────────────────────────────────────────┘");

    gotoxy(55, 11);
    printf("┌───────────────────────┐");
    gotoxy(55, 12);
    printf("│                       │");
    gotoxy(55, 13);
    printf("└───────────────────────┘");

    gotoxy(55, 15);
    printf("┌───────────────────────┐");
    gotoxy(55, 16);
    printf("│                       │");
    gotoxy(55, 17);
    printf("└───────────────────────┘");

    gotoxy(41, 12);
    printf("아  이  디  : ");
    gotoxy(41, 16);
    printf("비 밀 번 호 : ");

}