#include "main.h"

void care_animal(char* animalType, int* point, int* use_point, char* growth, int* exp, int* get_exp, int flag, int* call) {
    // ������
    int key;
    int x = 23, y = 1;
    int selected_menu = 0;
    int num_menu = 4;
    *get_exp = 0;
    *use_point = 0;

    // ���ѷ���
    while (1) {
        // ui������ �ʱ�ȭ
        clearRegion(x, y, 29, 23);

        // ui�� flag���� ���� �׸�
        ui_list(flag);

        // flag�� 0�̶�� ����ֱ� ���� �޴��� 1�̶�� �����ֱ� ���� �޴��� ���
        if (flag == 0) {
            show_care_menu(selected_menu, 0);
        }
        else if (flag == 1) {
            show_care_menu(selected_menu, 1);
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

        // ����Ű�� �Է¹�����
        else if (key == 13) {
            // ���� �����Ѱ� �´��� ����� ���� bool ����
            bool ans;
            // �ٽ� �ѹ� ���� �Լ��� flag�� ���� ���� ui�� ����ϰ� ����� ��ȯ
            ans = answer(flag);

            // ans�� 1�̶��
            if (ans) {
                // �÷��� ���� 0�̶��
                if (flag == 0) {
                    // ���õ� �޴��� ���� ����� ����Ʈ, ȹ�� ����ġ�� ����
                    if (selected_menu == 0) {
                        *use_point = 0;
                        *get_exp = rand() % 20 + 1;
                    }

                    else if (selected_menu == 1) {
                        if (*point < 100) {
                            answer(10);
                        }
                        else {
                            int selec = rand() % 2;
                            *use_point = -100;

                            if (selec == 0) *get_exp = -100;
                            else if (selec == 1) *get_exp = 100;
                        }
                    }

                    else if (selected_menu == 2) {
                        if (*point < 500) {
                            answer(10);
                        }
                        else {
                            *use_point = -500;
                            *get_exp = rand() % 101 + 200;
                        }
                    }

                    else if (selected_menu == 3) {
                        if (*point < 1000) {
                            answer(10);
                        }
                        else {
                            *use_point = -1000;
                            *get_exp = rand() % 501 + 500;
                        }
                    }
                }

                // �÷��� ���� 1�̶��
                if (flag == 1) {
                    if (selected_menu == 0) {
                        if (*point < 10) {
                            answer(10);
                        }
                        else {
                            *use_point = -10;
                            *get_exp = 20;
                        }
                    }

                    else if (selected_menu == 1) {
                        if (*point < 500) {
                            answer(10);
                        }

                        else {
                            *use_point = -500;
                            *get_exp = rand() % 101 + 200;
                        }
                    }

                    else if (selected_menu == 2) {
                        if (*point < 600) {
                            answer(10);
                        }

                        else {
                            *use_point = -600;
                            *get_exp = rand() % 201 + 200;
                        }
                    }

                    else if (selected_menu == 3) {
                        if (*point < 1500) {
                            answer(10);
                        }

                        else {
                            *use_point = -1500;
                            *get_exp = rand() % 501 + 1000;
                        }
                    }
                }

                // ȹ�� ����ġ�� 0�� �ʰ��ϰų� ���� ����Ʈ�� 0 �̸��̶��
                if (*get_exp > 0 || *use_point < 0) {
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

                    // exp�� ȹ�� ����ġ�� �߰�, point�� ��� ����Ʈ��ŭ ����
                    *exp += *get_exp;
                    *point -= ~(*use_point) + 1;

                    // �������Ʈ�� ȹ�� ���� ����ġ ���(����Ʈ�� ��ȣ ���� ���� +1�� �ؼ� -��ȣ�� ��µ��� �ʰ���
                    gotoxy(49, 12);
                    printf("��� ����Ʈ : %d", ~(*use_point) + 1);
                    gotoxy(49, 13);
                    printf("ȹ�� ���� ����ġ : %d", *get_exp);
                    _getch();
                }
                
                // ���� ����
                break;
            }

            // 0�� ��ȯ�Ǹ� answer UI ������ ������ UI�� �ٽ� �׸��� ��
            else {
                animal_draw(animalType, growth);
                if (flag == 0) ui_action(1);
                else if (flag == 1) ui_action(2);
            }
        }
    }
}