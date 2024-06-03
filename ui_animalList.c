#include "main.h"

void ui_animalList(char* animalName, char* type, int* call) {
    int key;
    int x = 6, y = 4;
    int selected_menu = 0;
    int num_menu = 8;

    while(1) {
        clearRegion(x, y, 107, 23);

        setColor(3);

        gotoxy(x, y);
        printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
        for (int i = 1; i <= 21; i++) {
            gotoxy(x, y + i);
            printf("��                                                                                                         ��");
        }
        gotoxy(x, y+22);
        printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

        setColor(7);

        gotoxy(52, 3);
        printf("���� �о�ޱ�");

        show_animalList(selected_menu);

        key = _getch();

        //escŰ ������ ������
        if (key == 27) {
            *call = 0;
            break;
        }

        // ����Ű �Է� ó��
        else if (key == 224) {
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
            case 72:  // ���� ����Ű
                if (selected_menu >= 4)
                    selected_menu -= 4;
                break;
            case 80:  // �Ʒ��� ����Ű
                if (selected_menu < 4)
                    selected_menu += 4;
                break;
            }
        }
        // ���� Ű �Է� ó��
        else if (key == 13) {
            *call = 1;
            clearRegion(x+1, y+1, 105, 21);
            gotoxy(48, 8);
            printf("�̸�");
            gotoxy(54, 7);
            printf("��������������������������������������������");
            gotoxy(54, 8);
            printf("��                    ��");
            gotoxy(54, 9);
            printf("��������������������������������������������");
            showCursor();
            getInput(animalName, 10, 55, 8, 0);
            hideCursor();
 
            if (selected_menu == 0) {
                strcpy(type, "������");
            }
            else if (selected_menu == 1) {
                strcpy(type, "�����");
            }
            else if (selected_menu == 2) {
                strcpy(type, "������");
            }
            else if (selected_menu == 3) {
                strcpy(type, "�Ҵ�");
            }
            else if (selected_menu == 4) {
                strcpy(type, "�䳢");
            }
            else if (selected_menu == 5) {
                strcpy(type, "����");
            }
            else if (selected_menu == 6) {
                strcpy(type, "���");
            }
            else if (selected_menu == 7) {
                strcpy(type, "��");
            }
            break;
        }
    }
}