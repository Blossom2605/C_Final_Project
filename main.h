#pragma once                        // ��� �ߺ� ��� ����
#pragma comment(lib, "libmysql.lib")    // mysql����� ���� lib���� ����
#define _CRT_SECURE_NO_WARNINGS		// CRT SECURE�� ���� ���� �߻� ����
#include <stdio.h>					// ǥ�� ����� ��� ���� ����
#include <stdlib.h>					// ǥ�� ���̺귯�� ��� ���� ����
#include <mysql.h>                  // mysql ��� ���� ����
#include <conio.h>                  // �ܼ� ����� ��� ���� ����
#include <windows.h>                // ������ api ��� ���� ����
#include <time.h>                   // �ð� ��� ���� ����
#include <stdbool.h>                // bool ������Ÿ�� ��� ���� ����
#include <string.h>                 // ���ڿ� ó�� ��� ���� ����

// mysql �������� ��� ��ũ�� ����
#define DB_HOST "127.0.0.1"         // ���� IP �ּҷ� DB ����
#define DB_USER "root"              // ������ ����(ID)
#define DB_PASS "abc123"            // DB ��й�ȣ
#define DB_NAME "project"           // ������ DB��
// DB�� ���� ������ ���๮�ڰ� �ԷµǴ� ���� �����ϴ� ���(�ش� ���α׷������� ���� ��
#define CHOP(x) x[strlen(x) - 1] = ' ' 

// �޴� ���ð��� ���
#define MENU_LOGIN 0                // ���� �޴� �α����� 0
#define MENU_SIGNUP 1               // ���� �޴� ȸ�������� 1
#define MENU_EXIT 2                 // ���� �޴� ��������� 2
#define NUM_MENU_ITEMS 3            // ���� �޴��� �� ������ 3��

// ���� ����ü ����
// ������ �о�������� ���Ǵ� ����ü
// �̸�, ����, �ִ����ġ, ���ݿ� ���ؼ� ������ ����
typedef struct {
    char nickname[10];
    char type[20];
    int max_exp;
    char temperament[20];
} Animal;

// �ý��۰��� �Լ�
void displayMenu(int);	// �޴� ���� �Լ�
void clearScreen();		// �ܼ� �ʱ�ȭ �Լ�
void clearRegion(int, int, int, int);   //Ư������ �ʱ�ȭ �Լ�
void setColor(int);		// �ؽ�Ʈ ������ �Լ�
void hideCursor();		// Ŀ�� ����� �Լ�
void showCursor();		// Ŀ���� ��Ÿ���� �Լ�
void goToMainMenu();	// ���θ޴��� ���ư��� �Լ�
void gotoxy(int, int);	// �ܼ� ��ġ ���� �Լ�
void getConsoleSize(int*, int*);	// �ܼ� ũ�� ���ϴ� �Լ�
void getInput(char*, int, int, int, int);	// �α��� �� ȸ������ �Է�ó�� �Լ�
void slowPrint(unsigned long, const char*); // Ű����Ÿ����ó�� �����ϴ� �Լ� 

// ��� �Լ�
// ���θ޴� �Լ�
void signup(char*, char*, char*);	//ȸ������ �Լ� (���̵� �� �г��� �ߺ������� ���� SELECT COUNT �� ȸ�������� ���� INSERT���� ����)
bool login(char*, char*);			//�α��� �Լ� (���̵� �Ǵ� ��й�ȣ�� Ʋ������ �α����� ���ϰ� �ϱ� ���� SELECT COUNT ���� ����)
void main_game(bool, char*);		//���� �����Լ�
int maxExp(char*);  // ������ ������ �Ǵ��ϰ� �ִ����ġ�� ��ȯ�ϴ� �Լ�
// ���� �о� ���� �Լ�
void save_animal_list(char*, char*, Animal*); // �о���� ������ ����ü�� �����ϴ� �Լ�
void show_animalList(int);     // ��������Ʈ ������ �о�ͼ� ����ϴ� �Լ�
// ���� ����ֱ�, �����ֱ� ���� �Լ�
void care_animal(char*, int*, int*, char*, int*, int*, int, int*);  //������ ����ֱ� or �����ֱ⸦ �����ϴ� �Լ�
void show_care_menu(int, int);      // ����ֱ� or �����ֱ��� �޴��� ����ϴ� �Լ�
bool answer(int);       // ���� ������ �ൿ�� �� ������ ���� �Լ�
// �̴ϰ��� ���� �Լ�
void minigame(int*, int, int*);     // �̴ϰ��� �������� ����ϴ� �Լ�
int animalRace(int*);       // ���� ���̽��� �����ϴ� �Լ�
int typingGame(int*);       // Ÿ���� ������ �����ϴ� �Լ�(������ ���� ������ �о�ͼ� �������� ���)
// �α� ���� �Լ�
void log(const char*, const char*, int, int);   //�α�(�ൿ)�� ���Ͽ� �����ϰų� �ʱ�ȭ�ϴ� �Լ�

// mysql ���� �Լ�
void user_info_query(char*, char*, char*, int*, int*, int);     // member ���̺��� ���������� �޾ƿ��ų� �����͸� �����ϴ� �Լ�(flag 0 = SELECT, flag = 1UPDATE)
bool animal_existence_query(char*);  // myanimal ���̺��� ������ �о�޾Ƽ� �����Ͱ� 1�� �̻� �ִ��� �Ǵ��ϴ� �Լ�(SELECT COUNT)
void insert_animal_query(char*, Animal*);   // myanimal ���̺� ������ �о�ް� ���� ������ �����ϴ� �Լ�(INSERT)
void animal_query(char*, char*, char*, char*, char*, int*, int);
// ���� �о��� �����ϰ� ������ ������ �޾ƿ��ų� ������ ����, ������ ������ �ϴ� �Լ�(flag 0 = SELECT, flag 1 = UPDATE, flag 2 = DELETE) 

// ui�� �׸��� �Լ�
void ui_main();         // ����ȭ�� �ƽ�Ű��Ʈ�� �׸��� �Լ�
void ui_signup();		// ȸ������ ȭ���� �׸��� �Լ�
void ui_login();        // �α��� ȭ���� �׸��� �Լ�
void ui_user(char*, char*, int, int);   // ���� ���� UI�� �׸��� �Լ�
void ui_action(int);    // ������ ���� �� �ִ� ���� �޴� UI�� �׸��� �Լ�
void ui_animalList(char*, char*, int*); // �о� ���� �� �ִ� ���� UI�� �׸��� �Լ�
void ui_saveAnimal(Animal*);    // �о� ���� ���� �̸��� ���ϴ� UI�� �׸��� �Լ�
void ui_log();          // �α�(�ൿ)�� �� �� �ִ� UI�� �׸��� �Լ�
void ui_animal(char*, char*, char*, char*, int*);   // �� ���� ���� UI�� �׸��� �Լ�
void ui_list(int);      // ����Ʈ UI�� �׸��� �Լ�

void errorMsg(int);     // ���� ���� �޽��� �� UI�� �׸��� �Լ�
void animal_draw(char*, char*);      // �ƽ�Ű��Ʈ�� ����Ǿ��ִ� ������ �о �׸��� �Լ�