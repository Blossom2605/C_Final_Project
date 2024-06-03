#include "main.h"

void ui_animal(char* name, char* type, char* growth, char* personality, int* exp) {
    gotoxy(7, 10);
    printf("동물 정보");
    setColor(3);
    gotoxy(2, 11);
    printf("┏──────────────────┓");
    gotoxy(2, 12);
    printf("│                  │");
    gotoxy(2, 13);
    printf("┣──────────────────┫");
    for (int i = 1; i <= 9; i++) {
        gotoxy(2, 13 + i);
        printf("│                  │");
    }
    gotoxy(2, 23);
    printf("┗──────────────────┛");
    setColor(7);

    gotoxy(9, 12);
    printf("%s", type);        //동물 종류
    gotoxy(3, 15);
    printf(" 이름  : %s", name); //동물 이름
    gotoxy(3, 17);
    printf(" 단계  : %s", growth);    //성장 단계
    gotoxy(3, 19);
    printf(" EXP  : %d", *exp);  //경험치
    gotoxy(3, 21);
    printf(" 성격  : %s", personality); //성격  
}