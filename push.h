#ifndef PUSHPUSH
#define PUSHPSUH
// 헤더 선언
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
// BLOCKTYPE
#define PUZZLESIZE 26
#define SPACE 0
#define WALL 1
#define MONSTER 2
#define STORE 4
#define BOX 8
#define GETBOX 10
#define PLAYER 9
// KEY
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define RESETKEY 114
#define SCOREKEY 115
#define HELPKEY 104
#define EXITKEY 113
#define KEYERROR 128
#define KEYYES 121
#define KEYNO 110
#define KEYENTER 13
// CLEAR TYPE
#define NOTCLEAR 200
#define CLEAR 201 
#define GAMEOVER 202
#define GAMEOUT 203
// BLOCK COLOR
#define MONSTERCOLOR pink
#define STORECOLOR lightaquamarine
#define BOXCOLOR aquamarine
#define PLAYERCOLOR peachblow
// PRINT COLOR
#define WINCOLOR aquamarine
#define LOSECOLOR pink
#define UNKNOWNCOLOR red
#define SELECTCOLOR aquamarine
#define OUTCOLOR purple
#define NOTICECOLOR yellow
// 자료형 재정의
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;
// 난이도 설정
#define EASY 205
#define NORMAL 206
#define HARD 207
#define GOD 208
// 난이도 색깔
#define EASYCOLOR white
#define NORMALCOLOR yellow
#define HARDCOLOR red
#define GODCOLOR pink
// 플레이 데이터 설정
#define EASYWALL 1
#define EASYBOX 4
#define EASYSTORE 6
#define EASYMONSTER 2
#define EASYLIMIT 250

#define NORMALWALL 4
#define NORMALBOX 6
#define NORMALSTORE 8
#define NORMALMONSTER 3
#define NORMALLIMIT 450

#define HARDWALL 4
#define HARDBOX 7
#define HARDSTORE 10
#define HARDMONSTER 3
#define HARDLIMIT 700

#define GODWALL 6
#define GODBOX 5
#define GODSTORE 10
#define GODMONSTER 2
#define GODLIMIT 900

typedef struct {
	uchar mode;
	uchar wallcount;
	uchar boxcount;
	uchar storecount;
	uchar monstercount;
	ushort limit;
}PLAYDATA;

typedef enum {
	black, blue, green, aquamarine, red, purple, yellow, white, gray, skyblue,
	yellowgreen, lightaquamarine, pink, peachblow, lightyellow, darkgray
} COLOR;

#endif