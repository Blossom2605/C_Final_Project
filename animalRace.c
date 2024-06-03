#include "main.h"

#define ENDPOINT 50
#define SIZE 6

void wait(int second); // second�ʸ�ŭ ����ϱ� ���� �Լ�
int select_animal(); // ������ �����ϴ� �Լ�
void drawline(); // ���� �ߴ� �Լ�
void run_animal(int* h1, int* h2, int* h3, int* h4, int* h5, int* h6); //������ �ӵ��� ���� �ִ� �Լ�
void draw_animal(int run, char animal);  // ������ �ӵ���ŭ ������ �����ϴ� �Լ�
void draw_start(); //�����ϱ� ���� �׸� �Լ� 
void draw_ui(int flag); // ui�� �׸��� �Լ�
void rank(int arr[], char* names[], int size);  // ��� ó���� ���� ���� �Լ�

int animalRace(int* result) {
    clearRegion(23, 1, 65, 24);
    int select_num;
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0;
    char mypick[10] = "";

    srand((unsigned)time(NULL)); // unsigned������ �ʱ�ȭ�ϸ� �ð� ���� �ʱ�ȭ����

    select_num = select_animal(); //������ ����

    // ���� ������ ������ 4��ȿ� ������� Ȯ���ϱ� ���� ���� ���� ���ڿ� ����
    if (select_num == 1) strcpy(mypick, "������");
    else if (select_num == 2) strcpy(mypick, "�����");
    else if (select_num == 3) strcpy(mypick, "������");
    else if (select_num == 4) strcpy(mypick, "�䳢");
    else if (select_num == 5) strcpy(mypick, "���");
    else if (select_num == 6) strcpy(mypick, "����");

    // 2�ʵڿ� ���
    draw_start();

    // �������̽� ����
    run_animal(&h1, &h2, &h3, &h4, &h5, &h6);

    // ���� ������ ���� �迭 ����
    int positions[SIZE] = { h1, h2, h3, h4, h5, h6 };
    char* animalNames[SIZE] = { "������", "�����", "������", "�䳢", "���", "����" };
    // �迭�� ����
    rank(positions, animalNames, SIZE);

    // ���� ���
    gotoxy(50, 18);
    printf("1��: %s, %d", animalNames[0], positions[0]);
    gotoxy(50, 19);
    printf("2��: %s, %d", animalNames[1], positions[1]);
    gotoxy(50, 20);
    printf("3��: %s, %d", animalNames[2], positions[2]);
    gotoxy(50, 21);
    printf("4��: %s, %d", animalNames[3], positions[4]);

    // ���� ������ ������ 1~4���̶�� �ش� ����� ���� ������ result�����ϰ� ������� ���
    if (strcmp(mypick,animalNames[0]) == 0) {
        gotoxy(48, 22);
        printf("��  1 �� ��");
        result = 3000;
    }
    else if (strcmp(mypick, animalNames[1]) == 0) {
        gotoxy(48, 22);
        printf("��  2 �� ��");
        result = 1500;
    }
    else if (strcmp(mypick, animalNames[2]) == 0) {
        gotoxy(48, 22);
        printf("��  3 �� ��");
        result = 1000;
    }
    else if (strcmp(mypick, animalNames[3]) == 0) {
        gotoxy(48, 22);
        printf("��  4 �� ��");
        result = 500;
    }
    else {
        gotoxy(50, 22);
        printf("��..");
        result = 0;
    }

    _getch();
    // �̴ϰ��� ���� �ʱ�ȭ
    clearRegion(23, 1, 65, 24);

    // ��� ���� ��ȯ
    return result;
}

void rank(int arr[], char* names[], int size) {
    // ���� ����
    int i, j, temp;
    char* tempName;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
}

void draw_ui(int flag){
    int x = 23, y = 1;

    setColor(3);

    gotoxy(x, y);
    printf("��������������������������������������������������������������������������������������������������������������������������������");
    gotoxy(x, y + 1);
    printf("��                                                              ��");
    for (int i = 1; i <= 21; i++) {
        gotoxy(x, y + i);
        printf("��                                                              ��");
    }
    gotoxy(x, y + 22);
    printf("��������������������������������������������������������������������������������������������������������������������������������");

    setColor(7);

    // �÷��� ���� 1�̶��
    if (flag == 1) {
        x = 26, y = 7;
        // �ݺ����� ���� �˸��� ��ġ�� ����(���̽� ����)�� ������ ������ END�� ���
        for (int i = 1; i <= 6; i++) {
            gotoxy(x, y + i);
            for (int j = 0; j < ENDPOINT; j++) {
                printf(" ");
            }
            printf(" END\n");
        }
    }
}

void wait(int second) {
    // �� ��ŭ ��ٸ��� ��
    clock_t endwait;

    endwait = clock() + second * CLOCKS_PER_SEC;

    while (clock() < endwait) {}
}

int select_animal() {
    int select_num;
    int flag = 0;

    while (1) {
        draw_ui(flag);
        gotoxy(50, 2);
        printf("�������̽�");

        gotoxy(34, 5);
        printf("������(�Ķ�) : 1");
        gotoxy(34, 6);
        printf("�����(�ʷ�) : 2");
        gotoxy(34, 7);
        printf("������(�ϴ�) : 3");
        gotoxy(34, 8);
        printf("�䳢(����)   : 4");
        gotoxy(34, 9);
        printf("���(����)   : 5");
        gotoxy(34, 10);
        printf("����(���) : 6");

        gotoxy(34, 12);
        printf("���� ��ȣ ���� : ");

        // ���� ��ȣ�� �Է¹���
        scanf("%d", &select_num);

        // �Էµ� ���� ��ȣ�� �ùٸ��� �Ǵ�
        if ((select_num > 0) && (select_num < 7)) break;

        printf("�߸� �����ϼ̽��ϴ�.");
    }

    // ���õ� ���� ��ȣ ��ȯ
    return select_num;
}

void run_animal(int* h1, int* h2, int* h3, int* h4, int* h5, int* h6) {
    int flag = 1;

    while (1) {
        draw_ui(flag);

        int x = 27, y = 7;

        // �� �������� �������� ����ؼ� ������
        *h1 += rand() % 7 + 1;

        *h2 += rand() % 7 + 1;

        *h3 += rand() % 7 + 1;

        *h4 += rand() % 7 + 1;

        *h5 += rand() % 7 + 1;

        *h6 += rand() % 7 + 1;

        gotoxy(x, y);
        drawline();

        // �������� ��ġ�� �� �� �ְ� x��ǥ�� ������ �߻��� ��ŭ ��� �Ű���
        gotoxy(x + *h1, y + 1);
        setColor(9);
        draw_animal(0, '>');

        setColor(10);
        gotoxy(x + *h2, y + 2);
        draw_animal(0, '>');

        setColor(11);
        gotoxy(x + *h3, y + 3);
        draw_animal(0, '>');

        setColor(12);
        gotoxy(x + *h4, y + 4);
        draw_animal(0, '>');

        setColor(13);
        gotoxy(x + *h5, y + 5);
        draw_animal(0, '>');

        setColor(14);
        gotoxy(x + *h6, y + 6);
        draw_animal(0, '>');

        setColor(7);
        gotoxy(x, y + 7);
        drawline();

        // ��������� ���� ������ ������ �����ϱ� ������ ���ڸ� �� �� �ֵ��� ���
        gotoxy(x, y + 8);
        printf("������ : %d | ����� : %d | ������ : %d", *h1, *h2, *h3);
        gotoxy(x, y + 9);
        printf("�䳢   : %d | ���   : %d | ���� : %d", *h4, *h5, *h6);

        gotoxy(x, y + 10);
        drawline();

        // 1�ʸ��� ������
        wait(1);

        // � �����̵� ������ ���� 50�̻��� �Ǹ� ���̽� ���� ���� ����
        if (*h1 >= 50) break;
        if (*h2 >= 50) break;
        if (*h3 >= 50) break;
        if (*h4 >= 50) break;
        if (*h5 >= 50) break;
        if (*h6 >= 50) break;
    }
}

void drawline() {
    // ���� �׸��� �Լ�
    printf("****************************************************\n");
}

void draw_animal(int run, char animal) {
    // ���޹��� ������ �����̹��� ���
    for (int i = 0; i < run; i++) {
        printf(" ");
    }

    printf("%c", animal);
}

void draw_start() {
    // ��߼����� ����ϴٰ� 2�ʵڿ� ����ϴ°��� �����ϴ� �Լ�
    int flag = 1;
    draw_ui(flag);

    int x = 27, y = 7;

    gotoxy(x, y);
    drawline();

    gotoxy(x, y + 1);
    setColor(9);
    draw_animal(0, '>');

    setColor(10);
    gotoxy(x, y + 2);
    draw_animal(0, '>');

    setColor(11);
    gotoxy(x, y + 3);
    draw_animal(0, '>');

    setColor(12);
    gotoxy(x, y + 4);
    draw_animal(0, '>');

    setColor(13);
    gotoxy(x, y + 5);
    draw_animal(0, '>');

    setColor(14);
    gotoxy(x, y + 6);
    draw_animal(0, '>');

    setColor(7);
    gotoxy(x, y + 7);
    drawline();

    wait(2);
}