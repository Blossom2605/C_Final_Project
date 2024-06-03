#include "main.h"

void signup(char* id, char* password, char* nickname) {
    clearScreen();  // �ܼ� �ʱ�ȭ
    showCursor();   // Ŀ�� ��ġ�� ����ȭ�ϱ� ���� Ŀ���� �ٽ� ���̰� ��
    ui_signup();    // ȸ������ UI�� ���

    // mysql ��������
    MYSQL con = { 0 };
    MYSQL* connection = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };

    // mysql �ʱ�ȭ
    mysql_init(&con);

    // id, password, nickname ���� �Է¹ް� ���� q�Ǵ� Q��� 3�� �ڿ� ����ȭ������ ���ư�
    getInput(id, 13, 66, 12, 0);
    if (strcmp(id, "q") == 0 || strcmp(id, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("ȸ������ ��� 3�ʵڿ� ����ȭ������ ���ư��ϴ�.\n");
        Sleep(3000);
        return;
    }

    getInput(password, 13, 66, 14, 1);
    if (strcmp(password, "q") == 0 || strcmp(password, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("ȸ������ ��� 3�ʵڿ� ����ȭ������ ���ư��ϴ�.\n");
        Sleep(3000);
        return;
    }

    getInput(nickname, 12, 66, 16, 0);
    if (strcmp(nickname, "q") == 0 || strcmp(nickname, "Q") == 0) {
        hideCursor();
        gotoxy(38, 20);
        printf("ȸ������ ��� 3�ʵڿ� ����ȭ������ ���ư��ϴ�.\n");
        Sleep(3000);
        return;
    }

    // Ư�� ui�� ������ ���� ���� ���
    gotoxy(41, 20);
    printf("                                                 ");

    // DB ���� ����
    connection = mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, NULL, 0);

    // c���� mysql �����ϸ鼭 �ѱ��� �� ������ ����
    mysql_set_character_set(connection, "euckr");

    // �ߺ� �˻� ���� ����
    char query[256];
    // �Էµ� id �Ǵ� password�� �����ϸ� ī��Ʈ ���� �÷��� ��ȯ
    snprintf(query, sizeof(query), "SELECT COUNT(*) FROM member WHERE id='%s' OR nickname='%s'", id, nickname);
    mysql_query(connection, query);
    result = mysql_store_result(connection);    // ��ȯ�� ����� result�� ����
    row = mysql_fetch_row(result);      // ����� �迭���·� ����

    // ��ȯ�� ���� 0���� ũ�ٸ� �ߺ����� �ֱ� ������ �ߺ��ȴٰ� ����ϰ� ����ȭ������ ���ư�
    if (atoi(row[0]) > 0) {
        gotoxy(42, 18);
        printf("ID �Ǵ� �г����� �ߺ��˴ϴ�.\n");
        // ���θ޴����� Ŀ�� �Ⱥ��̰� �ٽ� Ŀ�� ����
        hideCursor();
        // while ���� ���̶� �ٷ� �ʱ�ȭ �ȵǰ� Ű�Է� �����ɶ����� ����
        _getch();

        // ������� ���� �ʱ�ȭ �� mysql �ݱ�
        mysql_free_result(result);
        mysql_close(connection);
        return; 
    }
    else {
        //�װ� �ƴ϶�� �Է� �����͸� member ���̺� �߰���
        snprintf(query, sizeof(query), "INSERT INTO member (id, password, nickname) VALUES ('%s', '%s', '%s')", id, password, nickname);
        // mysql_query �Լ��� �����ϸ� 1�� ��ȯ�ϱ� ������ ���� ���н� ���� ���� ���
        if (mysql_query(connection, query)) {
            gotoxy(42, 18);
            printf("ȸ������ ����: %s\n", mysql_error(connection));
            hideCursor();
            _getch();
        }
        // �ƴ� ��� �����Ͱ� �߰��ǰ� ȸ�������� �����ߴٴ� �޽����� �����
        else {
            gotoxy(42, 18);
            printf("ȸ������ ����! ȯ���մϴ� %s ��\n", nickname);
            hideCursor();
            _getch();
        }
    }

    // ������� ���� �ʱ�ȭ �� mysql �ݱ�
    mysql_free_result(result);
    mysql_close(connection);
}