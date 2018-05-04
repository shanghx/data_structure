#include"Stack.h"
//#include"Maze.h"

//�ǽӿں�������
void AddCapacity(Stack *s);//���ݺ���
void PrintStack(Stack *s);//��ӡջ��Ԫ��
void AddCapacity(Stack *s)
{
	s->_array = (DataType*)realloc(s->_array, sizeof(DataType) * s->capacity * 2);
	if (s->_array == NULL)
	{
		printf("�ռ�����ʧ��!!!\n");
		return;
	}
	s->capacity = s->capacity * 2;
	return;

}
void StackInit(Stack* s, int capacity)// ջ�ĳ�ʼ�� 
{
	assert(s);
	s->_array = (DataType*)malloc(sizeof(DataType) * capacity);
	if (s->_array == NULL)
	{
		printf("�ռ�����ʧ��!!!\n");
		return;
	}
	s->capacity = capacity;
	s->_top = 0;
}


void StackPush(Stack* s, DataType data)// ��ջ 
{
	assert(s);
	if (s->_top == s->capacity)
	{
		AddCapacity(s);
	}
	s->_array[s->_top] = data;

	s->_top++;
}

void StackPop(Stack* s)// ��ջ 
{
	assert(s);
	if (s->_top == 0)
	{
		printf("ջ�գ��޷���ջ!!!\n");
		return;
	}
	s->_top--;
}


DataType StackTop(Stack* s)// ��ȡջ��Ԫ�� 
{
	assert(s);
	return s->_array[s->_top - 1];
}


int StackSize(Stack* s)// ��ȡջ��Ԫ�ظ��� 
{
	assert(s);
	return s->_top;
}


int StackEmpty(Stack* s)// ���ջ�Ƿ�Ϊ�� 
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