#include "main.h"

void clearRegion(int x, int y, int width, int height) {
    COORD coord; // �ܼ� Ŀ���� ��ġ�� ������ ����ü
    DWORD written; // ������ ���� ���� ������ ����
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� ��� �ڵ��� ������
    for (int i = 0; i < height; i++) { // �־��� ���̸�ŭ �ݺ�
        coord.X = x; // ���� ���� x ��ǥ ����
        coord.Y = y + i; // ���� ���� y ��ǥ ����

        // ���� ��ġ���� �־��� �ʺ�ŭ ���� ���ڸ� ����Ͽ� �ش� ���� ����
        FillConsoleOutputCharacter(hConsole, ' ', width, coord, &written);

        // ���� ��ġ���� �־��� �ʺ�ŭ ���� �Ӽ��� ����
        FillConsoleOutputAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, width, coord, &written);
    }
}