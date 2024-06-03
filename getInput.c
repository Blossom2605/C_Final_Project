#include "main.h"

void getInput(char* inputBuffer, int bufferSize, int x, int y, int password) {
    gotoxy(x, y);

    int charCount = 0;
    char ch;

    while (1) {
        ch = _getch(); // getch()로 사용자의 입력을 하나씩 읽음

        if (ch == '\r') { // Enter 키를 누르면 입력 종료
            inputBuffer[charCount] = '\0';
            break;
        }
        else if (ch == '\b') { // Backspace 키 처리
            if (charCount > 0) {
                charCount--;
                gotoxy(x + charCount, y);
                printf(" ");
                gotoxy(x + charCount, y);
            }
        }
        else if (charCount < bufferSize) { // 입력 문자 수가 버퍼 크기보다 작을 때
            inputBuffer[charCount] = ch;
            if (password) {
                putchar('*'); // 패스워드는 '*'로 마스킹 처리
            }
            else {
                putchar(ch);
            }
            charCount++;
        }
    }
}