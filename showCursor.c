#include "main.h"

void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true; // Ŀ�� �ѱ�
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}