#include "main.h" 

void draw_UI();

int typingGame(int* result) {
    // 초기 점수는 0점, life는 3개
    int score = 0, life = 4;

    while (1) {
        // 미니게임 영역 초기화
        clearRegion(23, 1, 65, 24);
        // UI 출력
        draw_UI();
        
        // 문장이 이미 저장된 파일을 읽기 모드로 엶
        FILE* file = fopen("keyboard.txt", "r");

        if (file == NULL) {
            printf("파일을 열 수 없습니다.\n");
            return;
        }

        // 문장을 저장하는 함수
        char sentence[100][100] = { 0 };
        // 문자를 입력할 변수
        char input[100] = "";

        int i = 0;
        char line[100];

        // 파일의 끝까지 진행
        while (fgets(line, sizeof(line), file) != NULL) {
            // 제대로 된 문자열 비교를 위해 개행 문자 제거
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            strcpy(sentence[i], line); // line의 내용을 sentence[i]에 복사
            i++;
        }

        gotoxy(78, 3);
        printf("%d", score);
        gotoxy(78, 4);
        printf("%d", life);

        // 문장을 랜덤하게 출력하게 하기 위해 난수 초기화
        srand(time(NULL));

        // 난수값을 저장하는 변수
        int n = 0;
        n = rand() % i;

        // 파일 닫기
        fclose(file);

        // 정해진 문장을 0.1초마다 한글자씩 출력되게 함
        gotoxy(30, 5);
        slowPrint(100, sentence[n]);

        gotoxy(30, 8);
        printf("입력 : ");

        fgets(input, sizeof(input), stdin); // 공백을 포함한 한 줄 전체를 입력 받음

        // 입력받은 문장 개행 문자 제거
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // 입력받은 문장이 제시된 문장과 같다면 10점 추가
        if (strcmp(sentence[n], input) == 0) {
            score += 10;
        }
        // 아니라면 목숨 -1;
        else if (strcmp(sentence[n], input) != 0) {
            life--;
        }

        // life가 0이라면 게임을 종료하고 획득포인트 점수 * 100으로 보상
        if (life == 0) {
            gotoxy(50, 15);
            printf("Game Over");
            gotoxy(45, 16);
            printf("획득 포인트 : %d", score * 100);
            _getch();

            // 획득 포인트 반환
            return score * 100;
        }
    }
}

void draw_UI() {
    int x = 23, y = 1;

    setColor(3);

    gotoxy(x, y);
    printf("┏──────────────────────────────────────────────────────────────┓");
    gotoxy(x, y + 1);
    printf("│                                                              │");
    for (int i = 1; i <= 21; i++) {
        gotoxy(x, y + i);
        printf("│                                                              │");
    }
    gotoxy(x, y + 22);
    printf("┗──────────────────────────────────────────────────────────────┛");

    setColor(7);

    gotoxy(70, 3);
    printf("Score : ");
    gotoxy(70, 4);
    printf("life : ");
}