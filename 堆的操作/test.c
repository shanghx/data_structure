#include"Heap.h"
void test()
{

	return;
}
int main()
{
	Heap hp;
	int arr[] = { 53,17,78,9,45,65,87,23,31 };


	InitHeap(&hp);
	CreatHeap(&hp, arr, 9, Less);
	printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 10); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 9); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 8); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 7); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 6); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 5); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 4); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	InsertHeap(&hp, 3); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	/*DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));
	DeleteHeap(&hp); printf("�Ѷ�Ԫ��Ϊ:%d\n", GetHeapTop(&hp));*/
	system("pause");
	return 0;
}