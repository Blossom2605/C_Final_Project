#include "main.h"

void setColor(int color) {
    /*
     0  : ����
     1  : ��ο� �Ķ�
     2  : ��ο� �ʷ�
     3  : ��ο� �ϴ�
     4  : ��ο� ����
     5  : ��ο� ����
     6  : ��ο� ���
     7  : ȸ��
     8  : ��ο� ȸ��
     9  : �Ķ�
     10 : �ʷ�
     11 : �ϴ�
     12 : ����
     13 : ����
     14 : ���
     15 : �Ͼ�
     */
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}