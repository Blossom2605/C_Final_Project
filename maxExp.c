#include "main.h"

int maxExp(char* type) {
    int max_exp = 0;

    if (strcmp(type, "강아지") == 0 || strcmp(type, "토끼") == 0) {
        max_exp = 2000;
    }
    else if (strcmp(type, "고양이") == 0) {
        max_exp = 2500;
    }
    else if (strcmp(type, "족제비") == 0 || strcmp(type, "팬더") == 0) {
        max_exp = 3000;
    }
    else if (strcmp(type, "돌고래") == 0) {
        max_exp = 3500;
    }
    else if (strcmp(type, "펭귄") == 0) {
        max_exp = 4000;
    }
    else if (strcmp(type, "용") == 0) {
        max_exp = 8000;
    }

    return max_exp;
}