#include "main.h"

#define ENDPOINT 50
#define SIZE 6

void wait(int second); // second초만큼 대기하기 위한 함수
int select_animal(); // 동물을 선택하는 함수
void drawline(); // 선을 긋는 함수
void run_animal(int* h1, int* h2, int* h3, int* h4, int* h5, int* h6); //동물의 속도를 각각 주는 함수
void draw_animal(int run, char animal);  // 동물의 속도만큼 앞으로 가게하는 함수
void draw_start(); //시작하기 전의 그림 함수 
void draw_ui(int flag); // ui를 그리는 함수
void rank(int arr[], char* names[], int size);  // 등수 처리를 위한 정렬 함수

int animalRace(int* result) {
    clearRegion(23, 1, 65, 24);
    int select_num;
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0;
    char mypick[10] = "";

    srand((unsigned)time(NULL)); // unsigned형으로 초기화하면 시간 난수 초기화가능

    select_num = select_animal(); //동물을 선택

    // 내가 선택한 동물이 4등안에 들었는지 확인하기 위해 값에 따른 문자열 복사
    if (select_num == 1) strcpy(mypick, "강아지");
    else if (select_num == 2) strcpy(mypick, "고양이");
    else if (select_num == 3) strcpy(mypick, "족제비");
    else if (select_num == 4) strcpy(mypick, "토끼");
    else if (select_num == 5) strcpy(mypick, "펭귄");
    else if (select_num == 6) strcpy(mypick, "돌고래");

    // 2초뒤에 출발
    draw_start();

    // 동물레이싱 진행
    run_animal(&h1, &h2, &h3, &h4, &h5, &h6);

    // 순위 산정을 위한 배열 저장
    int positions[SIZE] = { h1, h2, h3, h4, h5, h6 };
    char* animalNames[SIZE] = { "강아지", "고양이", "족제비", "토끼", "펭귄", "돌고래" };
    // 배열을 정렬
    rank(positions, animalNames, SIZE);

    // 순위 출력
    gotoxy(50, 18);
    printf("1위: %s, %d", animalNames[0], positions[0]);
    gotoxy(50, 19);
    printf("2위: %s, %d", animalNames[1], positions[1]);
    gotoxy(50, 20);
    printf("3위: %s, %d", animalNames[2], positions[2]);
    gotoxy(50, 21);
    printf("4위: %s, %d", animalNames[3], positions[4]);

    // 내가 선택한 동물이 1~4등이라면 해당 등수에 대한 보상을 result저장하고 몇등인지 출력
    if (strcmp(mypick,animalNames[0]) == 0) {
        gotoxy(48, 22);
        printf("★  1 등 ★");
        result = 3000;
    }
    else if (strcmp(mypick, animalNames[1]) == 0) {
        gotoxy(48, 22);
        printf("★  2 등 ★");
        result = 1500;
    }
    else if (strcmp(mypick, animalNames[2]) == 0) {
        gotoxy(48, 22);
        printf("★  3 등 ★");
        result = 1000;
    }
    else if (strcmp(mypick, animalNames[3]) == 0) {
        gotoxy(48, 22);
        printf("★  4 등 ★");
        result = 500;
    }
    else {
        gotoxy(50, 22);
        printf("꽝..");
        result = 0;
    }

    _getch();
    // 미니게임 영역 초기화
    clearRegion(23, 1, 65, 24);

    // 결과 보상 반환
    return result;
}

void rank(int arr[], char* names[], int size) {
    // 버블 정렬
    int i, j, temp;
    char* tempName;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
}

void draw_ui(int flag){
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

    // 플래그 값이 1이라면
    if (flag == 1) {
        x = 26, y = 7;
        // 반복문을 통해 알맞은 위치에 공백(레이스 길이)과 끝나는 지점에 END를 출력
        for (int i = 1; i <= 6; i++) {
            gotoxy(x, y + i);
            for (int j = 0; j < ENDPOINT; j++) {
                printf(" ");
            }
            printf(" END\n");
        }
    }
}

void wait(int second) {
    // 초 만큼 기다리게 함
    clock_t endwait;

    endwait = clock() + second * CLOCKS_PER_SEC;

    while (clock() < endwait) {}
}

int select_animal() {
    int select_num;
    int flag = 0;

    while (1) {
        draw_ui(flag);
        gotoxy(50, 2);
        printf("동물레이싱");

        gotoxy(34, 5);
        printf("강아지(파랑) : 1");
        gotoxy(34, 6);
        printf("고양이(초록) : 2");
        gotoxy(34, 7);
        printf("족제비(하늘) : 3");
        gotoxy(34, 8);
        printf("토끼(빨강)   : 4");
        gotoxy(34, 9);
        printf("펭귄(보라)   : 5");
        gotoxy(34, 10);
        printf("돌고래(노랑) : 6");

        gotoxy(34, 12);
        printf("동물 번호 선택 : ");

        // 동물 번호를 입력받음
        scanf("%d", &select_num);

        // 입력된 동물 번호가 올바른지 판단
        if ((select_num > 0) && (select_num < 7)) break;

        printf("잘못 선택하셨습니다.");
    }

    // 선택된 동물 번호 반환
    return select_num;
}

void run_animal(int* h1, int* h2, int* h3, int* h4, int* h5, int* h6) {
    int flag = 1;

    while (1) {
        draw_ui(flag);

        int x = 27, y = 7;

        // 각 동물마다 랜덤값을 계속해서 더해줌
        *h1 += rand() % 7 + 1;

        *h2 += rand() % 7 + 1;

        *h3 += rand() % 7 + 1;

        *h4 += rand() % 7 + 1;

        *h5 += rand() % 7 + 1;

        *h6 += rand() % 7 + 1;

        gotoxy(x, y);
        drawline();

        // 동물들의 위치를 알 수 있게 x좌표를 난수가 발생된 만큼 계속 옮겨줌
        gotoxy(x + *h1, y + 1);
        setColor(9);
        draw_animal(0, '>');

        setColor(10);
        gotoxy(x + *h2, y + 2);
        draw_animal(0, '>');

        setColor(11);
        gotoxy(x + *h3, y + 3);
        draw_animal(0, '>');

        setColor(12);
        gotoxy(x + *h4, y + 4);
        draw_animal(0, '>');

        setColor(13);
        gotoxy(x + *h5, y + 5);
        draw_animal(0, '>');

        setColor(14);
        gotoxy(x + *h6, y + 6);
        draw_animal(0, '>');

        setColor(7);
        gotoxy(x, y + 7);
        drawline();

        // 결과적으로 최종 값으로 순위를 산정하기 때문에 숫자를 볼 수 있도록 출력
        gotoxy(x, y + 8);
        printf("강아지 : %d | 고양이 : %d | 족제비 : %d", *h1, *h2, *h3);
        gotoxy(x, y + 9);
        printf("토끼   : %d | 펭귄   : %d | 돌고래 : %d", *h4, *h5, *h6);

        gotoxy(x, y + 10);
        drawline();

        // 1초마다 움직임
        wait(1);

        // 어떤 동물이든 누적된 값이 50이상이 되면 레이싱 게임 루프 종료
        if (*h1 >= 50) break;
        if (*h2 >= 50) break;
        if (*h3 >= 50) break;
        if (*h4 >= 50) break;
        if (*h5 >= 50) break;
        if (*h6 >= 50) break;
    }
}

void drawline() {
    // 라인 그리는 함수
    printf("****************************************************\n");
}

void draw_animal(int run, char animal) {
    // 전달받은 값으로 동물이미지 출력
    for (int i = 0; i < run; i++) {
        printf(" ");
    }

    printf("%c", animal);
}

void draw_start() {
    // 출발선에서 대기하다가 2초뒤에 출발하는것을 연출하는 함수
    int flag = 1;
    draw_ui(flag);

    int x = 27, y = 7;

    gotoxy(x, y);
    drawline();

    gotoxy(x, y + 1);
    setColor(9);
    draw_animal(0, '>');

    setColor(10);
    gotoxy(x, y + 2);
    draw_animal(0, '>');

    setColor(11);
    gotoxy(x, y + 3);
    draw_animal(0, '>');

    setColor(12);
    gotoxy(x, y + 4);
    draw_animal(0, '>');

    setColor(13);
    gotoxy(x, y + 5);
    draw_animal(0, '>');

    setColor(14);
    gotoxy(x, y + 6);
    draw_animal(0, '>');

    setColor(7);
    gotoxy(x, y + 7);
    drawline();

    wait(2);
}