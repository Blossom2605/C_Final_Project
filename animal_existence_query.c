#include "main.h"

bool animal_existence_query(char* id) {
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };
    MYSQL_RES* resultName = NULL;
    MYSQL_ROW rowName = { 0 };

    mysql_init(&con);

    // DB 연결 설정
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    // myanimal의 값이 있다면 1반환 없다면 0반환
    char query[256];
    snprintf(query, sizeof(query), "SELECT COUNT(*) FROM myanimal WHERE id='%s'", id);
    mysql_query(connection, query);
    result = mysql_store_result(connection);
    row = mysql_fetch_row(result);

    bool TrueFalse = atoi(row[0]) > 0;

    mysql_free_result(result);
    mysql_close(connection);

    return TrueFalse;
}