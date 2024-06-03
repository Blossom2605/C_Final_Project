#include "main.h"

bool answer(int flag) {
    int key;
    int selected_menu = 0;
    int num_menu = 2;

    int x = 23, y = 1;

    while (1) {
        setColor(3);

        gotoxy(43, 9);
        printf("┌───────────────────────────────┐");
        for (int i = 1; i <= 6; i++) {
            gotoxy(43, 9 + i);
            printf("│                               │");
        }
        gotoxy(43, 16);
        printf("└───────────────────────────────┘");

        setColor(7);

        // 플래그 값에 따라 경고문 출력 내용이 달라짐
        gotoxy(43, 10);
        if (flag == 0) {
            printf("!! 정말 해당 놀이를 하실건가요?");
            if (selected_menu == 0) {
                setColor(14);
                gotoxy(53, 13);
                printf("예");
                setColor(7);
            }
            else {
                gotoxy(53, 13);
                printf("예");
            }

            if (selected_menu == 1) {
                setColor(14);
                gotoxy(62, 13);
                printf("아니오");
                setColor(7);
            }
            else {
                gotoxy(62, 13);
                printf("아니오");
            }

        }

        if (flag == 1) {
            printf("!! 정말 해당 먹이를 먹일까요?");
            if (selected_menu == 0) {
                setColor(14);
                gotoxy(53, 13);
                printf("예");
                setColor(7);
            }
            else {
                gotoxy(53, 13);
                printf("예");
            }

            if (selected_menu == 1) {
                setColor(14);
                gotoxy(62, 13);
                printf("아니오");
                setColor(7);
            }
            else {
                gotoxy(62, 13);
                printf("아니오");
            }
        }

        // 잠정 보류
        //if (flag == 2) {
        //    printf("♣미니게임을 진행합니다♣");
        //    if (selected_menu == 0) {
        //        setColor(14);
        //        gotoxy(53, 13);
        //        printf("예");
        //        setColor(7);
        //    }
        //    else {
        //        gotoxy(53, 13);
        //        printf("예");
        //    }

        //    if (selected_menu == 1) {
        //        setColor(14);
        //        gotoxy(62, 13);
        //        printf("아니오");
        //        setColor(7);
        //    }
        //    else {
        //        gotoxy(62, 13);
        //        printf("아니오");
        //    }
        //}

        // 플래그 값이 10이 전달되었다면 포인트 부족하다고 경고하고 돌아감
        gotoxy(51, 12);
        if (flag == 10) {
            printf("포인트가 부족합니다");
        }

        key = _getch();

        if (key == 224) {
            key = _getch();
            switch (key) {
            case 75:  // 왼쪽 방향키
                if (selected_menu > 0)
                    selected_menu--;
                break;
            case 77:  // 오른쪽 방향키
                if (selected_menu < num_menu - 1)
                    selected_menu++;
                break;
            }
        }

        // 예(selected_menu값이 0)라면 true값 반환 / 아니라면 false값 반환
        else if (key == 13) {
            clearRegion(43, 9, 33, 8);
            if (selected_menu == 0) {
                return true;
            }

            if (selected_menu == 1) {
                return false;
            }
        }
    }
}