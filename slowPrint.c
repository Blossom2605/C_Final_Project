#include "main.h"

void slowPrint(unsigned long speed, const char* s){
	int i = 0;

	// ������ ������ �и��� �����θ��� �� ���ھ� �����
	while (s[i] != 0) {
		printf("%c", s[i++]);
		fflush(stdout);
		Sleep(speed);
	}
}