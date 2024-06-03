#include "main.h"

void ui_log() {
	int x = 23, y = 1;
	
	setColor(3);

	gotoxy(x, y);
	printf("┏────────────────────────────────────────────────────────────────────┓");
	for (int i = 1; i <= 22; i++) {
		gotoxy(x, y + i);
		printf("│                                                                    │");
	}
	gotoxy(x, y + 23);
	printf("┗────────────────────────────────────────────────────────────────────┛");

	setColor(7);
	
	gotoxy(x, 0);
	printf("로그 보기");
}