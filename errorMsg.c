#include "main.h"

void errorMsg(int choice) {
    setColor(12);

    gotoxy(43, 9);
    printf("��������������������������������������������������������");
    for (int i = 1; i <= 5; i++) {
        gotoxy(43, 9 + i);
        printf("��                          ��");
    }
    gotoxy(43, 15);
    printf("��������������������������������������������������������");

    gotoxy(43, 10);

    if (choice == 0) {   // ���� �������϶� �о�õ� �� �����޽���
        printf("!! Error !!");

        gotoxy(44, 12);
        printf("�̹� ������ �о�޾ҽ��ϴ�");

        setColor(7);

        _getch();
    }

    else if (choice == 1) {   // ���� �о���ϰ� ����ֱ� or �����ֱ� or �̴ϰ��� �õ��� ��
        printf("!! Error !!");

        gotoxy(44, 12);
        printf("������ ���� �о�޾��ּ���");

        setColor(7);
        _getch();
    }

    else if (choice == 2) {   // log.txt�� ��������� �α׺��⸦ �õ��ϴ� ���
        printf("!! Error !!");

        gotoxy(44, 12);
        printf("�α� ����� �����ϴ�!");

        setColor(7);
        _getch();
    }

    else if (choice == 10) {
        clearScreen();
        setColor(12);

        gotoxy(43, 9);
        printf("��������������������������������������������������������");
        for (int i = 1; i <= 5; i++) {
            gotoxy(43, 9 + i);
            printf("��                          ��");
        }
        gotoxy(43, 15);
        printf("��������������������������������������������������������");

        gotoxy(43, 10);
        printf("!! Game Over !!");

        gotoxy(44, 12);
        printf("     ������ �����մϴ�");

        setColor(7);

        gotoxy(0, 27);
    }
}