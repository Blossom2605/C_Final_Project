#include "main.h"

void errorMsg(int choice) {
    setColor(12);

    gotoxy(43, 9);
    printf("┌──────────────────────────┐");
    for (int i = 1; i <= 5; i++) {
        gotoxy(43, 9 + i);
        printf("│                          │");
    }
    gotoxy(43, 15);
    printf("└──────────────────────────┘");

    gotoxy(43, 10);

    if (choice == 0) {   // 동물 보유중일때 분양시도 시 에러메시지
        printf("!! Error !!");

        gotoxy(44, 12);
        printf("이미 동물을 분양받았습니다");

        setColor(7);

        _getch();
    }

    else if (choice == 1) {   // 동물 분양안하고 놀아주기 or 먹이주기 or 미니게임 시도할 때
        printf("!! Error !!");

        gotoxy(44, 12);
        printf("동물을 먼저 분양받아주세요");

        setColor(7);
        _getch();
    }

    else if (choice == 2) {   // log.txt가 비어있을때 로그보기를 시도하는 경우
        printf("!! Error !!");

        gotoxy(44, 12);
        printf("로그 기록이 없습니다!");

        setColor(7);
        _getch();
    }

    else if (choice == 10) {
        clearScreen();
        setColor(12);

        gotoxy(43, 9);
        printf("┌──────────────────────────┐");
        for (int i = 1; i <= 5; i++) {
            gotoxy(43, 9 + i);
            printf("│                          │");
        }
        gotoxy(43, 15);
        printf("└──────────────────────────┘");

        gotoxy(43, 10);
        printf("!! Game Over !!");

        gotoxy(44, 12);
        printf("     게임을 종료합니다");

        setColor(7);

        gotoxy(0, 27);
    }
}