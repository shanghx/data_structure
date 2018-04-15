#include<stdio.h>
#include<stdlib.h>
typedef struct A                            //建立结构体
{
	int data;
	struct A * next;
}L;

L *Lahead, *pa, *p, *pc;                         //定义两个链表的指针
L *Lbhead, *pb, *Lchead;

int m = sizeof(L);                                 //计算结构体所占的字节

void Labulid()                                       //建立La链表
{
	pa = (L*)malloc(m);
	Lahead = pa;                                          //先开辟一个空间给Pa,让head指向该区域
	L * pBefore = NULL;	                                //接着再定义一个节点pBefore，让它时刻都指向遍历指针所指向节点的前一个节点
	pa = (L*)malloc(m);                                      //再开辟一个节点，作为链表的的第一个节点,里面存放链表第一个元素    
	Lahead->next = pa;
	printf("请连续输入La的元素，用空格隔开，按'0'结束输入:\n");
	while (1)                                                 //循环开始，当输入的数据是'0'时，跳出循环
	{
		scanf_s("%d", &pa->data);
		if (pa->data == 0)
		{
			free(pa);	                                    //当输入数据是‘0’时，释放掉当前节点
			break;
		}
		pBefore = pa;            //当输入的数据不为'0'时，先让当前节点赋值给PBefore,再开辟一个新的空间，让pa->next指向下新的节点，再让pa指向pa->next,继续循环
		pa->next = (L*)malloc(m);
		pa = pa->next;
	}
	pBefore->next = NULL;                     //循环结束，此时PBefore为链表最后一个节点，让它的next指向NULL
}
/* 建立链表Lb,方法和La相同，注释参考La*/
void Lbbulid()
{
	pb = (L*)malloc(m);
	L * pBefore = NULL;
	Lbhead = pb;
	pb = (L*)malloc(m);
	Lbhead->next = pb;
	printf("请连续输入Lb的元素，用空格隔开，按'0'结束输入:\n");
	while (1)
	{
		scanf_s("%d", &pb->data);
		if (pb->data == 0) {

			free(pb);
			break;
		}
		pb->next = (L*)malloc(m);
		pBefore = pb;
		pb = pb->next;

	}
	pBefore->next = NULL;
}
/*La输出函数*/
void Ladisplay()
{
	pa = Lahead->next; printf("A组数据：");     //让pa指向第一个节点，循环，当遍历到最后一个节点，跳出循环
	while (pa != NULL)
	{

		printf("%d ", pa->data);

		pa = pa->next;
	}
	printf("\n");
}
/*Lb输出函数，和La作用以及实现方式相同*/
void Lbdisplay()
{
	pb = Lbhead->next; printf("B组数据：");
	while (pb != NULL)
	{

		printf("%d ", pb->data);
		pb = pb->next;
	}
}
/* Lc输出函数，和La作用以及实现方式相同 */
void Lcdisplay()
{
	pc = Lchead->next;

	while (pc != NULL)
	{
		printf("%d ", pc->data);
		pc = pc->next;
	}
}
/* 合并函数，求两个集合的并集 */
void merger()
{
	pa = Lahead->next; /* 先让pa,pb两个遍历指针指向各自的第一个节点 */
	pb = Lbhead->next;
	Lchead = pc = Lahead;

	while (pa&&pb)    /* 判断两个链表的元素是否遍历完*/ 
	{
		/*if (pa->data>pb->data)
		{
			pc = pb->next;
			pb->next = Lahead->next;
			Lahead->next = pb;
			Lahead = Lahead->next;
			pb = pc;
		}
		else
			if ((pa->data) < pb->data)
			{
				Lahead = Lahead->next;
				pa = Lahead->next;
			}
			else if ((pa->data) == pb->data)
			{
				pb = pb->next;
			}
	}*/
	if (pa == NULL) Lahead->next = pb;
	/*  判断两个链表元素的值大小，共三种情况,若La中的元素比Lb小，
	则将此时La中此时遍历指针指向的节点连接到Lc中对应的节点的next，
	反之，将Lb中的遍历指针指向的节点连接到Lc对应的节点的next，
	若La和Lb中的元素相等，则将La或Lb中的节点连接给Lc对应节点的next */
	if (pa->data < pb->data)/* 第一种情况 */

	{
		/* 先将pc->next指向此时元素值小的节点，再让Lc的遍历指针下移，指向pa;继续让La的遍历指针下移，判断下个节点的值的大小*/
		pc->next = pa; pc = pa; pa = pa->next;
	}

	else
		if (pa->data == pb->data)
		{
			/* 当两值相等时，pc的下个节点可以是任意一个，此时由于两个值相等，所以La和Lb的遍历指针都要下移*/
			pc->next = pa; pc = pa; pa = pa->next; pb = pb->next;
		}
		else
		{
			/* 该句和第一句的功能相同，只把pa换成pb，因为此时Lb中的元素值小*/
			pc->next = pb; pc = pb; pb = pb->next;
		}
}
/* 循环跳出后，说明有一个链表已经遍历结束了，
若La遍历结束，则将Lb中剩余的节点连接到Lc,
若Lb遍历结束，则将La中剩余的节点连接到Lc*/
pc->next = pa ? pa : pb;
free(Lbhead);   //之后，释放掉Lb的head节点，因为是用Lahead作为Lc的head;
}

/*求两个集合交集函数,*/
void intersect()
{
	L *palast, *pblast;
	pa = Lahead->next; pb = Lbhead->next;
	Lchead = pc = Lahead;
	/* 判断，若两个链表中元素值相等，用Lc将它们连起来*/
	
		while (pa)            //以La作为基础,如果有相同的元素，就将La中符合的元素用Lc连起来
		{
			while(pb)                        // 从Lb中遍历，判断元素是否相同
			{ 
			if (pa->data == pb->data)
			{
				pc->next = pa; pc = pc->next;  break;                //如果相同，用pc将其接上，然后直接跳出循环，判断是否L为空
			}
			else
			{
				 pb = pb->next;
			}
			}
			if (pb == NULL)          //如果为空 ，释放掉La当前节点，然后让其指向下个节点
			{
				palast = pa;   pa = pa->next;  free(palast); pb = Lbhead->next;
			}
			else
			{
				pa = pa->next; pb = Lbhead->next;  //否则  说明有相同的元素，让pc连接后，直接让pa指向下个节点，继续遍历
			}
		}
		pc->next = NULL; //pb = Lbhead->next;             //最后让pcd的next指向NULL
		/*while (pb->next  )
		{
			free(pb); pb = pb->next;
		}
		free(Lbhead); free(pb);*/
}

/* 两个集合的差集函数              */

void disparity()
{
	L *palast=NULL, *pblast=NULL;
	pa = Lahead->next; pb = Lbhead->next;
	Lchead = pc = Lahead;
	while (pa && pb)                   //用while循环，开始遍历
	{
		if (pa->data < pb->data)
		{
			pc->next = pa; pc = pa;  pa = pa->next;   //当有元素不相同时，用pc连接起来，pa只想下个节点
		}else
		if (pa->data == pb->data)
		{
			palast = pa; pblast = pb;pa = pa->next; pb = pb->next; free(palast); free(pblast);  //当相同时，释放点当前的节点，然后遍历下个节点
		}else
		
		{
			pc->next = pb; pc = pb; pb = pb->next;                         //当有元素不相同时，用pc连接起来，pa只想下个节点
		}
		
	}/*跳出循环后，哪个链表为空，则将另外一个链表连在Lc上*/
	if (!pa)pc->next  = pb;                        
	if (!pb)pc->next = pa; free(Lbhead);
}
int main()                   //主函数
{
	/*建立三次链表，测试三个函数*/
		Labulid();
		Lbbulid(); Ladisplay(); Lbdisplay(); merger(); printf("\n"); printf("两集合的并集为:"); Lcdisplay(); printf("\n");
		Labulid();
		Lbbulid(); Ladisplay(); Lbdisplay(); intersect(); printf("\n"); printf("两集合的交集为:"); Lcdisplay(); printf("\n");
		Labulid();
		Lbbulid(); Ladisplay(); Lbdisplay(); disparity(); printf("\n"); printf("两集合的差集为:"); Lcdisplay(); printf("\n");
	system("pause");
	return 0;
}