#include "Heap.h"
//�ǽӿں�������


void AdjustDown(Heap *hp, int parent, Compare com);

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
void AdjustDown(Heap *hp, int parent, Compare com)
{
	int child = 0;
	child = (parent << 1) + 1;   //Ĭ������ʱ������������С��һ��

								 //����Һ���С�����ӣ���ô���Һ��ӱ��Ϊchild
	if ((child + 1 < hp->_size) && hp->com(child + 1, child))
		child += 1;
	//�����жϺ��Ӻ�˫�׵Ĵ�С
	while (child<(hp->_size))
	{
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
		AdjustDown(hp, root, com);
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

	parent = ((child - 1) >> 1);   //�ҵ���˫��
	while (child)
	{
		if (hp->com(child, parent))   //������ӱ�˫��С������
		{
			Swap(&hp->array[child], &hp->array[parent]);
		}
		child = parent;
		parent = ((child - 1) >> 1);
	}
}
void DeleteHeap(Heap *hp)                           //ɾ��Ԫ��
{
	assert(hp);
	int child = 0;

	//����:�Ƚ����һ���ͶѶ�Ԫ�ؽ�����֮���ٵ����Ѷ�Ԫ�ص�λ��	
	child = hp->_size - 1;

	Swap(&hp->array[child], &hp->array[0]);
	--hp->_size;

	AdjustDown(hp, 0, hp->com);

}
// void DestoryHeap(Heap *hp);             //���ٶ�
DataType GetHeapTop(Heap *hp)         //��ȡ���еĶѶ�Ԫ��
{
	assert(hp);
	return hp->array[0];

}