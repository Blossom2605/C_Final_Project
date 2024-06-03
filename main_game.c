#include "main.h"

void main_game(bool comp, char* id) {
    int selected_menu = 0;  // 선택된 메뉴 인덱스 (0부터 시작)
    int key;    // 키 입력 감지해서 키값을 저장하는 변수

    int num_menu = 6, exp = 0, point = 0;       // 메뉴 개수, 경험치, 포인트
    int callFunc = 1;   // esc를 감지했을때 함수 루프를 빠져나오게하는 변수
    int animalExp = 0;  // 동물 경험치
    int max = 0;        // 동물 종류마다 최대 경험치를 담는 변수

    // 유저 닉네임, 계급
    char nickname[50] = "", classes[10] = "";
    // 동물 이름, 종류, 성장상태, 성격
    char animalName[50] = "", animalType[50] = "", growth[20] = "", personality[20] = "";

    // myaniaml의 현재 로그인된 아이디에 동물 정보가 있는지 판단하는 bool 변수
    bool TrueFalse;

    // 난수 생성기 초기화
    srand(time(NULL));

    // comp값이 1이라면
    if (comp) {
        while (1) {
            // 사용 포인트, 획득 경험치
            int use_point = 0, get_exp = 0;

            // 유저 정보를 반환 받아서 변수에 저장하는 쿼리 함수
            user_info_query(id, nickname, classes, &exp, &point, 0);

            // 유저가 동물을 가지고 있는지 판단하는 쿼리 함수
            TrueFalse = animal_existence_query(id);

            // 콘솔 초기화
            clearScreen();

            // 유저가 동물을 가지고 있다면
            if (TrueFalse) {
                // id기준으로 동물 정보를 반환하는 쿼리
                animal_query(id, animalName, animalType, growth, personality, &animalExp, 0);
                // 동물 종류와 성장 상태 별로 아스키아트를 출력
                animal_draw(animalType, growth);
                // 동물 정보 띄우는 ui 그리기
                ui_animal(animalName, animalType, growth, personality, &animalExp);
            }

            // 유저가 가지고 있는 동물 종류에 따라 최대 경험치를 지정
            max = maxExp(animalType);

            // 유저 정보 및 행동 UI를 그리기
            ui_user(nickname, classes, exp, point);
            ui_action(selected_menu);

            // 키 입력 처리
            key = _getch();

            // 방향키 입력 처리
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

            // 엔터 키 입력 처리
            else if (key == 13) {
                if (selected_menu == 0) {   // 동물 분양받기
                    if (!TrueFalse) {       // 동물 정보가 없을때만 분양을 받을 수 있음
                        Animal myAnimal;    // 동물 구조체 선언
                        // 구조체의 정보를 담을 동물이름과 종류 변수 선언 및 초기화
                        char animalName[10] = "", type[10] = "";
                        // 동물리스트 파일 읽어서 전체 출력하고 입력으로 선택하고 동물별명(animalName)까지 입력받음
                        ui_animalList(animalName, type, &callFunc);
                        if (callFunc) {
                            // 선택한 동물의 타입과 별명을 아래 함수에 전달해서 구조체에 저장
                            save_animal_list(animalName, type, &myAnimal);
                            // 동물을 분양받을때 UI 그리기 
                            ui_saveAnimal(&myAnimal);
                            // 키입력 대기
                            _getch();
                            // 선택한 동물의 정보와 동물이름을 myanimal 테이블에 INSERT로 저장하는 쿼리
                            insert_animal_query(id, &myAnimal);
                            // 로그 남기기
                            log("를(을) 분양받았다!", &myAnimal.type, 0, 1);
                        }
                    }
                    else {  // 동물정보가 있을때 해당 메뉴가 선택되면 0번째 에러메시지를 출력
                        errorMsg(0);
                    }
                }

                else if (selected_menu == 1) {      // 놀아주기
                    if (TrueFalse) {    // 동물 분양을 제외한 메뉴는 동물 정보가 있을때만 사용가능
                        // 해당 함수에 flag 인자를 전달해서 놀아주기와 관련된 로직 및 ui를 그리게 함
                        care_animal(animalType, &point, &use_point, growth, &animalExp, &get_exp, 0, &callFunc);
                        // 로그 남기기
                        log("과(와) 놀아주었다!", animalType, get_exp, 2);
                        // 동물 정보 및 플레이어 포인트 업데이트
                        animal_query(id, animalName, animalType, growth, personality, &animalExp, 1);
                        user_info_query(id, nickname, classes, &exp, &point, 1);
                    }
                    else {
                        // 동물정보가 없을때 해당 메뉴가 선택되면 1번째 에러메시지를 출력
                        errorMsg(1);
                    }
                }

                else if (selected_menu == 2) {      // 먹이주기
                    if (TrueFalse) {        // 동물정보가 있다면
                        // 해당 함수에 플래그인자 1을 전달해서 관련 로직 및 UI를 출력
                        care_animal(animalType, &point, &use_point, growth, &animalExp, &get_exp, 1, &callFunc);
                        // 동물 정보 및 플레이어 포인트 업데이트
                        animal_query(id, animalName, animalType, growth, personality, &animalExp, 1);
                        user_info_query(id, nickname, classes, &exp, &point, 1);
                        // 로그 남기기
                        log("에게 먹이를 주었다!", animalType, get_exp, 3);
                    }
                    else {
                        // 동물 정보가 없을때 해당 메뉴가 선택되면 1번째 에러메시지를 출력
                        errorMsg(1);
                    }
                }

                else if (selected_menu == 3) {      // 미니게임
                    if (TrueFalse) {    // 동물정보가 있다면
                        // 미니게임 관련 로직 실행
                        minigame(&point, 2, &callFunc);
                        // 유저 정보(point) 업데이트
                        user_info_query(id, nickname, classes, &exp, &point, 1);
                    }
                    else {
                        errorMsg(1);
                    }
                }

                else if (selected_menu == 4) {      // 로그보기
                    // log.txt 파일을 읽기 모드로 file 변수에 저장
                    FILE* file = fopen("log.txt", "r");


                    fseek(file, 0, SEEK_END);  // 파일 포인터를 파일 끝으로 이동
                    long file_size = ftell(file);  // 파일 포인터의 현재 위치를 얻어 파일 크기를 반환
                    fclose(file);   // 파일 닫음

                    if (file_size != 0) {   // 파일의 사이즈가 0이 아니라면
                        // 10번째 로그 로직을 실행 후 출력
                        log("", "", 0, 10);
                        _getch();
                    }
                    else {
                        // 파일 사이즈가 0이면 2번째 에러메시지를 띄움
                        errorMsg(2);
                    }
                }

                else if (selected_menu == 5) {  // 게임종료
                    log("", "", 0, 0);       // log파일 초기화 로직 실행
                    errorMsg(10);   // 게임 종료 메시지 출력
                    // 프로그램 종료
                    exit(0);
                }
            }

            if (TrueFalse) {        // 동물의 정보가 있고
                if (animalExp >= max) { // 동물의 경험치가 최대경험치 이상이라면
                    // x,y 좌표 초기값
                    int x = 23, y = 1;

                    // 글자색 지정
                    setColor(3);

                    // ui출력
                    gotoxy(x, y);
                    printf("┏──────────────────────────────────────────────────────────────┓");
                    gotoxy(x, y + 1);
                    printf("│                                                              │");
                    for (int i = 1; i <= 21; i++) {
                        gotoxy(x, y + i);
                        printf("│                                                              │");
                    }
                    gotoxy(x, y + 22);
                    printf("┗──────────────────────────────────────────────────────────────┛");

                    // 글자색 복귀
                    setColor(7);

                    // 동물의 경험치가 넘어서서 돌아가고 몇 경험치를 얻었는지 출력하고 입력대기
                    gotoxy(37, 11);
                    // 문장을 0.1초마다 한글자씩 출력해 타이핑 연출
                    slowPrint(100, "동물의 경험치가 최대치를 넘어섰습니다..");

                    _getch();

                    // UI부분만 초기화해서 다른 UI가 사라지지 않게 방지
                    clearRegion(24, 2, 59, 20);
                    // 경험치는 500 ~ 1500 사이의 랜덤값으로 획득함
                    get_exp = rand() % 500 + 1000;
                    // 획득 경험치를 exp에 더해줌
                    exp += get_exp;
                    gotoxy(37, 10);
                    printf("%s", animalName);
                    slowPrint(100, "은(는) 자신의 고향으로 돌아갔습니다");
                    gotoxy(37, 11);
                    printf("%d", get_exp);
                    slowPrint(100, " 경험치 획득!");

                    // 키입력 대기
                    _getch();

                    // 유저 경험치, 계급, 포인트 갱신 및 동물 정보 삭제
                    user_info_query(id, nickname, classes, &exp, &point, 1);
                    animal_query(id, animalName, animalType, growth, personality, &animalExp, 2);

                    // 로그 남기기
                    log(animalType, animalName, get_exp, 11);
                }
            }
        }
    }

    else {
        clearScreen();
        return;
    }
}