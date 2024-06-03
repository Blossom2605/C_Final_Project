#include "main.h"

void log(const char* log_message, const char* text, int textNum, int flag) {
    // 현재 시간을 출력 하기 위해 관련된 것들을 미리 선언 및 정의
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;

    // flag값 0 : 파일 초기화
    if (flag == 0) {
        FILE* file = fopen("log.txt", "w");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fclose(file);
    }

    // flag값이 1 ~ 9라면 관련된 로그 추가한다.
    else if (flag == 1) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s%s\n", year, month, day, hour, min, sec, text, log_message);

        fclose(file);
    }

    else if (flag == 2) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s%s(획득 동물 경험치 : %d)\n", year, month, day, hour, min, sec, text, log_message, textNum);

        fclose(file);
    }

    else if (flag == 3) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s%s(획득 동물 경험치 : %d)\n", year, month, day, hour, min, sec, text, log_message, textNum);

        fclose(file);
    }

    else if (flag == 4) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) 타자게임으로 %d 포인트를 얻었다!\n", year, month, day, hour, min, sec, textNum);

        fclose(file);
    }

    else if (flag == 5) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s으로 %d 포인트를 얻었다!\n", year, month, day, hour, min, sec, log_message, textNum);

        fclose(file);
    }

    else if (flag == 6) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) 동물 레이싱 포인트를 얻지 못했다...\n", year, month, day, hour, min, sec);

        fclose(file);
    }

    else if (flag == 8) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s이(가) %s 계급이 되었다!\n승급기념 포인트 : %d\n", year, month, day, hour, min, sec, text, log_message, textNum);

        fclose(file);
    }

    else if (flag == 9) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s이(가) %s 성장을 했다!\n", year, month, day, hour, min, sec, text, log_message);

        fclose(file);
    }

    // flag값이 10이라면 지금까지 저장된 로그를 출력한다.
    else if (flag == 10) {
        ui_log();

        FILE* file = fopen("log.txt", "r");

        if (file == NULL) {
            printf("파일을 열 수 없습니다.\n");
            return;
        }

        int i = 2;
        char line[1024];
        int line_count = 0;
        int current_line = 0;
        int lines = 0;

        while (fgets(line, sizeof(line), file) != NULL) {
            line_count++;
        }

        fclose(file);

        fopen("log.txt", "r");

        while (fgets(line, sizeof(line), file) != NULL) {
            lines++;
            if (line_count > 22) {
                current_line = line_count - 22;
                if (lines > current_line) {
                    gotoxy(24, i);
                    printf(line);
                    i++;
                }
            }
            else {
                gotoxy(24, i);
                printf(line);
                i++;
            }
        }

        fclose(file);
    }

    // flag값이 11이라면 동물이 떠나간 로그를 남긴다.
    else if (flag == 11) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s(%s)이(가)\n", year, month, day, hour, min, sec, log_message, text);
        fprintf(file, "자신의 고향으로 돌아갔다\n");
        fprintf(file, "획득 경험치 : %d\n", textNum);

        fclose(file);
    }
}