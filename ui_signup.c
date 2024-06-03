#include "main.h"

void ui_signup() {
    gotoxy(56, 8);
    printf("회원가입");
    gotoxy(41, 20);
    printf("q또는 Q를 입력하면 회원가입이 취소됩니다");
    gotoxy(37, 9);
    printf("┌─────────────────────────────────────────────┐");
    for (int i = 1; i <= 10; i++) {
        gotoxy(37, 9 + i);
        printf("│                                             │");
    }
    gotoxy(37, 19);
    printf("└─────────────────────────────────────────────┘");

    gotoxy(65, 11);
    printf("┌─────────────┐");
    gotoxy(65, 12);
    printf("│             │");
    gotoxy(65, 13);
    printf("├─────────────┤");
    gotoxy(65, 14);
    printf("│             │");
    gotoxy(65, 15);
    printf("├─────────────┤");
    gotoxy(65, 16);
    printf("│             │");
    gotoxy(65, 17);
    printf("└─────────────┘");

    gotoxy(41, 12);
    printf("ID(최대길이 13)       : ");
    gotoxy(41, 14);
    printf("PASSWORD(최대길이 13) : ");
    gotoxy(41, 16);
    printf("닉네임(최대 12글자)   : ");
}