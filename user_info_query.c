#include "main.h"

void user_info_query(char* id, char* nickname, char* classes, int* exp, int* point, int flag) {
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };

    mysql_init(&con);

    // DB 연결 설정
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    if (flag == 0) {    // 플래그인자를 0을 받으면 member 테이블에 select쿼리를 진행
        // 조건검색
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "SELECT nickname, classes, exp, point FROM member where id='%s'", id);
        mysql_query(connection, query);
        result = mysql_store_result(connection);

        if (result) {
            // 결과가 존재하는 경우에만 정보를 가져옴
            row = mysql_fetch_row(result);
            if (row) {
                strcpy(nickname, row[0]);       // 닉네임 복사
                strcpy(classes, row[1]);        // 계급 복사
                *exp = atoi(row[2]);            // 경험치 변환
                *point = atoi(row[3]);          // 포인트 변환
            }
            mysql_free_result(result);
        }
    }

    else if (flag == 1) {       // 플래그인자를 1을 받으면 member 테이블에 update쿼리를 진행
        // 경험치 조건을 만족하면서 해당 계급이 아니라면 계급과 포인트를 바꾸고 로그를 남김
        if (*exp > 30000 && strcmp(classes, "공작") != 0) {
            strcpy(classes, "공작");
            *point += 100000;
            log(classes, nickname, 100000, 8);
        }
        else if ((*exp > 17000 && *exp <= 30000) && strcmp(classes, "후작") != 0) {
            strcpy(classes, "후작");
            *point += 30000;
            log(classes, nickname, 30000, 8);
        }
        else if ((*exp > 10000 && *exp <= 17000) && strcmp(classes, "백작") != 0) {
            strcpy(classes, "백작");
            *point += 10000;
            log(classes, nickname, 10000, 8);
        }
        else if ((*exp > 5000 && *exp <= 10000) && strcmp(classes, "자작") != 0) {
            strcpy(classes, "자작");
            *point += 5000;
            log(classes, nickname, 5000, 8);
        }
        else if ((*exp > 3000 && *exp <= 5000) && strcmp(classes, "남작") != 0) {
            strcpy(classes, "남작");
            *point += 3000;
            log(classes, nickname, 3000, 8);
        }
        else if ((*exp > 1000 && *exp <= 3000) && strcmp(classes, "기사") != 0) {
            strcpy(classes, "기사");
            *point += 1000;
            log(classes, nickname, 1000, 8);
        }

        // 유저 정보 업데이트(계급, exp, point)
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "UPDATE member SET classes='%s', exp=%d, point=%d WHERE id='%s'", classes, *exp, *point, id);
        mysql_query(connection, query);
    }

    mysql_close(connection);
}