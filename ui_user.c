#include "main.h";

void ui_user(char* nickname, char* classes, int exp, int point) {
    int startX = 89;
    int startY = 0;

    gotoxy(startX, startY);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    gotoxy(startX, startY + 1);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    gotoxy(startX, startY + 2);
    printf("@@@@@@@@@@@@@@.@ .@@@@@@@@@@@@\n");
    gotoxy(startX, startY + 3);
    printf("@@@@@@@@@@@@.,,.., .@@@@@@@@@@\n");
    gotoxy(startX, startY + 4);
    printf("@@@@@@@@@@@@-.    ...@@@@@@@@@\n");
    gotoxy(startX, startY + 5);
    printf("@@@@@@@@@@@@ . ...   .@@@@@@@@\n");
    gotoxy(startX, startY + 6);
    printf("@@@@@@@@@@, .....,.   .@@@@@@@\n");
    gotoxy(startX, startY + 7);
    printf("@@@@@@@@@@ .. .   ..  ..@@@@@@\n");
    gotoxy(startX, startY + 8);
    printf("@@@@@@@@@@...   ~. ...  @@@@@@\n");
    gotoxy(startX, startY + 9);
    printf("@@@@@@@@@@@..~  ,*......@@@@@@\n");
    gotoxy(startX, startY + 10);
    printf("@@@@@@@@@@@@@:, .= . ...@@@@@@\n");
    gotoxy(startX, startY + 11);
    printf("@@@@@@@@@@@@@-~     .. ..@@@@@\n");
    gotoxy(startX, startY + 12);
    printf("@@@@@@@@@@@@@@     ... ...@@@@\n");
    gotoxy(startX, startY + 13);
    printf("@@@@@@@@@@@@@@.   ,  .... @@@@\n");
    gotoxy(startX, startY + 14);
    printf("@@@@@@@@@@@@@@ .. . .... ..@@@\n");
    gotoxy(startX, startY + 15);
    printf("@@@@ .@@@@@@-~,.... ....  .@@@\n");
    gotoxy(startX, startY + 16);
    printf("  ., @@@@@@~,.,.  . .---. .@@@\n");
    gotoxy(startX, startY + 17);
    printf("...  @@@@@@-,,.   ..-,..,..@@@\n");
    gotoxy(startX, startY + 18);
    printf("@    @@@@@@,,.... ....~.-..@@@\n");
    gotoxy(startX, startY + 19);
    printf("@@ .  .@@@@-,.... ..,.---..@@@\n");
    gotoxy(startX, startY + 20);
    printf("@@@@   .@@.,....,.,,----,,,,@@\n");
    gotoxy(startX, startY + 21);
    printf("@@@@@,   . ,-...,,,-.--,,--,@@\n");
    gotoxy(startX, startY + 22);
    printf("@@@@@@.     ~...,.-, @ .  .-@@\n");
    gotoxy(startX, startY + 23);
    printf("@@@@@@@.   .@..., .,@@@.   @@@\n");
    gotoxy(startX, startY + 24);
    printf("@@@@@@@@.. @@,.....   @@   .@@\n");
    gotoxy(startX, startY + 25);
    printf("@@@@@@@@@@@@@....,.   @.   .@@\n");
    gotoxy(startX, startY + 26);
    printf("@@@@@@@@@@@@@    .        .@@@\n");
    gotoxy(startX, startY + 27);
    printf("@@@@@@@@@@@@@.    ...   ..@@@@\n");
    gotoxy(startX, startY + 28);
    printf("@@@@@@@@@@@ ........ .,@@@@@@@\n");

    gotoxy(6, 0);
    printf("ĳ���� ����");
    setColor(3);
    gotoxy(2, 1);
    printf("����������������������������������������");
    gotoxy(2, 2);
    printf("��                  ��");
    gotoxy(2, 3);
    printf("����������������������������������������");
    for (int i = 1; i <= 5; i++) {
        gotoxy(2, 3 + i);
        printf("��                  ��");
    }
    gotoxy(2, 9);
    printf("����������������������������������������");
    setColor(7);

    gotoxy(3, 2);
    printf("%s", nickname);        //�г���
    gotoxy(3, 4);
    printf("���  : %s", classes); //���
    gotoxy(3, 6);
    printf("EXP   : %d", exp);    //����ġ ��������ġ���� �������� ���������غ���(����ġ�� %ǥ�ý� 5�ڸ����� ǥ�Ⱑ��)
    gotoxy(3, 8);
    printf("POINT : %d", point);  //����Ʈ

    // ��޺��� �г��Ӱ� ��޿� ����ȿ��
    if (strcmp(classes, "����") == 0) {
        setColor(12);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("��");
        setColor(7);
        gotoxy(12, 4);
        printf(" �� �� ");
        setColor(12);
        gotoxy(19, 4);
        printf("��");
        setColor(7);
    }

    else if (strcmp(classes, "����") == 0) {
        setColor(13);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("��");
        setColor(7);
        gotoxy(12, 4);
        printf(" �� �� ");
        setColor(13);
        gotoxy(19, 4);
        printf("��");
        setColor(7);
    }

    else if (strcmp(classes, "����") == 0) {
        setColor(10);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("��");
        setColor(7);
        gotoxy(12, 4);
        printf(" �� �� ");
        setColor(10);
        gotoxy(19, 4);
        printf("��");
        setColor(7);
    }

    else if (strcmp(classes, "����") == 0) {
        setColor(8);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("��");
        setColor(7);
        gotoxy(12, 4);
        printf(" �� �� ");
        setColor(8);
        gotoxy(19, 4);
        printf("��");
        setColor(7);
    }

    else if (strcmp(classes, "����") == 0) {
        setColor(6);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("��");
        setColor(7);
        gotoxy(12, 4);
        printf(" �� �� ");
        setColor(6);
        gotoxy(18, 4);
        printf("��");
        setColor(7);
    }

    else if (strcmp(classes, "���") == 0) {
        setColor(9);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("��");
        setColor(7);
        gotoxy(12, 4);
        printf(" ��  �� ");
        setColor(9);
        gotoxy(19, 4);
        printf("��");
        setColor(7);
    }
}