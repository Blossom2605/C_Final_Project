#include "main.h"

void ui_saveAnimal(Animal* myAnimal) {
    gotoxy(48, 3);
    printf("%s을(를) 분양받았습니다!", myAnimal->type);

    setColor(3);

    gotoxy(48, 12);
    printf("┌──────────────────────────┐");
    for (int i = 1; i <= 5; i++) {
        gotoxy(48, 12 + i);
        printf("│                          │");
    }
    gotoxy(48, 18);
    printf("└──────────────────────────┘");
    
    setColor(7);

    gotoxy(49, 13);
    printf("분양정보");
    gotoxy(49, 15);
    printf("이름 : %s", myAnimal->nickname);
    gotoxy(49, 17);
    printf("성격 : %s", myAnimal->temperament);

    gotoxy(48, 22);
    printf("아무키나 눌러주세요.");
}