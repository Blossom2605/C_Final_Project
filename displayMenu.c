#include "main.h"

void displayMenu(int selected) {
    // main UI 띄우기
    ui_main();

    // x,y 좌표 초기값
    int x = 56, y = 12;

    // 좌표 옮기기
    gotoxy(x, y);
    setColor(7); // 기본 색상 (흰색)

    // 선택된 값이 0 또는 1 또는 2이라면 그것에 맞는 메뉴를 강조
    if (selected == MENU_LOGIN) {
        setColor(14); // 노란색
        printf("로그인");
        setColor(7); // 기본 색상으로 돌아가기
    }
    // 선택된 값이 0이 아니라면 강조하지 않음
    else {
        printf("로그인");
    }

    gotoxy(x, y + 1);
    if (selected == MENU_SIGNUP) {
        setColor(14);
        printf("회원가입");

        setColor(7);
    }
    else {
        printf("회원가입");
    }

    gotoxy(x, y + 2);
    if (selected == MENU_EXIT) {
        setColor(14);
        printf("게임 종료");
        setColor(7);
    }
    else {
        printf("게임 종료");
    }
}