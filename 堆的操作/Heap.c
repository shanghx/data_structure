#include "Heap.h"
//�ǽӿں�������


void AdjustDown(Heap *hp, int parent);

int CheckHeap(Heap *hp);

void Swap(int *a, int *b);
DataType * AddCapatipy(Heap* hp);

//����ʵ�ֲ���
int Greater(DataType left, DataType right)
{
	return left > right;
}
int Less(DataType left, DataType right)
{
	return left<right;
}
int CheckHeap(Heap *hp)
{
	assert(hp);
	if (hp->capacity == hp->_size)  //��ЧԪ�غ��������ʱ���Ѿ���
		return 1;
	else return 0;
}
DataType * AddCapatipy(Heap* hp)
{
	assert(hp);

	DataType *pCur = NULL;


	//1.ʹ��malloc����(1.�����¿ռ�   2.�������ݸ��¿ռ�  3.�ͷžɿռ�
	pCur = (DataType*)malloc(sizeof(DataType)*hp->capacity * 2);
	if (pCur == NULL)
	{
		assert(pCur);
		return NULL;
	}
	hp->capacity = hp->capacity * 2;
	int i = 0;
	for (; i < hp->_size; ++i)
	{
		pCur[i] = hp->array[i];
	}
	free(hp->array);
	hp->array = pCur;
	return hp->array;
#if 0
	//2.ʹ��relloc����
	hp->array = (DataType*)realloc(hp->array, sizeof(DataType)*hp->capacity * 2);
	if (hp->array == NULL)
	{
		assert(hp->array);
		return NULL;
	}
	hp->capacity = hp->capacity * 2;
	return hp->array;
#endif
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustDown(Heap *hp, int parent)
{
	int child = 0;
	child = (parent << 1) + 1;   //Ĭ������ʱ������������С��һ��

	
	//�����жϺ��Ӻ�˫�׵Ĵ�С
	while (child<(hp->_size))
	{
		//����Һ���С�����ӣ���ô���Һ��ӱ��Ϊchild
		if ((child + 1 < hp->_size) && hp->com(hp->array[child + 1], hp->array[child]))
			child += 1;
		if (hp->com(hp->array[child], hp->array[parent]))  //���˫�ױȺ��Ӵ󣬴�ʱ��������ֵ
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//֮�󣬵���parent��child��ֵ
			parent = child;
			child = ((parent << 1) + 1);
		}
		else return;
		//��childС�ڶ���ЧԪ�ظ���ʱ��˵�����µ������
	}
}
void AdjustUp(Heap *hp, int child)
{
	assert(hp);
	int parent = 0;
	parent = ((child - 1) >> 1);
	while (child)
	{
		if (hp->com(hp->array[child], hp->array[parent]))
		{
			Swap(&hp->array[child], &hp->array[parent]);
			child = parent;
			parent = parent = ((child - 1) >> 1);
		}
		
		else return;
	}
	

}
void InitHeap(Heap *hp)     //�ѵĳ�ʼ��
{
	assert(hp);
	hp->array = (DataType*)malloc(sizeof(DataType) * 3);
	if (hp->array == NULL)
	{
		assert(hp->array);
		return;
	}
	hp->capacity = 3;
	hp->_size = 0;
}
void CreatHeap(Heap *hp, DataType *array, int size, Compare com)   //������
{
	assert(hp);
	assert(array);
	hp->com = com;
	int root = 0;  //�������ÿ�ε����Ľ��
	hp->array = (DataType*)malloc(sizeof(DataType)*size);  //���ٺ������С��ȵĿռ�
	hp->capacity = size;
	int i = 0;

	//1.���ѵ�ÿ����㸳ֵ
	for (; i < size; ++i)
	{
		hp->array[i] = array[i];
	}


	hp->_size = size;  //�ı�ѵ���ЧԪ�ظ���

					   //2.�����ѵ�Ԫ�أ�ʹ������Ե�����
					   //���ȣ��ҵ��ѵĵ�һ����Ҷ�ӽڵ㣬Ȼ��ʼ���ϵ���

	root = (hp->_size - 1 - 1) >> 1;  //�������һ����Ҷ�ӽ��
									  //Ȼ��ѭ�����ε���rootǰ��ÿ�����
	for (; root >= 0; --root)
	{
		AdjustDown(hp, root);
	}
	//����һ����˵�����Ѿ���������
	return;
}
void InsertHeap(Heap *hp, DataType data)            //����Ԫ��
{
	int parent = 0;
	int child = 0;
	assert(hp);
	//������1.�Ƚ�Ҫ�����Ԫ�ز��뵽�ѵ����һ��λ�ã������ϵ�������Ԫ�ص�λ��

	//����֮ǰ���ȼ����Ƿ�����
	if (CheckHeap(hp))
	{
		AddCapatipy(hp);  //����
	}
	hp->array[hp->_size] = data;
	hp->_size++;
	child = hp->_size - 1;   //�ҳ����һ������

	AdjustUp(hp, child);
}
void DeleteHeap(Heap *hp)                           //ɾ��Ԫ��
{
	assert(hp);
	int child = 0;
	//����:�Ƚ����һ���ͶѶ�Ԫ�ؽ�����֮���ٵ����Ѷ�Ԫ�ص�λ��	
	child = hp->_size - 1;

	Swap(&hp->array[child], &hp->array[0]);
	--hp->_size;

	AdjustDown(hp, 0);

}
// void DestoryHeap(Heap *hp);             //���ٶ�
DataType GetHeapTop(Heap *hp)         //��ȡ���еĶѶ�Ԫ��
{
	assert(hp);
	if (!EmptyHeap(hp))
	
		return hp->array[0];
	else
	{
		assert(0);
		return -1;
	}	

}
int CountHeap(Heap *hp)       //��ȡ�ѵ���Ԫ�ظ���
{
	assert(hp);
	return hp->_size;
	
}
int EmptyHeap(Heap *hp)            //�ж϶��Ƿ�Ϊ��
{
	assert(hp);
	if (hp->_size == 0)
		return 1;
	else return 0;
}
void DestoryHeap(Heap *hp)   //���ٶ�
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->_size = 0;
	return;
}