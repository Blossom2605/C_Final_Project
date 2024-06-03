#include "main.h"

void slowPrint(unsigned long speed, const char* s){
	int i = 0;

	// 문장의 끝까지 밀리초 단위로마다 한 글자씩 출력함
	while (s[i] != 0) {
		printf("%c", s[i++]);
		fflush(stdout);
		Sleep(speed);
	}
}