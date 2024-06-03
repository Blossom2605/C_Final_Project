#include "main.h"

void clearRegion(int x, int y, int width, int height) {
    COORD coord; // 콘솔 커서의 위치를 저장할 구조체
    DWORD written; // 쓰여진 문자 수를 저장할 변수
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 출력 핸들을 가져옴
    for (int i = 0; i < height; i++) { // 주어진 높이만큼 반복
        coord.X = x; // 현재 줄의 x 좌표 설정
        coord.Y = y + i; // 현재 줄의 y 좌표 설정

        // 현재 위치에서 주어진 너비만큼 공백 문자를 출력하여 해당 줄을 지움
        FillConsoleOutputCharacter(hConsole, ' ', width, coord, &written);

        // 현재 위치에서 주어진 너비만큼 문자 속성을 설정
        FillConsoleOutputAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, width, coord, &written);
    }
}