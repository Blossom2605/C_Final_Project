#include "main.h"

void ui_list(int flag) {
	int x = 23, y = 1;

	setColor(3);

	gotoxy(x, y);
	printf("����������������������������������������������������������");
	gotoxy(x, y + 1);
	printf("��                           ��");
	gotoxy(x, y + 2);
	printf("����������������������������������������������������������");
	for (int i = 1; i <= 19; i++) {
		gotoxy(x, y + i + 2);
		printf("��                           ��");
	}
	gotoxy(x, y + 22);
	printf("����������������������������������������������������������");

	setColor(7);

	if (flag == 0) {
		gotoxy(x + 6, y + 1);
		printf("��   ��   ��   ��");
	}

	if (flag == 1) {
		gotoxy(x + 6, y + 1);
		printf("��   ��   ��   ��");
	}

	if (flag == 2) {
		gotoxy(x + 6, y + 1);
		printf("��   ��   ��   ��");
	}
}