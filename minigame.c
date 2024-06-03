#include "main.h"

void minigame(int* point, int flag, int* call) {
    int key;
    int selected_menu = 0;
    int num_menu = 2;
    int result = 0, get_point = 0;
    
    while (1) {
        int x = 23, y = 1;
        
        // �̴ϰ��� UI���� �ʱ�ȭ
        clearRegion(x, y, 29, 23);

        // �÷��� ���� 2�� UI ���
        ui_list(2);

        x = 26, y = 6;

        // ���õǾ��ִ� �޴� ����
        gotoxy(x, y);
        if (selected_menu == 0) {
            setColor(14);
            printf("�������̽�");
            gotoxy(x, y + 1);
            printf("����");
            gotoxy(x, y + 2);
            printf("1�� 3000, 2�� 1500");
            gotoxy(x, y + 3);
            printf("3�� 500, 4�� 100 ����Ʈ");

            setColor(7);
        }
        else {
            printf("�������̽�");
        }

        gotoxy(x, y + 5);
        if (selected_menu == 1) {
            setColor(14);
            printf("Ÿ�ڰ���");
            gotoxy(x, y + 6);
            printf("����");
            gotoxy(x, y + 7);
            printf("���� * 100 ����Ʈ");
            setColor(7);
        }
        else {
            printf("Ÿ�ڰ���");
        }        

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
            case 72:  // ���� ����Ű
                selected_menu--;
                if (selected_menu < 0) selected_menu = num_menu - 1;
                break;
            case 80:  // �Ʒ��� ����Ű
                selected_menu++;
                if (selected_menu >= num_menu) selected_menu = 0;
                break;
            }
        }

        // ����Ű ó��
        else if (key == 13) {
            // ���õ� �޴����� 0�̶��
            if (selected_menu == 0) {
                // �������̽� ���� ����
                get_point = animalRace(result);

                // ȹ�� ����Ʈ�� 0�� �ʰ��ϸ� ���� �α� �ۼ�
                if (get_point > 0) {
                    log("�������̽�", "", get_point, 5);
                }
                // ȹ�� ����Ʈ�� ������ ���� �α� �ۼ�
                else {
                    log("", "", 0, 6);
                }
                
                // ȹ�� ����Ʈ�� point���� ���ϰ� ���� ����
                *point += get_point;
                break;
            }

            // ���õ� �޴����� 1�̶��
            else if (selected_menu == 1) {
                // Ÿ���� ���� ����
                get_point = typingGame(result);
                
                //Ÿ���� ���� ���� �α� �ۼ�
                log("", "", get_point, 4);

                // ȹ�� ����Ʈ�� point���� ���ϰ� ���� ����
                *point += get_point;
                break;
            }
        }
    }
}