#define _CRT_SECURE_NO_WARNINGS
// 헤더파일
#include "push.h"

uchar getKey();
void cprint(const char *text, COLOR color);
void init(uchar level);
void display(uchar level);
uchar checkFinish(uchar level);
void setWindowSize(int x, int y);
void erasecursor();
uchar move(uchar level, uchar key);
void showScore();
void showHelp();
uint intro();
uint levelcheck();
void aimove();
// 전역변수
static int playtime = 0;
uchar ground[PUZZLESIZE][PUZZLESIZE] = { 0, };
uchar player[2] = { 0, };
uchar monster[10][2] = { 0, };
uchar mode, count = 0;
PLAYDATA data[4] = {
	{ EASY, EASYWALL, EASYBOX, EASYSTORE, EASYMONSTER, EASYLIMIT },
	{ NORMAL, NORMALWALL,NORMALBOX,NORMALSTORE,NORMALMONSTER,NORMALLIMIT },
	{ HARD, HARDWALL,HARDBOX,HARDSTORE,HARDMONSTER,HARDLIMIT },
	{ GOD, GODWALL,GODBOX,GODSTORE,GODMONSTER,GODLIMIT } };

int main() {
	uint key = 0, continueFlag = 0, level, tmp;
	char date[30];
	FILE *fp;
	erasecursor();

	system("title PUSH PUSH");
	system("color 00");

	while (1) {
		mode = intro();
		level = levelcheck();
		//fp = fopen("config.txt", "r");
		//if (fp == NULL) {
		//	fp = fopen("config.txt", "w");
		//	level = 25;
		//	fprintf(fp, "25");
		//}
		//else fscanf(fp,"%d %d", &level);
		//if (level < 15) level = 15;
		//else if (level > 25) level = 25;
		//fclose(fp);
		
		setWindowSize(level * 2, level + 9);
		// player x,y 좌표 배치
		player[0] = rand() % (level - 4) + 2;
		player[1] = rand() % (level - 4) + 2;
		count = 0;
		init(level);
		display(level);
		while (1) {
			key = getKey();
			if (key == EXITKEY) return 0;
			else if (key == RESETKEY) break;
			else if (key == KEYERROR) continue;
			else if (key == SCOREKEY) showScore();
			else if (key == HELPKEY) showHelp();
			move(level, key);
			setWindowSize(level * 2, level + 9), display(level);
			tmp = checkFinish(level);
			if (tmp == CLEAR || tmp == GAMEOVER || count > data[mode-EASY].limit) {
				if (tmp == GAMEOVER)
					cprint("적에게 잡혀버렸습니다...\n", LOSECOLOR);
				else  if (count > data[mode - EASY].limit)
					cprint("움직임 제한을 초과했습니다...\n", OUTCOLOR), tmp = GAMEOUT;
				else 
					cprint("게임에 승리하셧습니다!\n", WINCOLOR);
				printf("계속 진행하시겟습니까? (Y / N)");
				fp = fopen("score.txt", "a");
				_strdate(date);
				fprintf(fp, "%s %d %d %d %d\n", date, mode, level, tmp, count);
				fclose(fp);
				while (1) {
					key = getKey();
					if (key == KEYYES) {
						continueFlag = 1;
						break;
					}
					else if (key == KEYNO) return 0;
				}
			}
			if (continueFlag) {
				continueFlag = 0;
				break;
			}

		}
	}
}