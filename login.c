#include "main.h"

bool login(char* id, char* password) {
    // ���� ����� �����ϴ°ű����� signup.c�� ������
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
        printf("�α��� ��� 3�ʵڿ� ����ȭ������ ���ư��ϴ�.\n");
        Sleep(3000);
        return 0;
    }
    getInput(password, 13, 57, 16, 1);
    if (strcmp(password, "q") == 0 || strcmp(password, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("�α��� ��� 3�ʵڿ� ����ȭ������ ���ư��ϴ�.\n");
        Sleep(3000);
        return 0;
    }

    // DB ���� ����
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    mysql_set_character_set(connection, "euckr");

    char query[256];
    snprintf(query, sizeof(query), "SELECT COUNT(*) FROM member WHERE id='%s' AND password='%s'", id, password);
    mysql_query(connection, query);
    result = mysql_store_result(connection);
    row = mysql_fetch_row(result);

    // ������� 1�̻��̶�� 1�̶�� �ṉ̀� ������ �ش� ���� success ������ ������
    bool success = atoi(row[0]) > 0;
    // ����� �ʱ�ȭ
    mysql_free_result(result);

    // success�� 1�̶��
    if (success) {
        // member ���̺� id�� nickname�� ��ȯ�޾� �α��� ���� �޽����� �����
        snprintf(query, sizeof(query), "SELECT nickname FROM member WHERE id='%s'", id);
        mysql_query(connection, query);

        resultName = mysql_store_result(connection);

        rowName = mysql_fetch_row(resultName);
        char nickname[50];
        // ��ȯ���� ��� ���ڿ��� nickname ������ ����
        strcpy(nickname, rowName[0]);

        // connect���� 1�� �ٲ㼭 1���� ��ȯ�ϵ��� ��
        connect = 1;
        gotoxy(54, 8);
        printf("�α��� ����!\n");
        gotoxy(50, 18);
        printf("ȯ���մϴ�. %s��\n", nickname);
        gotoxy(40, 20); 
        printf("                                             ");
        hideCursor();
        _getch();
    }
    // success�� 1�� �ƴ϶��
    else {
        // id�Ǵ� ��й�ȣ�� Ʋ�ȴٴ� �޽����� ���
        // connect ���� 0���� �ٲ㼭 0�� ��ȯ�ϵ��� ��
        connect = 0;
        gotoxy(42, 18);
        printf("ID �Ǵ� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�.\n");
        gotoxy(40, 20);
        printf("                                             ");
        hideCursor();
        _getch();
    }

    // ����� ��� �ʱ�ȭ �� mysql ���� ����
    mysql_free_result(resultName);
    mysql_close(connection);

    // connect �� ��ȯ
    return connect;
}