#include "main.h";

void show_care_menu(int selected_menu, int flag) {
    // x,y ��ǥ ����
    int x = 26, y = 6;

    // �÷��� ���� 0�϶� ���� �޴� ����
    if (flag == 0) {
        gotoxy(x, y);
        if (selected_menu == 0) {
            setColor(14);
            printf("��å�ϱ�");
            gotoxy(x, y + 1);
            printf("����Ʈ : 0");
            gotoxy(x, y + 2);
            printf("ȹ�� ����ġ : 1 ~ 20");
            setColor(7);
        }
        else {
            printf("��å�ϱ�");
            gotoxy(x, y + 1);
            printf("����Ʈ : 0");
        }

        gotoxy(x, y + 4);
        if (selected_menu == 1) {
            setColor(14);
            printf("��������");
            gotoxy(x, y + 5);
            printf("����Ʈ : 100");
            gotoxy(x, y + 6);
            printf("ȹ�� ����ġ : -100 or 100");
            setColor(7);
        }
        else {
            printf("��������");
            gotoxy(x, y + 5);
            printf("����Ʈ : 100");
        }

        gotoxy(x, y + 8);
        if (selected_menu == 2) {
            setColor(14);
            printf("�� �����ֱ�");
            gotoxy(x, y + 9);
            printf("����Ʈ : 500");
            gotoxy(x, y + 10);
            printf("ȹ�� ����ġ : 200 ~ 300");
            setColor(7);
        }
        else {
            printf("�� �����ֱ�");
            gotoxy(x, y + 9);
            printf("����Ʈ : 500");
        }

        gotoxy(x, y + 12);
        if (selected_menu == 3) {
            setColor(14);
            printf("���డ��");
            gotoxy(x, y + 13);
            printf("����Ʈ : 1000");
            gotoxy(x, y + 14);
            printf("ȹ�� ����ġ : 500 ~ 1000");
            setColor(7);
        }
        else {
            printf("���డ��");
            gotoxy(x, y + 13);
            printf("����Ʈ : 1000");
        }
    }

    // �÷��� ���� 1�϶� ���õ� �޴� ����
    if (flag == 1) {
        gotoxy(x, y);
        if (selected_menu == 0) {
            setColor(14);
            printf("��");
            gotoxy(x, y + 1);
            printf("����Ʈ : 10");
            gotoxy(x, y + 2);
            printf("ȹ�� ����ġ : 20");
            setColor(7);
        }
        else {
            printf("��");
            gotoxy(x, y + 1);
            printf("����Ʈ : 10");
        }

        gotoxy(x, y + 4);
        if (selected_menu == 1) {
            setColor(14);
            printf("����");
            gotoxy(x, y + 5);
            printf("����Ʈ : 500");
            gotoxy(x, y + 6);
            printf("ȹ�� ����ġ : 200 ~ 300");
            setColor(7);
        }
        else {
            printf("����");
            gotoxy(x, y + 5);
            printf("����Ʈ : 500");
        }

        gotoxy(x, y + 8);
        if (selected_menu == 2) {
            setColor(14);
            printf("����ũ");
            gotoxy(x, y + 9);
            printf("����Ʈ : 600");
            gotoxy(x, y + 10);
            printf("ȹ�� ����ġ : 200 ~ 400");
            setColor(7);
        }
        else {
            printf("����ũ");
            gotoxy(x, y + 9);
            printf("����Ʈ : 600");
        }

        gotoxy(x, y + 12);
        if (selected_menu == 3) {
            setColor(14);
            printf("�ְ�� 1++ �ѿ�");
            gotoxy(x, y + 13);
            printf("����Ʈ : 1500");
            gotoxy(x, y + 14);
            printf("ȹ�� ����ġ : 1000 ~ 1500");
            setColor(7);
        }
        else {
            printf("�ְ�� 1++ �ѿ�");
            gotoxy(x, y + 13);
            printf("����Ʈ : 1500");
        }
    }
}