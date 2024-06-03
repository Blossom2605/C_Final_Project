#include "main.h"

void setColor(int color) {
    /*
     0  : 검정
     1  : 어두운 파랑
     2  : 어두운 초록
     3  : 어두운 하늘
     4  : 어두운 빨강
     5  : 어두운 보라
     6  : 어두운 노랑
     7  : 회색
     8  : 어두운 회색
     9  : 파랑
     10 : 초록
     11 : 하늘
     12 : 빨강
     13 : 보라
     14 : 노랑
     15 : 하양
     */
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}