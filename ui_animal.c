#include "main.h"

void ui_animal(char* name, char* type, char* growth, char* personality, int* exp) {
    gotoxy(7, 10);
    printf("���� ����");
    setColor(3);
    gotoxy(2, 11);
    printf("����������������������������������������");
    gotoxy(2, 12);
    printf("��                  ��");
    gotoxy(2, 13);
    printf("����������������������������������������");
    for (int i = 1; i <= 9; i++) {
        gotoxy(2, 13 + i);
        printf("��                  ��");
    }
    gotoxy(2, 23);
    printf("����������������������������������������");
    setColor(7);

    gotoxy(9, 12);
    printf("%s", type);        //���� ����
    gotoxy(3, 15);
    printf(" �̸�  : %s", name); //���� �̸�
    gotoxy(3, 17);
    printf(" �ܰ�  : %s", growth);    //���� �ܰ�
    gotoxy(3, 19);
    printf(" EXP  : %d", *exp);  //����ġ
    gotoxy(3, 21);
    printf(" ����  : %s", personality); //����  
}