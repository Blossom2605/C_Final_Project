// 내가 정의한 main.h 헤더 불러오기
#include "main.h"

// 메인함수 실행
int main() {
    bool success;   // 로그인 여부 판단 bool형 변수
    int selectedMenu = MENU_LOGIN;  // 해당 값에 따라 현재 선택 중인 값의 메뉴가 강조됨
    int ch;         // 키입력을 받아서 값을 변환하거나 메뉴를 선택함
    // 로그인, 회원가입을 위한 아이디, 비밀번호, 닉네임 변수 선언 및 초기화
    char id[13] = "", insert_id[13] = "";
    char password[13] = "", insert_password[13] = "";
    char nickname[12] = "", insert_nickname[12] = "";

    hideCursor(); // 커서 숨기기

    // 메뉴 루프
    while (1) {
        clearScreen();  // 화면 전체 초기화
        displayMenu(selectedMenu);  // 메인 메뉴 출력

        // 키입력대기함수를 ch 변수에 담아서 키입력 감지
        ch = _getch();
        if (ch == 224) { // 방향키는 224
            ch = _getch();
            if (ch == 72) { // 윗방향키는 72 입력이 감지되면 값을 감소시키고 0보다 작은 값이 되면 2로 값을 바꿈
                selectedMenu--;
                if (selectedMenu < 0) selectedMenu = NUM_MENU_ITEMS - 1;
            }
            else if (ch == 80) { // 아랫방향키는 80 입력이 감지되면 값을 증가시키고 최대 메뉴보다 큰 값이 되면 0으로 값을 바꿈
                selectedMenu++;
                if (selectedMenu >= NUM_MENU_ITEMS) selectedMenu = 0;
            }
        }
        else if (ch == 13) { // 엔터 키는 13
            // 선택 메뉴값이 0이라면 로그인 함수를 실행
            if (selectedMenu == MENU_LOGIN) {
                success = login(id, password);  // 해당 함수에서 계정, 암호가 둘 다 같으면 1을 반환 아니면 0을 반환
                // 로그인에서 1을 반환받으면 로그인을 하고 main_game 루프를 실행
                if (success) {
                    main_game(success, id);
                }
            }
            // 선택 메뉴값이 1이라면 회원가입 함수를 실행
            else if (selectedMenu == MENU_SIGNUP) {
                signup(insert_id, insert_password, insert_nickname);
            }
            // 선택 메뉴값이 2라면 게임 종료 함수를 실행
            else if (selectedMenu == MENU_EXIT) {
                // 게임 종료
                gotoxy(0, 29);
                exit(0);
            }
        }
    }

    return 0;
}