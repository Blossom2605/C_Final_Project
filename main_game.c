#include "main.h"

void main_game(bool comp, char* id) {
    int selected_menu = 0;  // ���õ� �޴� �ε��� (0���� ����)
    int key;    // Ű �Է� �����ؼ� Ű���� �����ϴ� ����

    int num_menu = 6, exp = 0, point = 0;       // �޴� ����, ����ġ, ����Ʈ
    int callFunc = 1;   // esc�� ���������� �Լ� ������ �����������ϴ� ����
    int animalExp = 0;  // ���� ����ġ
    int max = 0;        // ���� �������� �ִ� ����ġ�� ��� ����

    // ���� �г���, ���
    char nickname[50] = "", classes[10] = "";
    // ���� �̸�, ����, �������, ����
    char animalName[50] = "", animalType[50] = "", growth[20] = "", personality[20] = "";

    // myaniaml�� ���� �α��ε� ���̵� ���� ������ �ִ��� �Ǵ��ϴ� bool ����
    bool TrueFalse;

    // ���� ������ �ʱ�ȭ
    srand(time(NULL));

    // comp���� 1�̶��
    if (comp) {
        while (1) {
            // ��� ����Ʈ, ȹ�� ����ġ
            int use_point = 0, get_exp = 0;

            // ���� ������ ��ȯ �޾Ƽ� ������ �����ϴ� ���� �Լ�
            user_info_query(id, nickname, classes, &exp, &point, 0);

            // ������ ������ ������ �ִ��� �Ǵ��ϴ� ���� �Լ�
            TrueFalse = animal_existence_query(id);

            // �ܼ� �ʱ�ȭ
            clearScreen();

            // ������ ������ ������ �ִٸ�
            if (TrueFalse) {
                // id�������� ���� ������ ��ȯ�ϴ� ����
                animal_query(id, animalName, animalType, growth, personality, &animalExp, 0);
                // ���� ������ ���� ���� ���� �ƽ�Ű��Ʈ�� ���
                animal_draw(animalType, growth);
                // ���� ���� ���� ui �׸���
                ui_animal(animalName, animalType, growth, personality, &animalExp);
            }

            // ������ ������ �ִ� ���� ������ ���� �ִ� ����ġ�� ����
            max = maxExp(animalType);

            // ���� ���� �� �ൿ UI�� �׸���
            ui_user(nickname, classes, exp, point);
            ui_action(selected_menu);

            // Ű �Է� ó��
            key = _getch();

            // ����Ű �Է� ó��
            if (key == 224) {
                key = _getch();
                switch (key) {
                case 75:  // ���� ����Ű
                    if (selected_menu > 0)
                        selected_menu--;
                    break;
                case 77:  // ������ ����Ű
                    if (selected_menu < num_menu - 1)
                        selected_menu++;
                    break;
                }
            }

            // ���� Ű �Է� ó��
            else if (key == 13) {
                if (selected_menu == 0) {   // ���� �о�ޱ�
                    if (!TrueFalse) {       // ���� ������ �������� �о��� ���� �� ����
                        Animal myAnimal;    // ���� ����ü ����
                        // ����ü�� ������ ���� �����̸��� ���� ���� ���� �� �ʱ�ȭ
                        char animalName[10] = "", type[10] = "";
                        // ��������Ʈ ���� �о ��ü ����ϰ� �Է����� �����ϰ� ��������(animalName)���� �Է¹���
                        ui_animalList(animalName, type, &callFunc);
                        if (callFunc) {
                            // ������ ������ Ÿ�԰� ������ �Ʒ� �Լ��� �����ؼ� ����ü�� ����
                            save_animal_list(animalName, type, &myAnimal);
                            // ������ �о������ UI �׸��� 
                            ui_saveAnimal(&myAnimal);
                            // Ű�Է� ���
                            _getch();
                            // ������ ������ ������ �����̸��� myanimal ���̺� INSERT�� �����ϴ� ����
                            insert_animal_query(id, &myAnimal);
                            // �α� �����
                            log("��(��) �о�޾Ҵ�!", &myAnimal.type, 0, 1);
                        }
                    }
                    else {  // ���������� ������ �ش� �޴��� ���õǸ� 0��° �����޽����� ���
                        errorMsg(0);
                    }
                }

                else if (selected_menu == 1) {      // ����ֱ�
                    if (TrueFalse) {    // ���� �о��� ������ �޴��� ���� ������ �������� ��밡��
                        // �ش� �Լ��� flag ���ڸ� �����ؼ� ����ֱ�� ���õ� ���� �� ui�� �׸��� ��
                        care_animal(animalType, &point, &use_point, growth, &animalExp, &get_exp, 0, &callFunc);
                        // �α� �����
                        log("��(��) ����־���!", animalType, get_exp, 2);
                        // ���� ���� �� �÷��̾� ����Ʈ ������Ʈ
                        animal_query(id, animalName, animalType, growth, personality, &animalExp, 1);
                        user_info_query(id, nickname, classes, &exp, &point, 1);
                    }
                    else {
                        // ���������� ������ �ش� �޴��� ���õǸ� 1��° �����޽����� ���
                        errorMsg(1);
                    }
                }

                else if (selected_menu == 2) {      // �����ֱ�
                    if (TrueFalse) {        // ���������� �ִٸ�
                        // �ش� �Լ��� �÷������� 1�� �����ؼ� ���� ���� �� UI�� ���
                        care_animal(animalType, &point, &use_point, growth, &animalExp, &get_exp, 1, &callFunc);
                        // ���� ���� �� �÷��̾� ����Ʈ ������Ʈ
                        animal_query(id, animalName, animalType, growth, personality, &animalExp, 1);
                        user_info_query(id, nickname, classes, &exp, &point, 1);
                        // �α� �����
                        log("���� ���̸� �־���!", animalType, get_exp, 3);
                    }
                    else {
                        // ���� ������ ������ �ش� �޴��� ���õǸ� 1��° �����޽����� ���
                        errorMsg(1);
                    }
                }

                else if (selected_menu == 3) {      // �̴ϰ���
                    if (TrueFalse) {    // ���������� �ִٸ�
                        // �̴ϰ��� ���� ���� ����
                        minigame(&point, 2, &callFunc);
                        // ���� ����(point) ������Ʈ
                        user_info_query(id, nickname, classes, &exp, &point, 1);
                    }
                    else {
                        errorMsg(1);
                    }
                }

                else if (selected_menu == 4) {      // �α׺���
                    // log.txt ������ �б� ���� file ������ ����
                    FILE* file = fopen("log.txt", "r");


                    fseek(file, 0, SEEK_END);  // ���� �����͸� ���� ������ �̵�
                    long file_size = ftell(file);  // ���� �������� ���� ��ġ�� ��� ���� ũ�⸦ ��ȯ
                    fclose(file);   // ���� ����

                    if (file_size != 0) {   // ������ ����� 0�� �ƴ϶��
                        // 10��° �α� ������ ���� �� ���
                        log("", "", 0, 10);
                        _getch();
                    }
                    else {
                        // ���� ����� 0�̸� 2��° �����޽����� ���
                        errorMsg(2);
                    }
                }

                else if (selected_menu == 5) {  // ��������
                    log("", "", 0, 0);       // log���� �ʱ�ȭ ���� ����
                    errorMsg(10);   // ���� ���� �޽��� ���
                    // ���α׷� ����
                    exit(0);
                }
            }

            if (TrueFalse) {        // ������ ������ �ְ�
                if (animalExp >= max) { // ������ ����ġ�� �ִ����ġ �̻��̶��
                    // x,y ��ǥ �ʱⰪ
                    int x = 23, y = 1;

                    // ���ڻ� ����
                    setColor(3);

                    // ui���
                    gotoxy(x, y);
                    printf("��������������������������������������������������������������������������������������������������������������������������������");
                    gotoxy(x, y + 1);
                    printf("��                                                              ��");
                    for (int i = 1; i <= 21; i++) {
                        gotoxy(x, y + i);
                        printf("��                                                              ��");
                    }
                    gotoxy(x, y + 22);
                    printf("��������������������������������������������������������������������������������������������������������������������������������");

                    // ���ڻ� ����
                    setColor(7);

                    // ������ ����ġ�� �Ѿ�� ���ư��� �� ����ġ�� ������� ����ϰ� �Է´��
                    gotoxy(37, 11);
                    // ������ 0.1�ʸ��� �ѱ��ھ� ����� Ÿ���� ����
                    slowPrint(100, "������ ����ġ�� �ִ�ġ�� �Ѿ���ϴ�..");

                    _getch();

                    // UI�κи� �ʱ�ȭ�ؼ� �ٸ� UI�� ������� �ʰ� ����
                    clearRegion(24, 2, 59, 20);
                    // ����ġ�� 500 ~ 1500 ������ ���������� ȹ����
                    get_exp = rand() % 500 + 1000;
                    // ȹ�� ����ġ�� exp�� ������
                    exp += get_exp;
                    gotoxy(37, 10);
                    printf("%s", animalName);
                    slowPrint(100, "��(��) �ڽ��� �������� ���ư����ϴ�");
                    gotoxy(37, 11);
                    printf("%d", get_exp);
                    slowPrint(100, " ����ġ ȹ��!");

                    // Ű�Է� ���
                    _getch();

                    // ���� ����ġ, ���, ����Ʈ ���� �� ���� ���� ����
                    user_info_query(id, nickname, classes, &exp, &point, 1);
                    animal_query(id, animalName, animalType, growth, personality, &animalExp, 2);

                    // �α� �����
                    log(animalType, animalName, get_exp, 11);
                }
            }
        }
    }

    else {
        clearScreen();
        return;
    }
}