#include "main.h"

void displayMenu(int selected) {
    // main UI ����
    ui_main();

    // x,y ��ǥ �ʱⰪ
    int x = 56, y = 12;

    // ��ǥ �ű��
    gotoxy(x, y);
    setColor(7); // �⺻ ���� (���)

    // ���õ� ���� 0 �Ǵ� 1 �Ǵ� 2�̶�� �װͿ� �´� �޴��� ����
    if (selected == MENU_LOGIN) {
        setColor(14); // �����
        printf("�α���");
        setColor(7); // �⺻ �������� ���ư���
    }
    // ���õ� ���� 0�� �ƴ϶�� �������� ����
    else {
        printf("�α���");
    }

    gotoxy(x, y + 1);
    if (selected == MENU_SIGNUP) {
        setColor(14);
        printf("ȸ������");

        setColor(7);
    }
    else {
        printf("ȸ������");
    }

    gotoxy(x, y + 2);
    if (selected == MENU_EXIT) {
        setColor(14);
        printf("���� ����");
        setColor(7);
    }
    else {
        printf("���� ����");
    }
}