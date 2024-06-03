#include "main.h"

void signup(char* id, char* password, char* nickname) {
    clearScreen();  // 콘솔 초기화
    showCursor();   // 커서 위치를 가시화하기 위해 커서를 다시 보이게 함
    ui_signup();    // 회원가입 UI를 띄움

    // mysql 연동관련
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };

    // mysql 초기화
    mysql_init(&con);

    // id, password, nickname 값을 입력받고 값이 q또는 Q라면 3초 뒤에 메인화면으로 돌아감
    getInput(id, 13, 66, 12, 0);
    if (strcmp(id, "q") == 0 || strcmp(id, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("회원가입 취소 3초뒤에 메인화면으로 돌아갑니다.\n");
        Sleep(3000);
        return;
    }

    getInput(password, 13, 66, 14, 1);
    if (strcmp(password, "q") == 0 || strcmp(password, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("회원가입 취소 3초뒤에 메인화면으로 돌아갑니다.\n");
        Sleep(3000);
        return;
    }

    getInput(nickname, 12, 66, 16, 0);
    if (strcmp(nickname, "q") == 0 || strcmp(nickname, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("회원가입 취소 3초뒤에 메인화면으로 돌아갑니다.\n");
        Sleep(3000);
        return;
    }

    // 특정 ui를 가리기 위한 공백 출력
    gotoxy(41, 20);
    printf("                                                 ");

    // DB 연결 설정
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    // c에서 mysql 연동하면서 한글이 안 깨지게 설정
    mysql_set_character_set(connection, "euckr");

    // 중복 검사 쿼리 실행
    char query[256];
    // 입력된 id 또는 password가 존재하면 카운트 값을 올려서 반환
    snprintf(query, sizeof(query), "SELECT COUNT(*) FROM member WHERE id='%s' OR nickname='%s'", id, nickname);
    mysql_query(connection, query);
    result = mysql_store_result(connection);    // 반환된 결과를 result에 저장
    row = mysql_fetch_row(result);      // 결과를 배열형태로 저장

    // 반환된 값이 0보다 크다면 중복값이 있기 때문에 중복된다고 출력하고 메인화면으로 돌아감
    if (atoi(row[0]) > 0) {
        gotoxy(42, 18);
        printf("ID 또는 닉네임이 중복됩니다.\n");
        // 메인메뉴에서 커서 안보이게 다시 커서 숨김
        hideCursor();
        // while 루프 안이라서 바로 초기화 안되게 키입력 감지될때까지 멈춤
        _getch();

        // 결과값들 전부 초기화 및 mysql 닫기
        mysql_free_result(result);
        mysql_close(connection);
        return; 
    }
    else {
        //그게 아니라면 입력 데이터를 member 테이블에 추가함
        snprintf(query, sizeof(query), "INSERT INTO member (id, password, nickname) VALUES ('%s', '%s', '%s')", id, password, nickname);
        // mysql_query 함수는 실패하면 1을 반환하기 때문에 쿼리 실패시 실패 문구 출력
        if (mysql_query(connection, query)) {
            gotoxy(42, 18);
            printf("회원가입 실패: %s\n", mysql_error(connection));
            hideCursor();
            _getch();
        }
        // 아닌 경우 데이터가 추가되고 회원가입을 성공했다는 메시지를 출력함
        else {
            gotoxy(42, 18);
            printf("회원가입 성공! 환영합니다 %s 님\n", nickname);
            hideCursor();
            _getch();
        }
    }

    // 결과값들 전부 초기화 및 mysql 닫기
    mysql_free_result(result);
    mysql_close(connection);
}