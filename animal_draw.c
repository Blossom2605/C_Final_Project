#include "main.h"

void animal_draw(char* filename, char* grow) {
    // ���޹��� ���ڰ��� ���ļ� ��������_�������.txt ���ڿ��� ����
    char files[100];
    strcpy(files, filename);
    strcat(files, "_");
    strcat(files, grow);
    strcat(files, ".txt");

    // files���� ������ �б� ���� ��
    FILE* file = fopen(files, "r");

    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // ������ ������ ���
    int i = 1;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        gotoxy(58, 0 + i);
        printf(line);
        i++;
    }

    //������ ����
    fclose(file);
}