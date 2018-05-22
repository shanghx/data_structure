
#include<stdio.h>
#include<stdlib.h>
typedef int Selemtype ;
typedef struct stack                     //定义结构体
{
	Selemtype data;
	struct stack *link;
}sqstack;
 sqstack*p,*q, *top, *base;                   //定义需要的指针
 int m = sizeof(sqstack);
 /*建立链表栈*/
void Initstack()
{
	
	p =(sqstack*)malloc(m);             //开辟两个空间，分别给p,q,让top链接上base
	base=p;
	p = (sqstack*)malloc(m);
	top = p;
	top->link = base;
} 
/*s压入栈函数*/
void push(Selemtype &a)
{
	p = (sqstack*)malloc(m);//下班开辟一个空间
	
	
	if (!p) exit(0);
	else
	{
			p->link  = top;                   //之前的top就成为栈的一个节点，让新开辟的空间为top
		top->data = a;  top = p; 
	}	
}
/*   压出栈  */
Selemtype  pop()
{
	p = top->link;                                      // 先让p指向栈的第一个元素节点
	Selemtype n;
	if (top->link==base) exit(0);
	else
	{
		n = p->data; q = p; p = p->link; top->link = p;             //先先把药压出的节点的值存起来，让p节点下移，之后让top->link指向第一个元素节点
		free(q); return (n);
	}
}
/*  输出函数*/
void print()
{
	q = top->link ;
	while (q != base)            //栈不为空时，打印出节点元素的值
	{
		printf("%d", q->data);
		q = q->link;
	}
	
}
/*求八进制函数*/
void conversion()
{
	int N,j,e;
	Initstack();
	scanf_s("%d", &N);         //输入要转换的数
	while (N)
	{
		j = N % 8;               //先求余数
		push(j);               //计算后压入栈
		N = N / 8;          //再取整数
	}
	while (top->link != base)
	{
		e=pop();
		printf("%d ",e);                  //打印出压入栈的元素

	}
	
}
/*主函数*/
int main()
{
	printf("请输入要转换的数：");
	conversion();
	system("pause");
	return 0;
}