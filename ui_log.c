#include "main.h"

void ui_log() {
	int x = 23, y = 1;
	
	setColor(3);

	gotoxy(x, y);
	printf("旨式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式旬");
	for (int i = 1; i <= 22; i++) {
		gotoxy(x, y + i);
		printf("弛                                                                    弛");
	}
	gotoxy(x, y + 23);
	printf("曲式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式旭");

	setColor(7);
	
	gotoxy(x, 0);
	printf("煎斜 爾晦");
}