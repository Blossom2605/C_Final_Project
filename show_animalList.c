#include "main.h"

void show_animalList(int selected_menu) {
    // animal_list.txt�� �б� ���� ��
    FILE* file = fopen("animal_list.txt", "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // ������ ������ �����ϰ� ����ϴ� ����
    char line[100];
    int index = 0;

    // line���� NULL�� �ɶ����� ����
    while (fgets(line, sizeof(line), file) != NULL) {
        // ����ü�� ������ ��� ������
        char type[20];
        int max_exp;
        char temperament[20];

        if (sscanf(line, "%s %d %s", type, &max_exp, temperament) == 3) {
            // x,y ��ǥ�� 
            // �ڽ� ui�� 4���� �Ѿ�� y��ǥ�� �ٲ�, x��ǥ�� index�� 4�� �������� 26�� ���ؼ� ��ǥ�� ����(26ĭ���� ��ġ)
            int x = (index % 4) * 26;
            int y = (index < 4) ? 8 : 16;

            setColor(3);

            gotoxy(x + 8, y);
            printf("������������������������������������������������");
            for (int i = 1; i <= 5; i++) {
                gotoxy(x + 8, y + i);
                printf("��                      ��");
            }
            gotoxy(x + 8, y+6);
            printf("������������������������������������������������");

            setColor(7);

           // ���� ��ġ ����� ���� ��ǥ�� ������
            x = (index % 4) * 26;
            y = (index < 4) ? 10 : 18;

            // �о簡�� ���� ���
            gotoxy(x + 10, y);
            printf("��   ��    : %s", type);
            gotoxy(x + 10, y + 1);
            printf("��   ��    : %s", temperament);
            gotoxy(x + 10, y + 2);
            printf("�ִ� ����ġ: %d", max_exp);

            // �ε��� ��ȭ�� ���� �ε����� ����
            index++;
        }
    }

    // ���� �ݱ�
    fclose(file);

    // ���� Ű���� ���� ���õǾ��ִ� �޴� ����
    gotoxy(10, 10);
    if (selected_menu == 0) {
        setColor(14);
        printf("��   ��    : ������");
        setColor(7);
    }
    else printf("��   ��    : ������");

    gotoxy(36, 10);
    if (selected_menu == 1) {
        setColor(14);
        printf("��   ��    : �����");
        setColor(7);
    }
    else printf("��   ��    : �����");

    gotoxy(62, 10);
    if (selected_menu == 2) {
        setColor(14);
        printf("��   ��    : ������");
        setColor(7);
    }
    else printf("��   ��    : ������");

    gotoxy(88, 10);
    if (selected_menu == 3) {
        setColor(14);
        printf("��   ��    : �Ҵ�");
        setColor(7);
    }
    else printf("��   ��    : �Ҵ�");

    gotoxy(10, 18);
    if (selected_menu == 4) {
        setColor(14);
        printf("��   ��    : �䳢");
        setColor(7);
    }
    else printf("��   ��    : �䳢");

    gotoxy(36, 18);
    if (selected_menu == 5) {
        setColor(14);
        printf("��   ��    : ����");
        setColor(7);
    }
    else printf("��   ��    : ����");

    gotoxy(62, 18);
    if (selected_menu == 6) {
        setColor(14);
        printf("��   ��    : ���");
        setColor(7);
    }
    else printf("��   ��    : ���");

    gotoxy(88, 18);
    if (selected_menu == 7) {
        setColor(14);
        printf("��   ��    : ��");
        setColor(7);
    }
    else printf("��   ��    : ��");
}