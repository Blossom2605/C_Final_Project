#pragma once                        // 헤더 중복 사용 방지
#pragma comment(lib, "libmysql.lib")    // mysql사용을 위한 lib파일 선언
#define _CRT_SECURE_NO_WARNINGS		// CRT SECURE에 대한 오류 발생 중지
#include <stdio.h>					// 표준 입출력 헤더 파일 선언
#include <stdlib.h>					// 표준 라이브러리 헤더 파일 선언
#include <mysql.h>                  // mysql 헤더 파일 선언
#include <conio.h>                  // 콘솔 입출력 헤더 파일 선언
#include <windows.h>                // 윈도우 api 헤더 파일 선언
#include <time.h>                   // 시간 헤더 파일 선언
#include <stdbool.h>                // bool 데이터타입 헤더 파일 선언
#include <string.h>                 // 문자열 처리 헤더 파일 선언

// mysql 연동관련 상수 매크로 선언
#define DB_HOST "127.0.0.1"         // 로컬 IP 주소로 DB 연결
#define DB_USER "root"              // 관리자 계정(ID)
#define DB_PASS "abc123"            // DB 비밀번호
#define DB_NAME "project"           // 연결할 DB명
// DB에 값을 넣을때 개행문자가 입력되는 것을 방지하는 상수(해당 프로그램에서는 선언만 함
#define CHOP(x) x[strlen(x) - 1] = ' ' 

// 메뉴 선택관련 상수
#define MENU_LOGIN 0                // 메인 메뉴 로그인은 0
#define MENU_SIGNUP 1               // 메인 메뉴 회원가입은 1
#define MENU_EXIT 2                 // 메인 메뉴 게임종료는 2
#define NUM_MENU_ITEMS 3            // 메인 메뉴의 총 갯수는 3개

// 동물 구조체 정의
// 동물을 분양받을때만 사용되는 구조체
// 이름, 종류, 최대경험치, 성격에 대해서 저장이 가능
typedef struct {
    char nickname[10];
    char type[20];
    int max_exp;
    char temperament[20];
} Animal;

// 시스템관련 함수
void displayMenu(int);	// 메뉴 선택 함수
void clearScreen();		// 콘솔 초기화 함수
void clearRegion(int, int, int, int);   //특정구역 초기화 함수
void setColor(int);		// 텍스트 색지정 함수
void hideCursor();		// 커서 숨기는 함수
void showCursor();		// 커서를 나타내는 함수
void goToMainMenu();	// 메인메뉴로 돌아가는 함수
void gotoxy(int, int);	// 콘솔 위치 조정 함수
void getConsoleSize(int*, int*);	// 콘솔 크기 구하는 함수
void getInput(char*, int, int, int, int);	// 로그인 및 회원가입 입력처리 함수
void slowPrint(unsigned long, const char*); // 키보드타이핑처럼 연출하는 함수 

// 기능 함수
// 메인메뉴 함수
void signup(char*, char*, char*);	//회원가입 함수 (아이디 및 닉네임 중복방지를 위한 SELECT COUNT 와 회원가입을 위한 INSERT쿼리 존재)
bool login(char*, char*);			//로그인 함수 (아이디 또는 비밀번호가 틀렸을때 로그인을 못하게 하기 위해 SELECT COUNT 쿼리 존재)
void main_game(bool, char*);		//메인 게임함수
int maxExp(char*);  // 동물의 종류를 판단하고 최대경험치를 반환하는 함수
// 동물 분양 관련 함수
void save_animal_list(char*, char*, Animal*); // 분양받을 동물을 구조체에 저장하는 함수
void show_animalList(int);     // 동물리스트 파일을 읽어와서 출력하는 함수
// 동물 놀아주기, 먹이주기 관련 함수
void care_animal(char*, int*, int*, char*, int*, int*, int, int*);  //동물과 놀아주기 or 먹이주기를 진행하는 함수
void show_care_menu(int, int);      // 놀아주기 or 먹이주기의 메뉴를 출력하는 함수
bool answer(int);       // 정말 선택한 행동을 할 것인지 묻는 함수
// 미니게임 관련 함수
void minigame(int*, int, int*);     // 미니게임 선택지를 출력하는 함수
int animalRace(int*);       // 동물 레이싱을 진행하는 함수
int typingGame(int*);       // 타이핑 게임을 진행하는 함수(문제는 문장 파일을 읽어와서 랜덤으로 출력)
// 로그 관련 함수
void log(const char*, const char*, int, int);   //로그(행동)을 파일에 저장하거나 초기화하는 함수

// mysql 쿼리 함수
void user_info_query(char*, char*, char*, int*, int*, int);     // member 테이블에서 유저정보를 받아오거나 데이터를 갱신하는 함수(flag 0 = SELECT, flag = 1UPDATE)
bool animal_existence_query(char*);  // myanimal 테이블에서 동물을 분양받아서 데이터가 1개 이상 있는지 판단하는 함수(SELECT COUNT)
void insert_animal_query(char*, Animal*);   // myanimal 테이블에 동물을 분양받고 동물 정보를 저장하는 함수(INSERT)
void animal_query(char*, char*, char*, char*, char*, int*, int);
// 동물 분양을 제외하고 동물의 정보를 받아오거나 데이터 갱신, 데이터 삭제를 하는 함수(flag 0 = SELECT, flag 1 = UPDATE, flag 2 = DELETE) 

// ui를 그리는 함수
void ui_main();         // 메인화면 아스키아트를 그리는 함수
void ui_signup();		// 회원가입 화면을 그리는 함수
void ui_login();        // 로그인 화면을 그리는 함수
void ui_user(char*, char*, int, int);   // 유저 정보 UI를 그리는 함수
void ui_action(int);    // 유저가 행할 수 있는 게임 메뉴 UI를 그리는 함수
void ui_animalList(char*, char*, int*); // 분양 받을 수 있는 동물 UI를 그리는 함수
void ui_saveAnimal(Animal*);    // 분양 받을 동물 이름을 정하는 UI를 그리는 함수
void ui_log();          // 로그(행동)을 볼 수 있는 UI를 그리는 함수
void ui_animal(char*, char*, char*, char*, int*);   // 내 동물 정보 UI를 그리는 함수
void ui_list(int);      // 리스트 UI를 그리는 함수

void errorMsg(int);     // 에러 관련 메시지 및 UI를 그리는 함수
void animal_draw(char*, char*);      // 아스키아트가 저장되어있는 파일을 읽어서 그리는 함수