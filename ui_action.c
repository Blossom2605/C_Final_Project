#include "main.h"

void ui_action(int selected_menu) {
    setColor(3);
    gotoxy(2, 25);
    printf("┏────────────────────────────────────────────────────────────────────────────────────────┓");
    gotoxy(2, 26);
    printf("│                                                                                        │                                  ");
    gotoxy(2, 27);
    printf("│                                                                                        ├─────────────────");
    gotoxy(2, 28);
    printf("│                                                                                        │                                  ");
    gotoxy(2, 29);
    printf("┗────────────────────────────────────────────────────────────────────────────────────────┛");

    gotoxy(108, 25);
    printf("┏──────────┓");
    gotoxy(108, 26);
    printf("│          │");
    gotoxy(108, 27);
    printf("┤          │");
    gotoxy(108, 28);
    printf("│          │");
    gotoxy(108, 29);
    printf("┗──────────┛");

    setColor(7); // 기본 색상 (흰색)
    gotoxy(5, 27);
    if (selected_menu == 0) {
        setColor(14); // 노란색
        printf("▶분양받기");
        setColor(7);
    }
    else printf(" 분양받기 ");

    gotoxy(24, 27);
    if (selected_menu == 1) {
        setColor(14); // 노란색
        printf("▶놀아주기");
        setColor(7);
    }
    else printf(" 놀아주기 ");

    gotoxy(43, 27);
    if (selected_menu == 2) {
        setColor(14); // 노란색
        printf("▶먹이주기");
        setColor(7);
    }
    else printf(" 먹이주기 ");

    gotoxy(62, 27);
    if (selected_menu == 3) {
        setColor(14); // 노란색
        printf("▶미니게임");
        setColor(7);
    }
    else printf(" 미니게임 ");

    gotoxy(80, 27);
    if (selected_menu == 4) {
        setColor(14); // 노란색
        printf("▶로그보기");
        setColor(7);
    }
    else printf(" 로그보기 ");

    gotoxy(109, 27);
    if (selected_menu == 5) {
        setColor(14); // 노란색
        printf("▶게임종료");
        setColor(7);
    }
    else {
        gotoxy(110, 27);
        printf("게임종료");
    }
}