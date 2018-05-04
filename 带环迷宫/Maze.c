#include"Maze.h"
#include"Stack.h"

void UndataPath(Stack *shortPath, Stack *Path)//更新路径
{
	int i = 0;
	assert(shortPath);
	assert(Path);
	while (i<StackSize(Path))
	{
		shortPath->_array[i] = Path->_array[i];
		i++;
	}
	shortPath->_top = i;
	shortPath->capacity = i;
}
void InitMaze(Maze* m, int map[][MAX_COL])// 迷宫的初始化 
{
	assert(m);
	int i = 0, j = 0;
	for (; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			m->_map[i][j] = map[i][j];
		}
	}
	return;
}
int IsValidEntry(Maze* m, Position entry)// 检测入口是否为有效入口 
{
	assert(m);
	if ((entry._x == 0 || entry._x == MAX_ROW - 1 ||
		entry._y == 0 || entry._y == MAX_COL - 1)&&(m->_map[entry._x][entry._y]==1))
		return 1;
	else return 0;
}

int IsNextPass(Maze* m, Position cur,Position next)// 检测cur位置是否是通路 
{
	//判断迷宫是否传入成功
	assert(m);
	if ((m->_map[next._x][next._y]==1)&&
		next._x<MAX_ROW&&next._x>=0&&
		next._y<MAX_COL&&next._y >= 0 
	   )return 1;

	if (m->_map[next._x][next._y]  > m->_map[cur._x][cur._y] &&
		next._x<MAX_ROW&&next._x >= 0 &&
		next._y<MAX_COL&&next._y >= 0
		)return 1;
	return 0;	
}

int IsExit(Maze* m,Position entry, Position cur)// 检测pCur是否在出口 
{
	assert(m);
	if ((cur._x == 0 || cur._x == MAX_ROW - 1 ||
		 cur._y == 0 || cur._y == MAX_COL - 1)&& 
		 (entry._x != cur._x || entry._y != cur._y)
		)
		return 1;
	else return 0;
}

int _PassMaze(Maze* m, Position entry, Position cur, Stack* Path, Stack* shortPath)// 真正走迷宫函数 
{
	assert(m);
	Position next;
	//next._x = cur._x, next._y = cur._y;
	if (!StackSize(Path))// 检测入口是否为有效入口
	{
		m->_map[cur._x][cur._y] = 2;	
	}
	StackPush(Path, cur);

	if (IsExit(m, entry, cur))
	{
		if (StackEmpty(shortPath))
			UndataPath(shortPath, Path);
		if (StackSize(Path) < StackSize(shortPath))
		{
			printf("当前可通过路径:");
			PrintShortPath(m, shortPath);
		}
			UndataPath(shortPath, Path);
		  //StackPop(Path);
	}
	
	//上
	next._x = cur._x - 1; next._y = cur._y ;
	if (IsNextPass(m,cur, next)) //检测下一步能否走成功
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		
		_PassMaze(m, entry, next, Path, shortPath);
	}
	//左
	 next._y = cur._y-1; next._x = cur._x;
	if (IsNextPass(m, cur,next)) //检测下一步能否走成功
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, Path, shortPath);
	}
	//右
	 next._y = cur._y+1; next._x = cur._x;
	if (IsNextPass(m, cur, next)) //检测下一步能否走成功
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, Path, shortPath);
	}
	//下
	next._x = cur._x+1; next._y = cur._y;
	if (IsNextPass(m, cur, next)) //检测下一步能否走成功
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, Path, shortPath);
	}
	StackPop(Path);
	return 0;
	
}

void PassMaze(Maze* m, Position entry, Stack* Path)// 提供给用户使用的走迷宫函数
{
	assert(m);
	Stack shortPath;
	StackInit(&shortPath, 20);
	StackInit(Path, 20);
	if (!IsValidEntry(m, entry))
	{
		printf("'.'入口在迷宫里面啊，我钻不进去'.'\n");
		return;
	}
	_PassMaze(m, entry, entry, Path,&shortPath);
	printf("最短路径:");
	 PrintShortPath(m, &shortPath);
	return;
	
}

void PrintMaze(Maze* m)
{
	assert(m);
	int i = 0, j = 0;
	for (; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			printf("%d ", m->_map[i][j]);
		}
		printf("\n");
	}
	return;
}
void PrintShortPath(Maze *m,Stack *shortPath)
{
	/*if (shortPath->_top>1)
	{
		shortPath->_top--;
		PrintShortPath(m, shortPath);
	}
	printf("%d,%d -> ", shortPath->_array[(shortPath->_top) - 1]._x, shortPath->_array[(shortPath->_top) - 1]._y);*/
	while (shortPath->_top)
	{
		if(shortPath->_top==1)
			printf("%d,%d ", shortPath->_array[(shortPath->_top) - 1]._x, shortPath->_array[(shortPath->_top) - 1]._y);
		else
		printf("%d,%d <- ", shortPath->_array[(shortPath->_top) - 1]._x, shortPath->_array[(shortPath->_top) - 1]._y);	
		shortPath->_top--;
	}
	printf("\n");

}
