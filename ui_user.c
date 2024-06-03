#include "main.h";

void ui_user(char* nickname, char* classes, int exp, int point) {
    int startX = 89;
    int startY = 0;

    gotoxy(startX, startY);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    gotoxy(startX, startY + 1);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    gotoxy(startX, startY + 2);
    printf("@@@@@@@@@@@@@@.@ .@@@@@@@@@@@@\n");
    gotoxy(startX, startY + 3);
    printf("@@@@@@@@@@@@.,,.., .@@@@@@@@@@\n");
    gotoxy(startX, startY + 4);
    printf("@@@@@@@@@@@@-.    ...@@@@@@@@@\n");
    gotoxy(startX, startY + 5);
    printf("@@@@@@@@@@@@ . ...   .@@@@@@@@\n");
    gotoxy(startX, startY + 6);
    printf("@@@@@@@@@@, .....,.   .@@@@@@@\n");
    gotoxy(startX, startY + 7);
    printf("@@@@@@@@@@ .. .   ..  ..@@@@@@\n");
    gotoxy(startX, startY + 8);
    printf("@@@@@@@@@@...   ~. ...  @@@@@@\n");
    gotoxy(startX, startY + 9);
    printf("@@@@@@@@@@@..~  ,*......@@@@@@\n");
    gotoxy(startX, startY + 10);
    printf("@@@@@@@@@@@@@:, .= . ...@@@@@@\n");
    gotoxy(startX, startY + 11);
    printf("@@@@@@@@@@@@@-~     .. ..@@@@@\n");
    gotoxy(startX, startY + 12);
    printf("@@@@@@@@@@@@@@     ... ...@@@@\n");
    gotoxy(startX, startY + 13);
    printf("@@@@@@@@@@@@@@.   ,  .... @@@@\n");
    gotoxy(startX, startY + 14);
    printf("@@@@@@@@@@@@@@ .. . .... ..@@@\n");
    gotoxy(startX, startY + 15);
    printf("@@@@ .@@@@@@-~,.... ....  .@@@\n");
    gotoxy(startX, startY + 16);
    printf("  ., @@@@@@~,.,.  . .---. .@@@\n");
    gotoxy(startX, startY + 17);
    printf("...  @@@@@@-,,.   ..-,..,..@@@\n");
    gotoxy(startX, startY + 18);
    printf("@    @@@@@@,,.... ....~.-..@@@\n");
    gotoxy(startX, startY + 19);
    printf("@@ .  .@@@@-,.... ..,.---..@@@\n");
    gotoxy(startX, startY + 20);
    printf("@@@@   .@@.,....,.,,----,,,,@@\n");
    gotoxy(startX, startY + 21);
    printf("@@@@@,   . ,-...,,,-.--,,--,@@\n");
    gotoxy(startX, startY + 22);
    printf("@@@@@@.     ~...,.-, @ .  .-@@\n");
    gotoxy(startX, startY + 23);
    printf("@@@@@@@.   .@..., .,@@@.   @@@\n");
    gotoxy(startX, startY + 24);
    printf("@@@@@@@@.. @@,.....   @@   .@@\n");
    gotoxy(startX, startY + 25);
    printf("@@@@@@@@@@@@@....,.   @.   .@@\n");
    gotoxy(startX, startY + 26);
    printf("@@@@@@@@@@@@@    .        .@@@\n");
    gotoxy(startX, startY + 27);
    printf("@@@@@@@@@@@@@.    ...   ..@@@@\n");
    gotoxy(startX, startY + 28);
    printf("@@@@@@@@@@@ ........ .,@@@@@@@\n");

    gotoxy(6, 0);
    printf("캐릭터 정보");
    setColor(3);
    gotoxy(2, 1);
    printf("┏──────────────────┓");
    gotoxy(2, 2);
    printf("│                  │");
    gotoxy(2, 3);
    printf("┣──────────────────┫");
    for (int i = 1; i <= 5; i++) {
        gotoxy(2, 3 + i);
        printf("│                  │");
    }
    gotoxy(2, 9);
    printf("┗──────────────────┛");
    setColor(7);

    gotoxy(3, 2);
    printf("%s", nickname);        //닉네임
    gotoxy(3, 4);
    printf("계급  : %s", classes); //계급
    gotoxy(3, 6);
    printf("EXP   : %d", exp);    //경험치 다음경험치까지 몇퍼인지 구현생각해보기(경험치는 %표시시 5자리까지 표기가능)
    gotoxy(3, 8);
    printf("POINT : %d", point);  //포인트

    // 계급별로 닉네임과 계급에 강조효과
    if (strcmp(classes, "공작") == 0) {
        setColor(12);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("◈");
        setColor(7);
        gotoxy(12, 4);
        printf(" 공 작 ");
        setColor(12);
        gotoxy(19, 4);
        printf("◈");
        setColor(7);
    }

    else if (strcmp(classes, "후작") == 0) {
        setColor(13);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("◆");
        setColor(7);
        gotoxy(12, 4);
        printf(" 후 작 ");
        setColor(13);
        gotoxy(19, 4);
        printf("◆");
        setColor(7);
    }

    else if (strcmp(classes, "백작") == 0) {
        setColor(10);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("♣");
        setColor(7);
        gotoxy(12, 4);
        printf(" 백 작 ");
        setColor(10);
        gotoxy(19, 4);
        printf("♣");
        setColor(7);
    }

    else if (strcmp(classes, "자작") == 0) {
        setColor(8);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("♥");
        setColor(7);
        gotoxy(12, 4);
        printf(" 자 작 ");
        setColor(8);
        gotoxy(19, 4);
        printf("♥");
        setColor(7);
    }

    else if (strcmp(classes, "남작") == 0) {
        setColor(6);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("★");
        setColor(7);
        gotoxy(12, 4);
        printf(" 남 작 ");
        setColor(6);
        gotoxy(18, 4);
        printf("★");
        setColor(7);
    }

    else if (strcmp(classes, "기사") == 0) {
        setColor(9);
        gotoxy(3, 2);
        printf("%s", nickname);
        gotoxy(11, 4);
        printf("♠");
        setColor(7);
        gotoxy(12, 4);
        printf(" 기  사 ");
        setColor(9);
        gotoxy(19, 4);
        printf("♠");
        setColor(7);
    }
}