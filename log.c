#include "main.h"

void log(const char* log_message, const char* text, int textNum, int flag) {
    // ���� �ð��� ��� �ϱ� ���� ���õ� �͵��� �̸� ���� �� ����
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;

    // flag�� 0 : ���� �ʱ�ȭ
    if (flag == 0) {
        FILE* file = fopen("log.txt", "w");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fclose(file);
    }

    // flag���� 1 ~ 9��� ���õ� �α� �߰��Ѵ�.
    else if (flag == 1) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s%s\n", year, month, day, hour, min, sec, text, log_message);

        fclose(file);
    }

    else if (flag == 2) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s%s(ȹ�� ���� ����ġ : %d)\n", year, month, day, hour, min, sec, text, log_message, textNum);

        fclose(file);
    }

    else if (flag == 3) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s%s(ȹ�� ���� ����ġ : %d)\n", year, month, day, hour, min, sec, text, log_message, textNum);

        fclose(file);
    }

    else if (flag == 4) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) Ÿ�ڰ������� %d ����Ʈ�� �����!\n", year, month, day, hour, min, sec, textNum);

        fclose(file);
    }

    else if (flag == 5) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s���� %d ����Ʈ�� �����!\n", year, month, day, hour, min, sec, log_message, textNum);

        fclose(file);
    }

    else if (flag == 6) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) ���� ���̽� ����Ʈ�� ���� ���ߴ�...\n", year, month, day, hour, min, sec);

        fclose(file);
    }

    else if (flag == 8) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s��(��) %s ����� �Ǿ���!\n�±ޱ�� ����Ʈ : %d\n", year, month, day, hour, min, sec, text, log_message, textNum);

        fclose(file);
    }

    else if (flag == 9) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s��(��) %s ������ �ߴ�!\n", year, month, day, hour, min, sec, text, log_message);

        fclose(file);
    }

    // flag���� 10�̶�� ���ݱ��� ����� �α׸� ����Ѵ�.
    else if (flag == 10) {
        ui_log();

        FILE* file = fopen("log.txt", "r");

        if (file == NULL) {
            printf("������ �� �� �����ϴ�.\n");
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

    // flag���� 11�̶�� ������ ������ �α׸� �����.
    else if (flag == 11) {
        FILE* file = fopen("log.txt", "a");

        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�.\n");
            return;
        }

        fprintf(file, "(%d/%d/%d %d:%d:%d) %s(%s)��(��)\n", year, month, day, hour, min, sec, log_message, text);
        fprintf(file, "�ڽ��� �������� ���ư���\n");
        fprintf(file, "ȹ�� ����ġ : %d\n", textNum);

        fclose(file);
    }
}