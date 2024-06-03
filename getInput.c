#include "main.h"

void getInput(char* inputBuffer, int bufferSize, int x, int y, int password) {
    gotoxy(x, y);

    int charCount = 0;
    char ch;

    while (1) {
        ch = _getch(); // getch()�� ������� �Է��� �ϳ��� ����

        if (ch == '\r') { // Enter Ű�� ������ �Է� ����
            inputBuffer[charCount] = '\0';
            break;
        }
        else if (ch == '\b') { // Backspace Ű ó��
            if (charCount > 0) {
                charCount--;
                gotoxy(x + charCount, y);
                printf(" ");
                gotoxy(x + charCount, y);
            }
        }
        else if (charCount < bufferSize) { // �Է� ���� ���� ���� ũ�⺸�� ���� ��
            inputBuffer[charCount] = ch;
            if (password) {
                putchar('*'); // �н������ '*'�� ����ŷ ó��
            }
            else {
                putchar(ch);
            }
            charCount++;
        }
    }
}