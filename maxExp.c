#include "main.h"

int maxExp(char* type) {
    int max_exp = 0;

    if (strcmp(type, "������") == 0 || strcmp(type, "�䳢") == 0) {
        max_exp = 2000;
    }
    else if (strcmp(type, "�����") == 0) {
        max_exp = 2500;
    }
    else if (strcmp(type, "������") == 0 || strcmp(type, "�Ҵ�") == 0) {
        max_exp = 3000;
    }
    else if (strcmp(type, "����") == 0) {
        max_exp = 3500;
    }
    else if (strcmp(type, "���") == 0) {
        max_exp = 4000;
    }
    else if (strcmp(type, "��") == 0) {
        max_exp = 8000;
    }

    return max_exp;
}