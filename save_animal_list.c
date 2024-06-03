#include "main.h"

void save_animal_list(char* animalName, char* animalType, Animal* animal) {
    // animal_list.txt ������ ����
    FILE* file = fopen("animal_list.txt", "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // ������ �ٸ��� �о ���� �����ϴ� ����
    char line[100];
    
    // ������ line���� ��µ� NULL�̸� ���� ����
    while (fgets(line, sizeof(line), file) != NULL) {
        // �ؽ�Ʈ ���Ͽ��� �� ���� �а� ������ �������� �и�
        char type[20];
        int max_exp;
        char temperament[20];
        sscanf(line, "%s %d %s", type, &max_exp, temperament);

        // ã���� �ϴ� ���� Ÿ�԰� ��ġ�ϸ� ����ü�� ���� ����
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