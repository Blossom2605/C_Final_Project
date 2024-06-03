#include "main.h"

void user_info_query(char* id, char* nickname, char* classes, int* exp, int* point, int flag) {
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };

    mysql_init(&con);

    // DB ���� ����
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    if (flag == 0) {    // �÷������ڸ� 0�� ������ member ���̺� select������ ����
        // ���ǰ˻�
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "SELECT nickname, classes, exp, point FROM member where id='%s'", id);
        mysql_query(connection, query);
        result = mysql_store_result(connection);

        if (result) {
            // ����� �����ϴ� ��쿡�� ������ ������
            row = mysql_fetch_row(result);
            if (row) {
                strcpy(nickname, row[0]);       // �г��� ����
                strcpy(classes, row[1]);        // ��� ����
                *exp = atoi(row[2]);            // ����ġ ��ȯ
                *point = atoi(row[3]);          // ����Ʈ ��ȯ
            }
            mysql_free_result(result);
        }
    }

    else if (flag == 1) {       // �÷������ڸ� 1�� ������ member ���̺� update������ ����
        // ����ġ ������ �����ϸ鼭 �ش� ����� �ƴ϶�� ��ް� ����Ʈ�� �ٲٰ� �α׸� ����
        if (*exp > 30000 && strcmp(classes, "����") != 0) {
            strcpy(classes, "����");
            *point += 100000;
            log(classes, nickname, 100000, 8);
        }
        else if ((*exp > 17000 && *exp <= 30000) && strcmp(classes, "����") != 0) {
            strcpy(classes, "����");
            *point += 30000;
            log(classes, nickname, 30000, 8);
        }
        else if ((*exp > 10000 && *exp <= 17000) && strcmp(classes, "����") != 0) {
            strcpy(classes, "����");
            *point += 10000;
            log(classes, nickname, 10000, 8);
        }
        else if ((*exp > 5000 && *exp <= 10000) && strcmp(classes, "����") != 0) {
            strcpy(classes, "����");
            *point += 5000;
            log(classes, nickname, 5000, 8);
        }
        else if ((*exp > 3000 && *exp <= 5000) && strcmp(classes, "����") != 0) {
            strcpy(classes, "����");
            *point += 3000;
            log(classes, nickname, 3000, 8);
        }
        else if ((*exp > 1000 && *exp <= 3000) && strcmp(classes, "���") != 0) {
            strcpy(classes, "���");
            *point += 1000;
            log(classes, nickname, 1000, 8);
        }

        // ���� ���� ������Ʈ(���, exp, point)
        char query[256] = { 0 };
        snprintf(query, sizeof(query), "UPDATE member SET classes='%s', exp=%d, point=%d WHERE id='%s'", classes, *exp, *point, id);
        mysql_query(connection, query);
    }

    mysql_close(connection);
}