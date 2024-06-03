#include "main.h"

void minigame(int* point, int flag, int* call) {
    int key;
    int selected_menu = 0;
    int num_menu = 2;
    int result = 0, get_point = 0;
    
    while (1) {
        int x = 23, y = 1;
        
        // 미니게임 UI영역 초기화
        clearRegion(x, y, 29, 23);

        // 플래그 값이 2인 UI 출력
        ui_list(2);

        x = 26, y = 6;

        // 선택되어있는 메뉴 강조
        gotoxy(x, y);
        if (selected_menu == 0) {
            setColor(14);
            printf("동물레이싱");
            gotoxy(x, y + 1);
            printf("보상");
            gotoxy(x, y + 2);
            printf("1등 3000, 2등 1500");
            gotoxy(x, y + 3);
            printf("3등 500, 4등 100 포인트");

            setColor(7);
        }
        else {
            printf("동물레이싱");
        }

        gotoxy(x, y + 5);
        if (selected_menu == 1) {
            setColor(14);
            printf("타자게임");
            gotoxy(x, y + 6);
            printf("보상");
            gotoxy(x, y + 7);
            printf("점수 * 100 포인트");
            setColor(7);
        }
        else {
            printf("타자게임");
        }        

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
            case 72:  // 위쪽 방향키
                selected_menu--;
                if (selected_menu < 0) selected_menu = num_menu - 1;
                break;
            case 80:  // 아래쪽 방향키
                selected_menu++;
                if (selected_menu >= num_menu) selected_menu = 0;
                break;
            }
        }

        // 엔터키 처리
        else if (key == 13) {
            // 선택된 메뉴값이 0이라면
            if (selected_menu == 0) {
                // 동물레이싱 게임 진행
                get_point = animalRace(result);

                // 획득 포인트가 0을 초과하면 관련 로그 작성
                if (get_point > 0) {
                    log("동물레이싱", "", get_point, 5);
                }
                // 획득 포인트가 없을때 관련 로그 작성
                else {
                    log("", "", 0, 6);
                }
                
                // 획득 포인트를 point값에 더하고 루프 종료
                *point += get_point;
                break;
            }

            // 선택된 메뉴값이 1이라면
            else if (selected_menu == 1) {
                // 타이핑 게임 진행
                get_point = typingGame(result);
                
                //타이핑 게임 관련 로그 작성
                log("", "", get_point, 4);

                // 획득 포인트를 point값에 더하고 루프 종료
                *point += get_point;
                break;
            }
        }
    }
}