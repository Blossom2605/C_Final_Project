#include "main.h"

void ui_saveAnimal(Animal* myAnimal) {
    gotoxy(48, 3);
    printf("%s��(��) �о�޾ҽ��ϴ�!", myAnimal->type);

    setColor(3);

    gotoxy(48, 12);
    printf("��������������������������������������������������������");
    for (int i = 1; i <= 5; i++) {
        gotoxy(48, 12 + i);
        printf("��                          ��");
    }
    gotoxy(48, 18);
    printf("��������������������������������������������������������");
    
    setColor(7);

    gotoxy(49, 13);
    printf("�о�����");
    gotoxy(49, 15);
    printf("�̸� : %s", myAnimal->nickname);
    gotoxy(49, 17);
    printf("���� : %s", myAnimal->temperament);

    gotoxy(48, 22);
    printf("�ƹ�Ű�� �����ּ���.");
}