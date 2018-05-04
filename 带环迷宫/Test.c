#include"Stack.h"
#include"Maze.h"
int main()
{
	int i = 0;
	Maze m;
	Stack Path;
	Position entry;
	entry._x = 4, entry._y = 1;
	int map[][MAX_COL] = { { 0, 0, 0, 0, 0, 0 },
						   { 0, 1, 1, 1, 0, 0 },
						   { 0, 1, 0, 1, 0, 0 },
						   { 0, 1, 0, 1, 1, 0 },
						   { 0, 1, 1, 1, 1, 1 },
						   { 0, 1, 0, 0, 0, 0 }
						 };
	InitMaze(&m, map);
	PrintMaze(&m);
	PassMaze(&m, entry, &Path);
	printf("\n");
	PrintMaze(&m);
	system("pause");
	return 0;
}