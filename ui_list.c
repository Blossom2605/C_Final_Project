#include "main.h"

void ui_list(int flag) {
	int x = 23, y = 1;

	setColor(3);

	gotoxy(x, y);
	printf("旨式式式式式式式式式式式式式式式式式式式式式式式式式式式旬");
	gotoxy(x, y + 1);
	printf("弛                           弛");
	gotoxy(x, y + 2);
	printf("曳式式式式式式式式式式式式式式式式式式式式式式式式式式式朽");
	for (int i = 1; i <= 19; i++) {
		gotoxy(x, y + i + 2);
		printf("弛                           弛");
	}
	gotoxy(x, y + 22);
	printf("曲式式式式式式式式式式式式式式式式式式式式式式式式式式式旭");

	setColor(7);

	if (flag == 0) {
		gotoxy(x + 6, y + 1);
		printf("啾   嬴   輿   晦");
	}

	if (flag == 1) {
		gotoxy(x + 6, y + 1);
		printf("詳   檜   輿   晦");
	}

	if (flag == 2) {
		gotoxy(x + 6, y + 1);
		printf("嘐   棲   啪   歜");
	}
}