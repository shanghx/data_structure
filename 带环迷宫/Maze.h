#pragma once
#include"Stack.h"
#define MAX_ROW 6
#define MAX_COL 6

typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;

//Stack shortPath;

void  InitMaze(Maze* m, int map[][MAX_COL]);// �Թ��ĳ�ʼ�� 

int IsValidEntry(Maze* m, Position entry);// �������Ƿ�Ϊ��Ч��� 

int IsNextPass(Maze* m, Position cur, Position Next);// ���curλ���Ƿ���ͨ· 

int IsExit(Maze* m, Position entry, Position cur);// ���pCur�Ƿ��ڳ��� 

int _PassMaze(Maze* m, Position entry, Position cur, Stack* Path, Stack* shortPath);// �������Թ����� 

void PassMaze(Maze* m, Position entry, Stack* Path);// �ṩ���û�ʹ�õ����Թ�����

void PrintMaze(Maze* m);
void PrintShortPath(Maze *m, Stack *ShortPath);
