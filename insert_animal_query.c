#include "main.h"

void insert_animal_query(char* id, Animal* pet) {
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };
    mysql_init(&con);

    // DB ���� ����
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    // ����� ���� ����ü�� ���� �߰�
    char query[256];
    snprintf(query, sizeof(query),"INSERT INTO myanimal (id, animalName, type, personality) VALUES ('%s', '%s', '%s', '%s')", id, pet->nickname, pet->type, pet->temperament);
    mysql_query(connection, query);

    mysql_close(connection);
}