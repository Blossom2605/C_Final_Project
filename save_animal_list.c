#include "main.h"

void save_animal_list(char* animalName, char* animalType, Animal* animal) {
    // animal_list.txt 파일을 열기
    FILE* file = fopen("animal_list.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 파일을 줄마다 읽어서 값을 저장하는 변수
    char line[100];
    
    // 파일의 line값을 담는데 NULL이면 루프 종료
    while (fgets(line, sizeof(line), file) != NULL) {
        // 텍스트 파일에서 각 줄을 읽고 공백을 기준으로 분리
        char type[20];
        int max_exp;
        char temperament[20];
        sscanf(line, "%s %d %s", type, &max_exp, temperament);

        // 찾고자 하는 동물 타입과 일치하면 구조체에 정보 저장
        if (strcmp(type, animalType) == 0) {
            strncpy(animal->nickname, animalName, sizeof(animal->nickname) - 1);
            animal->nickname[sizeof(animal->nickname) - 1] = '\0';
            strncpy(animal->type, type, sizeof(animal->type) - 1);
            animal->type[sizeof(animal->type) - 1] = '\0';
            animal->max_exp = max_exp;
            strncpy(animal->temperament, temperament, sizeof(animal->temperament) - 1);
            animal->temperament[sizeof(animal->temperament) - 1] = '\0';
            break;
        }
    }

    fclose(file);
}