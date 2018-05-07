#include"Queue.h"
PQNode BuyQueueNode(QDataType data)
{
	PQNode pNewNode = (PQNode)malloc(sizeof(QNode));
	if (pNewNode == NULL)
	{
		assert(pNewNode);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->p_next = NULL;
	return pNewNode;
}
void QueueInit(Queue *q)//���г�ʼ��
{
	assert(q);
	q->front = (PQNode)malloc(sizeof(QNode));
	q->front->p_next = NULL; q->front->data = NULL;
	q->rear = q->front;
}
void QueuePush(Queue *q,QDataType data) //���
{
	assert(q);
	if (q->front->p_next==NULL)
	{
		q->front->p_next = BuyQueueNode(data);
		q->rear = q->front->p_next;
	}
	else
	{
		q->rear->p_next = BuyQueueNode(data);
		q->rear = q->rear->p_next;
	}
	
	
}
QDataType QueuePop(Queue *q) //����
{
	QDataType message;
	assert(q);
	PQNode pCur=NULL ;
	if (QueueEmpty(q))
		return NULL;
	pCur = q->front->p_next;message = pCur->data;
	q->front->p_next = pCur->p_next ;
	free(pCur);
	pCur = NULL;
	return message;
}

int QueueEmpty(Queue *q) //�ж϶����Ƿ�Ϊ�� 
{
	assert(q);
	if (!(q->front ->p_next))
		return 1;
	else return 0;
}
int QueueSize(Queue *q)//��ȡ�ӵ���ЧԪ�صĳ���
{
	assert(q);
	int count = 0;
	PQNode pCur = NULL;
	if (QueueEmpty(q))
		return 0;
	pCur = q->front->p_next;
	while (pCur != q->rear)
	{
		count++;
		pCur = pCur->p_next;	
	}
	return count;
	
}
void QueueDestory(Queue *q)//���ٶ���
{
	assert(q);
	PQNode pCur = NULL;
	assert(q);
	if (QueueEmpty(q))
	{	
		free(q->front);
		q->front = NULL;
		return;
	}
	
	while(q->front->p_next)
	{
		pCur = q->front->p_next;
		q->front->p_next = pCur->p_next;
		free(pCur);
		pCur = NULL;	
	}
	free(q->front);
	q->front = NULL;

}
void QueuePrint(Queue *q)
{
	if (QueueEmpty(q))
		return;
	PQNode pCur = NULL;
	pCur = q->front->p_next;
	while (pCur)
	{
		printf("%d ", pCur->data);
		pCur = pCur->p_next;
	}
	printf("\n");
	return;
}