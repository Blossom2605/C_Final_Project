#include "main.h"

void care_animal(char* animalType, int* point, int* use_point, char* growth, int* exp, int* get_exp, int flag, int* call) {
    // 변수들
    int key;
    int x = 23, y = 1;
    int selected_menu = 0;
    int num_menu = 4;
    *get_exp = 0;
    *use_point = 0;

    // 무한루프
    while (1) {
        // ui구역만 초기화
        clearRegion(x, y, 29, 23);

        // ui를 flag값에 따라 그림
        ui_list(flag);

        // flag가 0이라면 놀아주기 관련 메뉴를 1이라면 먹이주기 관련 메뉴를 출력
        if (flag == 0) {
            show_care_menu(selected_menu, 0);
        }
        else if (flag == 1) {
            show_care_menu(selected_menu, 1);
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

        // 엔터키를 입력받으면
        else if (key == 13) {
            // 정말 선택한게 맞는지 물어보기 위한 bool 변수
            bool ans;
            // 다시 한번 묻는 함수를 flag에 따라 관련 ui를 출력하고 결과값 반환
            ans = answer(flag);

            // ans가 1이라면
            if (ans) {
                // 플래그 값이 0이라면
                if (flag == 0) {
                    // 선택된 메뉴에 따라 사용한 포인트, 획득 경험치를 정함
                    if (selected_menu == 0) {
                        *use_point = 0;
                        *get_exp = rand() % 20 + 1;
                    }

                    else if (selected_menu == 1) {
                        if (*point < 100) {
                            answer(10);
                        }
                        else {
                            int selec = rand() % 2;
                            *use_point = -100;

                            if (selec == 0) *get_exp = -100;
                            else if (selec == 1) *get_exp = 100;
                        }
                    }

                    else if (selected_menu == 2) {
                        if (*point < 500) {
                            answer(10);
                        }
                        else {
                            *use_point = -500;
                            *get_exp = rand() % 101 + 200;
                        }
                    }

                    else if (selected_menu == 3) {
                        if (*point < 1000) {
                            answer(10);
                        }
                        else {
                            *use_point = -1000;
                            *get_exp = rand() % 501 + 500;
                        }
                    }
                }

                // 플래그 값이 1이라면
                if (flag == 1) {
                    if (selected_menu == 0) {
                        if (*point < 10) {
                            answer(10);
                        }
                        else {
                            *use_point = -10;
                            *get_exp = 20;
                        }
                    }

                    else if (selected_menu == 1) {
                        if (*point < 500) {
                            answer(10);
                        }

                        else {
                            *use_point = -500;
                            *get_exp = rand() % 101 + 200;
                        }
                    }

                    else if (selected_menu == 2) {
                        if (*point < 600) {
                            answer(10);
                        }

                        else {
                            *use_point = -600;
                            *get_exp = rand() % 201 + 200;
                        }
                    }

                    else if (selected_menu == 3) {
                        if (*point < 1500) {
                            answer(10);
                        }

                        else {
                            *use_point = -1500;
                            *get_exp = rand() % 501 + 1000;
                        }
                    }
                }

                // 획득 경험치가 0을 초과하거나 사용된 포인트가 0 미만이라면
                if (*get_exp > 0 || *use_point < 0) {
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

                    // exp에 획득 경험치를 추가, point를 사용 포인트만큼 차감
                    *exp += *get_exp;
                    *point -= ~(*use_point) + 1;

                    // 사용포인트와 획득 동물 경험치 출력(포인트는 부호 반전 값에 +1을 해서 -부호를 출력되지 않게함
                    gotoxy(49, 12);
                    printf("사용 포인트 : %d", ~(*use_point) + 1);
                    gotoxy(49, 13);
                    printf("획득 동물 경험치 : %d", *get_exp);
                    _getch();
                }
                
                // 루프 종료
                break;
            }

            // 0이 반환되면 answer UI 영역에 없어진 UI를 다시 그리게 함
            else {
                animal_draw(animalType, growth);
                if (flag == 0) ui_action(1);
                else if (flag == 1) ui_action(2);
            }
        }
    }
}