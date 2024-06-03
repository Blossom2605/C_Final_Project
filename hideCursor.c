#include "main.h"

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Ä¿¼­ ¼û±â±â
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}