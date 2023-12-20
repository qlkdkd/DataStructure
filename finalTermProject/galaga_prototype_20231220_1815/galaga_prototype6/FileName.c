// 한성대학교 2023 2학기 자료구조 기말과제 <슈팅게임-갤러그>
// 2171358 신대한 && 2393084 김민상
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define ENEMY_NUM 3 //적의 수
#define PLAYER_START_X 25 //플레이어 시작 x
#define PLAYER_START_Y 40 //플레이어 시작 y
#define BULLET_NUM 4 //플레이어가 동시에 발사 가능한 총알 수
#define ENEMY_BULLET_NUM (ENEMY_NUM * 5) //적이 발사 가능한 총알 수

#define MAX_X 48 // 이동가능한 x좌표의 최대 범위
#define MIN_X 2 // 이동가능한 x좌표의 최소 범위 
#define MAX_Y 40 // 이동가능한 y좌표의 최대 범위
#define MIN_Y 2 // 이동가능한 y좌표의 최소 범위 
#define CENTER_LINE 20 // 플레이어와 적 사이의 이동 경계

void gotoxy(int x, int y);
void PrintGameTitle();
void start_menu();
void QuitGame();
void game_manual();
void gotoxy(int x, int y);
void print_player(int x, int y, bool exist);
void print_enemy(int x, int y, bool exist);
void print_bullet(int x, int y, bool exist);
void hide_cursor(int num);
void bullet_moving();
int checking_hit();
void enemy_rand_moving_();
void print_enemy_bullet(int x, int y, bool exist);
void enemy_rand_shooting();
void print_gameover();
void print_win();
void print_hsu();
int checking_game_end();
void update_score();//점수 표시

//효과음 함수
void play_background_music();//시작 브금
void play_shot_sound();



typedef struct bullet_state { //총알의 현재 좌표를 알려주는 구조체
    int x;
    int y;
    bool exist;
} bullet_state;

typedef struct player_state { //플레이어의 현재 상태를 알려주는 구조체
    int x;
    int y;
    int health;
    int speed;
    bool exist; //생존 여부
} player_state;

typedef struct enemy_state { // 적의 현재 상태를 알려주는 구조체
    int x;
    int y;
    int health;
    int speed;
    bool exist; // 생존 여부
} enemy_state;

int score = 0;//점수
clock_t  lastScoreUpdateTime;

player_state player;
enemy_state enemy[ENEMY_NUM];
bullet_state bullet[BULLET_NUM];
bullet_state enemy_bullet[ENEMY_BULLET_NUM];

void StartGame() { //본 게임 코드
    printf("게임이 시작됩니다!\n");
    PlaySound(TEXT("Enemy_Division.wav"), NULL, SND_FILENAME | SND_ASYNC);
    system("cls"); // 콘솔창 지우는 명령어

    player.x = PLAYER_START_X; //플레이어 상태 초기화
    player.y = PLAYER_START_Y;
    player.health = 0;
    player.speed = 0;
    player.exist = true;

    for (int i = 0; i < ENEMY_NUM; i++) { //적 상태 초기화
        enemy[i].x = 5 + 15 * i;
        enemy[i].y = 1 + 3 * i;
        enemy[i].health = 0;
        enemy[i].speed = 0;
        enemy[i].exist = true;
    }

    lastScoreUpdateTime = clock();//마지막 점수를 초기화
    while (1) {
        print_player(player.x, player.y, player.exist); // 플레이어 출력

        for (int i = 0; i < ENEMY_NUM; i++) { // 적 출력
            print_enemy(enemy[i].x, enemy[i].y, enemy[i].exist);
        }

        int hit = checking_hit();
        bullet_moving(); // 총알 이동 시키는 함수 작동
        if (checking_game_end() == 0) break; // 게임이 끝난 상황인지 확인하는 함수&조건문
        enemy_rand_moving_(); // 적을 랜덤하게 이동시키는 함수
        enemy_rand_shooting(); // 적이 랜덤하게 총알을 쏘는 함수

        // 플레이어 상하좌우 방향키로 이동하게 하는 조건문
        if ((GetAsyncKeyState(VK_UP) & 0x0001) && (MIN_Y < player.y) && (player.y > CENTER_LINE)) {
            print_player(player.x, player.y, false);
            player.y--;
            print_player(player.x, player.y, true);
        }
        if ((GetAsyncKeyState(VK_DOWN) & 0x0001) && (MAX_Y > player.y)) {
            print_player(player.x, player.y, false);
            player.y++;
            print_player(player.x, player.y, true);
        }
        if ((GetAsyncKeyState(VK_RIGHT) & 0x0001) && (MAX_X > player.x)) {
            print_player(player.x, player.y, false);
            player.x++;
            print_player(player.x, player.y, true);
        }
        if ((GetAsyncKeyState(VK_LEFT) & 0x0001) && (MIN_X < player.x)) {
            print_player(player.x, player.y, false);
            player.x--;
            print_player(player.x, player.y, true);
        }

        //스페이스바 키로 총알 발사하는 조건문
        if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
            int i = 0;
            while (i < BULLET_NUM && bullet[i].exist) { //사용 불가능한 총알 수 계산하는 반복문
                i++;
            }
            if (i != BULLET_NUM) {
                bullet[i].x = player.x;
                bullet[i].y = player.y + 2;
                bullet[i].exist = true;
                play_shot_sound();
            }
        }
        //0.1초마다 1점씩 추가
        clock_t currentTime = clock();
        double elapsedSeconds = (double)(currentTime - lastScoreUpdateTime) / CLOCKS_PER_SEC;
        if (elapsedSeconds >= 0.1) {
            score++;
            update_score();
            lastScoreUpdateTime = currentTime;
        }

        //적 잡으면 100점 획득
        if (hit) {
            score += 100;
        }
        update_score();

        gotoxy(0, 42);
        printf("HANSUNG UNIVERSITY DEPARTMENT OF APPLIED AI");

        Sleep(20); // 0.02초 간격으로 화면 업데이트
    }
    Sleep(5000); // 5초 대기 후 메인 메뉴로 넘어감
}

void gotoxy(int x, int y) { //커서를 특정 좌표로 이동시키는 함수
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_player(int x, int y, bool exist) { // 플레이어를 화면에 출력하는 함수
    if (exist == true) {
        gotoxy(x-1, y); printf("○");
        gotoxy(x - 2, y + 1); printf("◇△◇");
    }

    if (exist != true) {
        gotoxy(x, y); printf("   ");
        gotoxy(x - 2, y + 1); printf("         ");
    }
}

void print_enemy(int x, int y, bool exist) { // 적을 화면에 출력하는 함수
    if (exist == true) {
        gotoxy(x - 2, y - 1); printf("◆▼◆");
        gotoxy(x-1, y); printf("●");
    }

    if (exist != true) {
        gotoxy(x - 2, y - 1); printf("      ");
        gotoxy(x, y); printf("   ");
    }
}

void print_bullet(int x, int y, bool exist) { // 플레이어의 총알을 화면에 출력하는 함수
    if (exist == true) {
        gotoxy(x, y);
        printf("∧");
    }

    if (exist != true) {
        gotoxy(x, y);
        printf("  ");
    }
}

void print_enemy_bullet(int x, int y, bool exist) { // 적의 총알을 화면에 출력하는 함수
    if (exist == true) {
        gotoxy(x, y);
        printf("v");
    }

    if (exist != true) {
        gotoxy(x, y);
        printf("  ");
    }
}

void bullet_moving() { // 총알 이동시키는 함수
    int i, j;
    //플레이어의 총알 이동
    for (i = 0; i < BULLET_NUM; i++) {
        print_bullet(bullet[i].x, bullet[i].y, false);
        if (bullet[i].y == 0) {
            bullet[i].exist = false;
        }
        else {
            bullet[i].y--;
            print_bullet(bullet[i].x, bullet[i].y, bullet[i].exist);
        }
    }

    //적의 총알 이동
    for (j = 0; j < ENEMY_BULLET_NUM; j++) {
        print_enemy_bullet(enemy_bullet[j].x, enemy_bullet[j].y, false);
        if (enemy_bullet[j].y == 42) {
            enemy_bullet[j].exist = false;
        }
        else {
            enemy_bullet[j].y++;
            print_enemy_bullet(enemy_bullet[j].x, enemy_bullet[j].y, enemy_bullet[j].exist);
        }
    }
}

int checking_hit() { // 총알 피격 판정 담당하는 함수
    int hit = 0;
    //적의 피격 판정
    int i = 0, j = 0, p = 0;
    for (i = 0; i < ENEMY_NUM; i++) {
        for (j = 0; j < BULLET_NUM; j++) {
            if ((bullet[j].x == enemy[i].x) && (bullet[j].y == enemy[i].y) && (bullet[j].exist == true) && (enemy[i].exist == true)) {
                PlaySound(TEXT("Hit_on_Zako.wav"), NULL, SND_FILENAME | SND_ASYNC);
                bullet[j].exist = false;
                enemy[i].exist = false;
                hit = 1;
            }
        }
    }

    //플레이어의 피격 판정
    for (p = 0; p < ENEMY_BULLET_NUM; p++) {
        if ((p < ENEMY_BULLET_NUM) && (enemy_bullet[p].x == player.x) && (enemy_bullet[p].y == player.y) && (enemy_bullet[p].exist == true) && (player.exist == true)) {
            bullet[p].exist = false;
            player.exist = false;
        }
    }
    return hit;
}

void enemy_rand_moving_() { // 적을 랜덤으로 이동시키는 함수
    srand((unsigned int)time(NULL));
    int rand_x, rand_y;
    int i = 0;

    for (i = 0; i < ENEMY_NUM; i++) {
        rand_x = (rand() % 3) - 1; // x = -1, 0, 1
        rand_y = (rand() % 3) - 1; // y = -1, 0, 1

        //이동 가능한 xy범위의 최대값을 넘지 않는 경우에만 이동하는 조건문
        if (enemy[i].exist == true) {
            print_enemy(enemy[i].x, enemy[i].y, false);
            if (((enemy[i].x + rand_x) > MIN_X + 3) && ((enemy[i].x + rand_x) < MAX_X - 3)) {
                enemy[i].x += rand_x;
            }

            if (((enemy[i].y + rand_y) > MIN_Y + 3) && ((enemy[i].y + rand_y) < CENTER_LINE)) {
                enemy[i].y += rand_y;
            }
            print_enemy(enemy[i].x, enemy[i].y, enemy[i].exist);
        }
    }
}

void enemy_rand_shooting() { //적이 랜덤으로 총알을 발사하는 함수
    srand((unsigned int)time(NULL));
    int i = 0;
    int r_num;

    while (i < ENEMY_BULLET_NUM && enemy_bullet[i].exist) { //사용 불가능한 총알 수 계산하는 반복문
        i++;
    }
    if (i != ENEMY_BULLET_NUM) {
        while (i == 0) {
            r_num = rand() % ENEMY_NUM; //적의 인덱스를 랜덤으로 선택
            if (enemy[r_num].exist == true) {
                enemy_bullet[i].x = enemy[r_num].x;
                enemy_bullet[i].y = enemy[r_num].y - 2;
                enemy_bullet[i].exist = true;
                i--;
            }
        }
    }
}

void update_score() {
    gotoxy(0, 43);
    printf("Score: %d", score);
}


int checking_game_end() { // 게임이 끝난 상황인지 확인하는 함수
    if (player.exist != true) { //플레이어의 패배를 확인하는 조건문
        system("cls"); // 화면 지우기
        print_gameover(); // 게임 오버 화면 출력
        PlaySound(TEXT("Game_Over.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return 0;
    }

    int i = 0;
    while (i < ENEMY_NUM && !enemy[i].exist) { //제거한 적 숫자 계산하는 반복문
        i++;
    }
    if (i == ENEMY_NUM) { //플레이어의 승리를 확인하는 조건문
        system("cls"); // 화면 지우기
        print_win(); // 게임 승리 화면 출력
        PlaySound(TEXT("Game_Clear.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return 0;
    }

    return 1;
}

void print_gameover() { // 게임오버 화면 출력하는 함수 
    int start_x, start_y, length;
    length = 26;

    start_x = (52 - length) / 2;
    start_y = 5;

    gotoxy(start_x, start_y);
    printf(" ###     #    #   #  #####");
    gotoxy(start_x, start_y + 1);
    printf("#   #   # #   #   #  #    ");
    gotoxy(start_x, start_y + 2);
    printf("#      #   #  ## ##  #    ");
    gotoxy(start_x, start_y + 3);
    printf("#      #   #  # # #  #### ");
    gotoxy(start_x, start_y + 4);
    printf("#  ##  #####  #   #  #    ");
    gotoxy(start_x, start_y + 5);
    printf("#   #  #   #  #   #  #    ");
    gotoxy(start_x, start_y + 6);
    printf(" ###   #   #  #   #  #####");

    gotoxy(start_x, start_y + 8);
    printf(" ###   #   #  #####  #### ");
    gotoxy(start_x, start_y + 9);
    printf("#   #  #   #  #      #   #");
    gotoxy(start_x, start_y + 10);
    printf("#   #  #   #  #      #   #");
    gotoxy(start_x, start_y + 11);
    printf("#   #   # #   ####   #### ");
    gotoxy(start_x, start_y + 12);
    printf("#   #   # #   #      # #  ");
    gotoxy(start_x, start_y + 13);
    printf("#   #   # #   #      #  # ");
    gotoxy(start_x, start_y + 14);
    printf(" ###     #    #####  #   #");
}

void print_win() { // 승리 화면 출력하는 함수
    int start_x, start_y, length;
    length = 19;

    start_x = (52 - length) / 2;
    start_y = 5;

    gotoxy(start_x, start_y);
    printf("#   #   ###   #   #");
    gotoxy(start_x, start_y + 1);
    printf("#   #  #   #  #   #");
    gotoxy(start_x, start_y + 2);
    printf(" # #   #   #  #   #");
    gotoxy(start_x, start_y + 3);
    printf("  #    #   #  #   #");
    gotoxy(start_x, start_y + 4);
    printf("  #    #   #  #   #");
    gotoxy(start_x, start_y + 5);
    printf("  #    #   #  #   #");
    gotoxy(start_x, start_y + 6);
    printf("  #     ###    ### ");

    gotoxy(start_x, start_y + 8);
    printf("#   #   ###   #   #");
    gotoxy(start_x, start_y + 9);
    printf("#   #    #    #   #");
    gotoxy(start_x, start_y + 10);
    printf("#   #    #    ##  #");
    gotoxy(start_x, start_y + 11);
    printf("# # #    #    # # #");
    gotoxy(start_x, start_y + 12);
    printf("# # #    #    #  ##");
    gotoxy(start_x, start_y + 13);
    printf("## ##    #    #   #");
    gotoxy(start_x, start_y + 14);
    printf("#   #   ###   #   #");
}

void print_hsu() { // HSU 출력하는 함수
    int start_x, start_y, length;
    length = 19;

    start_x = (52 - length) / 2;
    start_y = 5;

    gotoxy(start_x, start_y);
    printf("#   #   ###   #   #");
    gotoxy(start_x, start_y + 1);
    printf("#   #  #   #  #   #");
    gotoxy(start_x, start_y + 2);
    printf("#   #  #      #   #");
    gotoxy(start_x, start_y + 3);
    printf("#####   ###   #   #");
    gotoxy(start_x, start_y + 4);
    printf("#   #      #  #   #");
    gotoxy(start_x, start_y + 5);
    printf("#   #  #   #  #   #");
    gotoxy(start_x, start_y + 6);
    printf("#   #   ###    ### ");
}

void PrintGameTitle() { // 타이틀 출력하는 함수
    int title_x;

    title_x = (52 - 23) / 2;

    gotoxy(title_x, 5);
    printf("### ### #   ### ### ###");
    gotoxy(title_x, 6);
    printf("#   # # #   # # #   # #");
    gotoxy(title_x, 7);
    printf("# # ### #   ### # # ###");
    gotoxy(title_x, 8);
    printf("### # # ### # # ### # #");
}

void game_manual() {
    system("cls");
    print_hsu();
    int start_x, start_y, length;
    length = 36;

    start_x = (52 - length) / 2;
    start_y = 15;

    gotoxy(start_x, start_y);
    printf("한성 갤러그의 조작법을 설명하겠습니다.");
    gotoxy(start_x, start_y + 2);
    printf("상하좌우 방향키로 우주선을 조작합니다.");
    gotoxy(start_x, start_y + 4);
    printf("스페이스바 버튼으로 총알을 발사합니다.");
    gotoxy(start_x, start_y + 6);
    printf("적 우주선을 모두 격추하면 승리합니다.");
    Sleep(5000);
}

void QuitGame() {
    printf("게임을 종료합니다.\n");
    exit(0);
}

void hide_cursor(int num) { //커서 숨기는 함수
    CONSOLE_CURSOR_INFO console_cursor;
    HANDLE handle_console = GetStdHandle(STD_OUTPUT_HANDLE);

    console_cursor.bVisible = num;
    console_cursor.dwSize = 1;
    SetConsoleCursorInfo(handle_console, &console_cursor);
}

void play_background_music() {
    PlaySound(TEXT("Game_Start_Music.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void play_shot_sound() {
    PlaySound(TEXT("Shot.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void start_menu() { //시작 메뉴 출력하는 함수
    int choice = 1;
    char key;
    int menuX, menuY;

    while (1) {
        system("cls");

        menuX = (52 - 12) / 2;
        menuY = (42 - 4) / 2;

        PrintGameTitle(); // 게임 제목 출력

        gotoxy(menuX, menuY);
        printf("1. 게임 시작");
        if (choice == 1) printf(" <--");
        gotoxy(menuX, menuY + 1);
        printf("2. 게임 방법");
        if (choice == 2) printf(" <--");
        gotoxy(menuX, menuY + 2);
        printf("3. 종료");
        if (choice == 3) printf(" <--");

        key = _getch();

        switch (key) {
        case 72:
            if (choice > 1) choice--;
            break;
        case 80:
            if (choice < 3) choice++;
            break;
        case 13:
            switch (choice) {
            case 1:
                StartGame();
                break;
            case 2:
                //printf("게임 방법\n");
                game_manual();
                break;
            case 3:
                QuitGame();
                break;
            }
            break;
        }
    }
}

int main() {
    hide_cursor(0);
    system("cls");
    system("title 2023_Hansung_Galaga");
    system("mode con: cols=52 lines=43"); // 52행 43열 

    play_background_music();
    lastScoreUpdateTime = clock();
    start_menu();
    return 0;
}