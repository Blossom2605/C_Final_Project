#include "main.h";

void ui_main() {
    int consoleWidth, consoleHeight;
    getConsoleSize(&consoleWidth, &consoleHeight);

    // �ƽ�Ű ��Ʈ�� ũ�� (���⼭�� �ƽ�Ű ��Ʈ�� �ʺ�� ���̸� ����)
    int logoWidth = 2; // �ƽ�Ű ��Ʈ�� �ʺ�
    int logoHeight = 15; // �ƽ�Ű ��Ʈ�� ����

    // �߾� ��ġ ���
    int startX = logoWidth / 2;
    int startY = (consoleHeight - logoHeight) / 2 - 3; // �߾ӿ��� �ణ �������� ����

    gotoxy(startX, startY);
    printf("                ;;;;;;;                           ");
    gotoxy(startX, startY + 1);
    printf("      :::::::   ;;;;;;;  ::                       ");
    gotoxy(startX, startY + 2);
    printf("      ;;;;;;;.  ;;   ;; ,;;-             ;:       ");
    gotoxy(startX, startY + 3);
    printf("      ;;;       ;;:::;; ,;;-      ------ ;:       ");
    gotoxy(startX, startY + 4);
    printf("      ;;;       ;;;;;;; ,;;-     :;;;;;; ;:       ");
    gotoxy(startX, startY + 5);
    printf("      ;;;:::::          ,;;;::::~  ;;;,  ;:       ");
    gotoxy(startX, startY + 6);
    printf("      ;;;;;;;;~;;;;;;;;:,;;;;;;;:  ;;;   ;;,,     ");
    gotoxy(startX, startY + 7);
    printf("        ~;;.  ~;;;;;;;;:   ;;;    .;;;;  ;;;;     ");
    gotoxy(startX, startY + 8);
    printf("     ---:;;~--    ;;;   ---;;;---.;;.:;: ;;..     ");
    gotoxy(startX, startY + 9);
    printf("     ;;;;;;;;;-~;;;;;;;.;;;;;;;;; ;.  ;- ;:       ");
    gotoxy(startX, startY + 10);
    printf("     ..,;;;;.. ~;;;;;;; ..:;;;;..       ~;:       ");
    gotoxy(startX, startY + 11);
    printf("       ;;:;;;       ;;;  -;;:;;:      ~;;;;       ");
    gotoxy(startX, startY + 12);
    printf("      -;~  ;;. ;;;;;;;;  ;;   ;;      ;; ~;~      ");
    gotoxy(startX, startY + 13);
    printf("      ~;-  ;;. ;;;;;;;;  ;;   ;;     .;,  ;;      ");
    gotoxy(startX, startY + 14);
    printf("      .;;-~;;  ;;;       ~;;,:;;      ;; ,;:      ");
    gotoxy(startX, startY + 15);
    printf("       :;;;;-  ;;;;;;;;   ;;;;;       ;;;;;       ");
    gotoxy(startX, startY + 16);
    printf("        .::    ;;;;;;;;    -:~         .:~        ");

    startX = 89;
    startY = 0;

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
}