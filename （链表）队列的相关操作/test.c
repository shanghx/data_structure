
#include"Queue.h"
int main()
{
	
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1); QueuePush(&q, 2); QueuePush(&q, 3); QueuePush(&q, 4);  QueuePush(&q, 5);	QueuePrint(&q);
	printf("%d\n", QueuePop(&q)); printf("%d\n ", QueuePop(&q));
	QueuePrint(&q); printf("%d", QueueSize(&q)); QueueDestory(&q); 
	system("pause");
	return 0;
}
