#pragma once
#include"Stack.h"
#define MAX_ROW 6
#define MAX_COL 6

typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;

//Stack shortPath;

void  InitMaze(Maze* m, int map[][MAX_COL]);// 迷宫的初始化 

int IsValidEntry(Maze* m, Position entry);// 检测入口是否为有效入口 

int IsNextPass(Maze* m, Position cur, Position Next);// 检测cur位置是否是通路 

int IsExit(Maze* m, Position entry, Position cur);// 检测pCur是否在出口 

int _PassMaze(Maze* m, Position entry, Position cur, Stack* Path, Stack* shortPath);// 真正走迷宫函数 

void PassMaze(Maze* m, Position entry, Stack* Path);// 提供给用户使用的走迷宫函数

void PrintMaze(Maze* m);
void PrintShortPath(Maze *m, Stack *ShortPath);
