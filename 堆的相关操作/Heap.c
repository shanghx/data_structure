#include "Heap.h"
//非接口函数声明


void AdjustDown(Heap *hp, int parent, Compare com);

int CheckHeap(Heap *hp);

void Swap(int *a, int *b);
DataType * AddCapatipy(Heap* hp);

//函数实现部分
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
	if (hp->capacity == hp->_size)  //有效元素和容量相等时，堆就满
		return 1;
	else return 0;
}
DataType * AddCapatipy(Heap* hp)
{
	assert(hp);

	DataType *pCur = NULL;


	//1.使用malloc增容(1.开辟新空间   2.复制内容给新空间  3.释放旧空间
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
	//2.使用relloc增容
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
	child = (parent << 1) + 1;   //默认左孩子时两个孩子中最小的一个

								 //如果右孩子小于左孩子，那么将右孩子标记为child
	if ((child + 1 < hp->_size) && hp->com(child + 1, child))
		child += 1;
	//下面判断孩子和双亲的大小
	while (child<(hp->_size))
	{
		if (hp->com(hp->array[child], hp->array[parent]))  //如果双亲比孩子大，此时交换两个值
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//之后，调整parent和child的值
			parent = child;
			child = ((parent << 1) + 1);
		}
		else return;
		//当child小于堆有效元素个数时，说明向下调整完成
	}
}
void InitHeap(Heap *hp)     //堆的初始化
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
void CreatHeap(Heap *hp, DataType *array, int size, Compare com)   //创建堆
{
	assert(hp);
	assert(array);
	hp->com = com;
	int root = 0;  //用来存放每次调整的结点
	hp->array = (DataType*)malloc(sizeof(DataType)*size);  //开辟和数组大小相等的空间
	hp->capacity = size;
	int i = 0;

	//1.给堆的每个结点赋值
	for (; i < size; ++i)
	{
		hp->array[i] = array[i];
	}


	hp->_size = size;  //改变堆的有效元素个数

					   //2.调整堆的元素，使其满足对的属性
					   //首先，找到堆的第一个非叶子节点，然后开始向上调整

	root = (hp->_size - 1 - 1) >> 1;  //计算出第一个非叶子结点
									  //然后循环依次调整root前面每个结点
	for (; root >= 0; --root)
	{
		AdjustDown(hp, root, com);
	}
	//到这一步，说明堆已经创建好了
	return;
}
void InsertHeap(Heap *hp, DataType data)            //插入元素
{
	int parent = 0;
	int child = 0;
	assert(hp);
	//方法：1.先将要插入的元素插入到堆的最后一个位置，再向上调整插入元素的位置

	//插入之前，先检测堆是否满了
	if (CheckHeap(hp))
	{
		AddCapatipy(hp);  //扩容
	}
	hp->array[hp->_size] = data;
	hp->_size++;
	child = hp->_size - 1;   //找出最后一个孩子

	parent = ((child - 1) >> 1);   //找到其双亲
	while (child)
	{
		if (hp->com(child, parent))   //如果孩子比双亲小，交换
		{
			Swap(&hp->array[child], &hp->array[parent]);
		}
		child = parent;
		parent = ((child - 1) >> 1);
	}
}
void DeleteHeap(Heap *hp)                           //删除元素
{
	assert(hp);
	int child = 0;

	//方法:先将最后一个和堆顶元素交换，之后再调整堆顶元素的位置	
	child = hp->_size - 1;

	Swap(&hp->array[child], &hp->array[0]);
	--hp->_size;

	AdjustDown(hp, 0, hp->com);

}
// void DestoryHeap(Heap *hp);             //销毁堆
DataType GetHeapTop(Heap *hp)         //获取堆中的堆顶元素
{
	assert(hp);
	return hp->array[0];

}