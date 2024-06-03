#include "main.h"

bool login(char* id, char* password) {
    // 쿼리 결과를 저장하는거까지는 signup.c와 유사함
    clearScreen();
    showCursor();
    ui_login();

    bool connect;
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };
    MYSQL_RES* resultName = NULL;
    MYSQL_ROW rowName = { 0 };

    mysql_init(&con);

    getInput(id, 13, 57, 12, 0);
    if (strcmp(id, "q") == 0 || strcmp(id, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("로그인 취소 3초뒤에 메인화면으로 돌아갑니다.\n");
        Sleep(3000);
        return 0;
    }
    getInput(password, 13, 57, 16, 1);
    if (strcmp(password, "q") == 0 || strcmp(password, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("로그인 취소 3초뒤에 메인화면으로 돌아갑니다.\n");
        Sleep(3000);
        return 0;
    }

    // DB 연결 설정
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    char query[256];
    snprintf(query, sizeof(query), "SELECT COUNT(*) FROM member WHERE id='%s' AND password='%s'", id, password);
    mysql_query(connection, query);
    result = mysql_store_result(connection);
    row = mysql_fetch_row(result);

    // 결과값이 1이상이라면 1이라는 의미기 때문에 해당 값을 success 변수에 저장함
    bool success = atoi(row[0]) > 0;
    // 결과값 초기화
    mysql_free_result(result);

    // success가 1이라면
    if (success) {
        // member 테이블 id의 nickname을 반환받아 로그인 성공 메시지를 출력함
        snprintf(query, sizeof(query), "SELECT nickname FROM member WHERE id='%s'", id);
        mysql_query(connection, query);

        resultName = mysql_store_result(connection);

        rowName = mysql_fetch_row(resultName);
        char nickname[50];
        // 반환받은 결과 문자열을 nickname 변수에 복사
        strcpy(nickname, rowName[0]);

        // connect값을 1로 바꿔서 1값을 반환하도록 함
        connect = 1;
        gotoxy(54, 8);
        printf("로그인 성공!\n");
        gotoxy(50, 18);
        printf("환영합니다. %s님\n", nickname);
        gotoxy(40, 20); 
        printf("                                             ");
        hideCursor();
        _getch();
    }
    // success가 1이 아니라면
    else {
        // id또는 비밀번호가 틀렸다는 메시지를 출력
        // connect 값을 0으로 바꿔서 0을 반환하도록 함
        connect = 0;
        gotoxy(42, 18);
        printf("ID 또는 비밀번호가 올바르지 않습니다.\n");
        gotoxy(40, 20);
        printf("                                             ");
        hideCursor();
        _getch();
    }

    // 사용한 결과 초기화 및 mysql 연동 종료
    mysql_free_result(resultName);
    mysql_close(connection);

    // connect 값 반환
    return connect;
}