#include "main.h"

bool answer(int flag) {
    int key;
    int selected_menu = 0;
    int num_menu = 2;

    int x = 23, y = 1;

    while (1) {
        setColor(3);

        gotoxy(43, 9);
        printf("������������������������������������������������������������������");
        for (int i = 1; i <= 6; i++) {
            gotoxy(43, 9 + i);
            printf("��                               ��");
        }
        gotoxy(43, 16);
        printf("������������������������������������������������������������������");

        setColor(7);

        // �÷��� ���� ���� ��� ��� ������ �޶���
        gotoxy(43, 10);
        if (flag == 0) {
            printf("!! ���� �ش� ���̸� �Ͻǰǰ���?");
            if (selected_menu == 0) {
                setColor(14);
                gotoxy(53, 13);
                printf("��");
                setColor(7);
            }
            else {
                gotoxy(53, 13);
                printf("��");
            }

            if (selected_menu == 1) {
                setColor(14);
                gotoxy(62, 13);
                printf("�ƴϿ�");
                setColor(7);
            }
            else {
                gotoxy(62, 13);
                printf("�ƴϿ�");
            }

        }

        if (flag == 1) {
            printf("!! ���� �ش� ���̸� ���ϱ��?");
            if (selected_menu == 0) {
                setColor(14);
                gotoxy(53, 13);
                printf("��");
                setColor(7);
            }
            else {
                gotoxy(53, 13);
                printf("��");
            }

            if (selected_menu == 1) {
                setColor(14);
                gotoxy(62, 13);
                printf("�ƴϿ�");
                setColor(7);
            }
            else {
                gotoxy(62, 13);
                printf("�ƴϿ�");
            }
        }

        // ���� ����
        //if (flag == 2) {
        //    printf("���̴ϰ����� �����մϴ٢�");
        //    if (selected_menu == 0) {
        //        setColor(14);
        //        gotoxy(53, 13);
        //        printf("��");
        //        setColor(7);
        //    }
        //    else {
        //        gotoxy(53, 13);
        //        printf("��");
        //    }

        //    if (selected_menu == 1) {
        //        setColor(14);
        //        gotoxy(62, 13);
        //        printf("�ƴϿ�");
        //        setColor(7);
        //    }
        //    else {
        //        gotoxy(62, 13);
        //        printf("�ƴϿ�");
        //    }
        //}

        // �÷��� ���� 10�� ���޵Ǿ��ٸ� ����Ʈ �����ϴٰ� ����ϰ� ���ư�
        gotoxy(51, 12);
        if (flag == 10) {
            printf("����Ʈ�� �����մϴ�");
        }

        key = _getch();

        if (key == 224) {
            key = _getch();
            switch (key) {
            case 75:  // ���� ����Ű
                if (selected_menu > 0)
                    selected_menu--;
                break;
            case 77:  // ������ ����Ű
                if (selected_menu < num_menu - 1)
                    selected_menu++;
                break;
            }
        }

        // ��(selected_menu���� 0)��� true�� ��ȯ / �ƴ϶�� false�� ��ȯ
        else if (key == 13) {
            clearRegion(43, 9, 33, 8);
            if (selected_menu == 0) {
                return true;
            }

            if (selected_menu == 1) {
                return false;
            }
        }
    }
}