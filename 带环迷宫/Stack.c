#include"Stack.h"
//#include"Maze.h"

//非接口函数声明
void AddCapacity(Stack *s);//扩容函数
void PrintStack(Stack *s);//打印栈的元素
void AddCapacity(Stack *s)
{
	s->_array = (DataType*)realloc(s->_array, sizeof(DataType) * s->capacity * 2);
	if (s->_array == NULL)
	{
		printf("空间申请失败!!!\n");
		return;
	}
	s->capacity = s->capacity * 2;
	return;

}
void StackInit(Stack* s, int capacity)// 栈的初始化 
{
	assert(s);
	s->_array = (DataType*)malloc(sizeof(DataType) * capacity);
	if (s->_array == NULL)
	{
		printf("空间申请失败!!!\n");
		return;
	}
	s->capacity = capacity;
	s->_top = 0;
}


void StackPush(Stack* s, DataType data)// 入栈 
{
	assert(s);
	if (s->_top == s->capacity)
	{
		AddCapacity(s);
	}
	s->_array[s->_top] = data;

	s->_top++;
}

void StackPop(Stack* s)// 出栈 
{
	assert(s);
	if (s->_top == 0)
	{
		printf("栈空，无法出栈!!!\n");
		return;
	}
	s->_top--;
}


DataType StackTop(Stack* s)// 获取栈顶元素 
{
	assert(s);
	return s->_array[s->_top - 1];
}


int StackSize(Stack* s)// 获取栈中元素个数 
{
	assert(s);
	return s->_top;
}


int StackEmpty(Stack* s)// 检测栈是否为空 
{
	assert(s);
	if (s->_top == 0)
		return 1;
	else return 0;
}
void PrintStack(Stack *s)
{
	assert(s);
	while (s->_top)
	{
		printf("%d,%d",s->_array[(s->_top) - 1]._x , s->_array[(s->_top) - 1]._y);
		s->_top--;
	}
	printf("\n");
	return;
}