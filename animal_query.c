#include "main.h"

void animal_query(char* id, char* name, char* type, char* growth, char* personality, int* exp, int flag) {
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };

    mysql_init(&con);

    // DB ���� ����
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    if(flag == 0) {     // �÷������ڸ� 0�� ������ myanimal ���̺� select������ ����
        // ���ǰ˻�
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "SELECT animalName, type, animalExp, growth, personality FROM myanimal where id='%s'", id);
        mysql_query(connection, query);
        result = mysql_store_result(connection);

        if (result) {
            // ����� �����ϴ� ��쿡�� ������ ������
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

    else if (flag == 1) {   //�÷������ڸ� 1�� ������ myanimal ���̺� update������ ����
        // ������ ����ġ�� �ִ����ġ�� 40�� �̻��̸� 1��, 70�� �̻��̶�� 2���� ���� ���°� �����
        int max_exp = maxExp(type);
        if (*exp > 0.4 * max_exp && strcmp(growth, "1��") != 0) {
            strcpy(growth, "1��");
            log(growth, type, 0, 9);
        }
        if (*exp > 0.7 * max_exp && strcmp(growth, "2��") != 0) {
            strcpy(growth, "2��");
            log(growth, type, 0, 9);
        }

        char query[256] = { 0 };
        snprintf(query, sizeof(query), "UPDATE myanimal SET animalExp=%d, growth='%s' WHERE id='%s'", *exp, growth, id);
        mysql_query(connection, query);
    }

    else if (flag == 2) {   //�÷������ڸ� 2�� ������ myanimal ���̺� Delete������ ����
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "DELETE FROM myanimal WHERE id='%s'", id);
        mysql_query(connection, query);
    }

    mysql_close(connection);
}