
#include<stdio.h>
#include<stdlib.h>
typedef int Selemtype ;
typedef struct stack                     //����ṹ��
{
	Selemtype data;
	struct stack *link;
}sqstack;
 sqstack*p,*q, *top, *base;                   //������Ҫ��ָ��
 int m = sizeof(sqstack);
 /*��������ջ*/
void Initstack()
{
	
	p =(sqstack*)malloc(m);             //���������ռ䣬�ֱ��p,q,��top������base
	base=p;
	p = (sqstack*)malloc(m);
	top = p;
	top->link = base;
} 
/*sѹ��ջ����*/
void push(Selemtype &a)
{
	p = (sqstack*)malloc(m);//�°࿪��һ���ռ�
	
	
	if (!p) exit(0);
	else
	{
			p->link  = top;                   //֮ǰ��top�ͳ�Ϊջ��һ���ڵ㣬���¿��ٵĿռ�Ϊtop
		top->data = a;  top = p; 
	}	
}
/*   ѹ��ջ  */
Selemtype  pop()
{
	p = top->link;                                      // ����pָ��ջ�ĵ�һ��Ԫ�ؽڵ�
	Selemtype n;
	if (top->link==base) exit(0);
	else
	{
		n = p->data; q = p; p = p->link; top->link = p;             //���Ȱ�ҩѹ���Ľڵ��ֵ����������p�ڵ����ƣ�֮����top->linkָ���һ��Ԫ�ؽڵ�
		free(q); return (n);
	}
}
/*  �������*/
void print()
{
	q = top->link ;
	while (q != base)            //ջ��Ϊ��ʱ����ӡ���ڵ�Ԫ�ص�ֵ
	{
		printf("%d", q->data);
		q = q->link;
	}
	
}
/*��˽��ƺ���*/
void conversion()
{
	int N,j,e;
	Initstack();
	scanf_s("%d", &N);         //����Ҫת������
	while (N)
	{
		j = N % 8;               //��������
		push(j);               //�����ѹ��ջ
		N = N / 8;          //��ȡ����
	}
	while (top->link != base)
	{
		e=pop();
		printf("%d ",e);                  //��ӡ��ѹ��ջ��Ԫ��

	}
	
}
/*������*/
int main()
{
	printf("������Ҫת��������");
	conversion();
	system("pause");
	return 0;
}