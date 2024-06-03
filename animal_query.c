#include "main.h"

void animal_query(char* id, char* name, char* type, char* growth, char* personality, int* exp, int flag) {
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };

    mysql_init(&con);

    // DB 연결 설정
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    if(flag == 0) {     // 플래그인자를 0을 받으면 myanimal 테이블에 select쿼리를 진행
        // 조건검색
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "SELECT animalName, type, animalExp, growth, personality FROM myanimal where id='%s'", id);
        mysql_query(connection, query);
        result = mysql_store_result(connection);

        if (result) {
            // 결과가 존재하는 경우에만 정보를 가져옴
            row = mysql_fetch_row(result);
            if (row) {
                strcpy(name, row[0]);
                strcpy(type, row[1]);
                *exp = atoi(row[2]);
                strcpy(growth, row[3]);
                strcpy(personality, row[4]);

            }
            mysql_free_result(result);
        }
    }

    else if (flag == 1) {   //플래그인자를 1을 받으면 myanimal 테이블에 update쿼리를 진행
        // 동물의 경험치가 최대경험치의 40퍼 이상이면 1차, 70퍼 이상이라면 2차로 성장 상태가 변경됨
        int max_exp = maxExp(type);
        if (*exp > 0.4 * max_exp && strcmp(growth, "1차") != 0) {
            strcpy(growth, "1차");
            log(growth, type, 0, 9);
        }
        if (*exp > 0.7 * max_exp && strcmp(growth, "2차") != 0) {
            strcpy(growth, "2차");
            log(growth, type, 0, 9);
        }

        char query[256] = { 0 };
        snprintf(query, sizeof(query), "UPDATE myanimal SET animalExp=%d, growth='%s' WHERE id='%s'", *exp, growth, id);
        mysql_query(connection, query);
    }

    else if (flag == 2) {   //플래그인자를 2를 받으면 myanimal 테이블에 Delete쿼리를 진행
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "DELETE FROM myanimal WHERE id='%s'", id);
        mysql_query(connection, query);
    }

    mysql_close(connection);
}