#include "main.h"

void ui_action(int selected_menu) {
    setColor(3);
    gotoxy(2, 25);
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    gotoxy(2, 26);
    printf("��                                                                                        ��                                  ");
    gotoxy(2, 27);
    printf("��                                                                                        ������������������������������������");
    gotoxy(2, 28);
    printf("��                                                                                        ��                                  ");
    gotoxy(2, 29);
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

    gotoxy(108, 25);
    printf("������������������������");
    gotoxy(108, 26);
    printf("��          ��");
    gotoxy(108, 27);
    printf("��          ��");
    gotoxy(108, 28);
    printf("��          ��");
    gotoxy(108, 29);
    printf("������������������������");

    setColor(7); // �⺻ ���� (���)
    gotoxy(5, 27);
    if (selected_menu == 0) {
        setColor(14); // �����
        printf("���о�ޱ�");
        setColor(7);
    }
    else printf(" �о�ޱ� ");

    gotoxy(24, 27);
    if (selected_menu == 1) {
        setColor(14); // �����
        printf("������ֱ�");
        setColor(7);
    }
    else printf(" ����ֱ� ");

    gotoxy(43, 27);
    if (selected_menu == 2) {
        setColor(14); // �����
        printf("�������ֱ�");
        setColor(7);
    }
    else printf(" �����ֱ� ");

    gotoxy(62, 27);
    if (selected_menu == 3) {
        setColor(14); // �����
        printf("���̴ϰ���");
        setColor(7);
    }
    else printf(" �̴ϰ��� ");

    gotoxy(80, 27);
    if (selected_menu == 4) {
        setColor(14); // �����
        printf("���α׺���");
        setColor(7);
    }
    else printf(" �α׺��� ");

    gotoxy(109, 27);
    if (selected_menu == 5) {
        setColor(14); // �����
        printf("����������");
        setColor(7);
    }
    else {
        gotoxy(110, 27);
        printf("��������");
    }
}