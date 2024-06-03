#include "main.h" 

void draw_UI();

int typingGame(int* result) {
    // �ʱ� ������ 0��, life�� 3��
    int score = 0, life = 4;

    while (1) {
        // �̴ϰ��� ���� �ʱ�ȭ
        clearRegion(23, 1, 65, 24);
        // UI ���
        draw_UI();
        
        // ������ �̹� ����� ������ �б� ���� ��
        FILE* file = fopen("keyboard.txt", "r");

        if (file == NULL) {
            printf("������ �� �� �����ϴ�.\n");
            return;
        }

        // ������ �����ϴ� �Լ�
        char sentence[100][100] = { 0 };
        // ���ڸ� �Է��� ����
        char input[100] = "";

        int i = 0;
        char line[100];

        // ������ ������ ����
        while (fgets(line, sizeof(line), file) != NULL) {
            // ����� �� ���ڿ� �񱳸� ���� ���� ���� ����
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            strcpy(sentence[i], line); // line�� ������ sentence[i]�� ����
            i++;
        }

        gotoxy(78, 3);
        printf("%d", score);
        gotoxy(78, 4);
        printf("%d", life);

        // ������ �����ϰ� ����ϰ� �ϱ� ���� ���� �ʱ�ȭ
        srand(time(NULL));

        // �������� �����ϴ� ����
        int n = 0;
        n = rand() % i;

        // ���� �ݱ�
        fclose(file);

        // ������ ������ 0.1�ʸ��� �ѱ��ھ� ��µǰ� ��
        gotoxy(30, 5);
        slowPrint(100, sentence[n]);

        gotoxy(30, 8);
        printf("�Է� : ");

        fgets(input, sizeof(input), stdin); // ������ ������ �� �� ��ü�� �Է� ����

        // �Է¹��� ���� ���� ���� ����
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // �Է¹��� ������ ���õ� ����� ���ٸ� 10�� �߰�
        if (strcmp(sentence[n], input) == 0) {
            score += 10;
        }
        // �ƴ϶�� ��� -1;
        else if (strcmp(sentence[n], input) != 0) {
            life--;
        }

        // life�� 0�̶�� ������ �����ϰ� ȹ������Ʈ ���� * 100���� ����
        if (life == 0) {
            gotoxy(50, 15);
            printf("Game Over");
            gotoxy(45, 16);
            printf("ȹ�� ����Ʈ : %d", score * 100);
            _getch();

            // ȹ�� ����Ʈ ��ȯ
            return score * 100;
        }
    }
}

void draw_UI() {
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

    gotoxy(70, 3);
    printf("Score : ");
    gotoxy(70, 4);
    printf("life : ");
}