// ���� ������ main.h ��� �ҷ�����
#include "main.h"

// �����Լ� ����
int main() {
    bool success;   // �α��� ���� �Ǵ� bool�� ����
    int selectedMenu = MENU_LOGIN;  // �ش� ���� ���� ���� ���� ���� ���� �޴��� ������
    int ch;         // Ű�Է��� �޾Ƽ� ���� ��ȯ�ϰų� �޴��� ������
    // �α���, ȸ�������� ���� ���̵�, ��й�ȣ, �г��� ���� ���� �� �ʱ�ȭ
    char id[13] = "", insert_id[13] = "";
    char password[13] = "", insert_password[13] = "";
    char nickname[12] = "", insert_nickname[12] = "";

    hideCursor(); // Ŀ�� �����

    // �޴� ����
    while (1) {
        clearScreen();  // ȭ�� ��ü �ʱ�ȭ
        displayMenu(selectedMenu);  // ���� �޴� ���

        // Ű�Է´���Լ��� ch ������ ��Ƽ� Ű�Է� ����
        ch = _getch();
        if (ch == 224) { // ����Ű�� 224
            ch = _getch();
            if (ch == 72) { // ������Ű�� 72 �Է��� �����Ǹ� ���� ���ҽ�Ű�� 0���� ���� ���� �Ǹ� 2�� ���� �ٲ�
                selectedMenu--;
                if (selectedMenu < 0) selectedMenu = NUM_MENU_ITEMS - 1;
            }
            else if (ch == 80) { // �Ʒ�����Ű�� 80 �Է��� �����Ǹ� ���� ������Ű�� �ִ� �޴����� ū ���� �Ǹ� 0���� ���� �ٲ�
                selectedMenu++;
                if (selectedMenu >= NUM_MENU_ITEMS) selectedMenu = 0;
            }
        }
        else if (ch == 13) { // ���� Ű�� 13
            // ���� �޴����� 0�̶�� �α��� �Լ��� ����
            if (selectedMenu == MENU_LOGIN) {
                success = login(id, password);  // �ش� �Լ����� ����, ��ȣ�� �� �� ������ 1�� ��ȯ �ƴϸ� 0�� ��ȯ
                // �α��ο��� 1�� ��ȯ������ �α����� �ϰ� main_game ������ ����
                if (success) {
                    main_game(success, id);
                }
            }
            // ���� �޴����� 1�̶�� ȸ������ �Լ��� ����
            else if (selectedMenu == MENU_SIGNUP) {
                signup(insert_id, insert_password, insert_nickname);
            }
            // ���� �޴����� 2��� ���� ���� �Լ��� ����
            else if (selectedMenu == MENU_EXIT) {
                // ���� ����
                gotoxy(0, 29);
                exit(0);
            }
        }
    }

    return 0;
}