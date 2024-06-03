#include "main.h"

void ui_animalList(char* animalName, char* type, int* call) {
    int key;
    int x = 6, y = 4;
    int selected_menu = 0;
    int num_menu = 8;

    while(1) {
        clearRegion(x, y, 107, 23);

        setColor(3);

        gotoxy(x, y);
        printf("┏─────────────────────────────────────────────────────────────────────────────────────────────────────────┓");
        for (int i = 1; i <= 21; i++) {
            gotoxy(x, y + i);
            printf("│                                                                                                         │");
        }
        gotoxy(x, y+22);
        printf("┗─────────────────────────────────────────────────────────────────────────────────────────────────────────┛");

        setColor(7);

        gotoxy(52, 3);
        printf("동물 분양받기");

        show_animalList(selected_menu);

        key = _getch();

        //esc키 누르면 나가기
        if (key == 27) {
            *call = 0;
            break;
        }

        // 방향키 입력 처리
        else if (key == 224) {
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
            case 72:  // 위쪽 방향키
                if (selected_menu >= 4)
                    selected_menu -= 4;
                break;
            case 80:  // 아래쪽 방향키
                if (selected_menu < 4)
                    selected_menu += 4;
                break;
            }
        }
        // 엔터 키 입력 처리
        else if (key == 13) {
            *call = 1;
            clearRegion(x+1, y+1, 105, 21);
            gotoxy(48, 8);
            printf("이름");
            gotoxy(54, 7);
            printf("┌────────────────────┐");
            gotoxy(54, 8);
            printf("│                    │");
            gotoxy(54, 9);
            printf("└────────────────────┘");
            showCursor();
            getInput(animalName, 10, 55, 8, 0);
            hideCursor();
 
            if (selected_menu == 0) {
                strcpy(type, "강아지");
            }
            else if (selected_menu == 1) {
                strcpy(type, "고양이");
            }
            else if (selected_menu == 2) {
                strcpy(type, "족제비");
            }
            else if (selected_menu == 3) {
                strcpy(type, "팬더");
            }
            else if (selected_menu == 4) {
                strcpy(type, "토끼");
            }
            else if (selected_menu == 5) {
                strcpy(type, "돌고래");
            }
            else if (selected_menu == 6) {
                strcpy(type, "펭귄");
            }
            else if (selected_menu == 7) {
                strcpy(type, "용");
            }
            break;
        }
    }
}