#include<stdio.h>
#include<stdlib.h>
typedef struct A                            //�����ṹ��
{
	int data;
	struct A * next;
}L;

L *Lahead, *pa, *p, *pc;                         //�������������ָ��
L *Lbhead, *pb, *Lchead;

int m = sizeof(L);                                 //����ṹ����ռ���ֽ�

void Labulid()                                       //����La����
{
	pa = (L*)malloc(m);
	Lahead = pa;                                          //�ȿ���һ���ռ��Pa,��headָ�������
	L * pBefore = NULL;	                                //�����ٶ���һ���ڵ�pBefore������ʱ�̶�ָ�����ָ����ָ��ڵ��ǰһ���ڵ�
	pa = (L*)malloc(m);                                      //�ٿ���һ���ڵ㣬��Ϊ����ĵĵ�һ���ڵ�,�����������һ��Ԫ��    
	Lahead->next = pa;
	printf("����������La��Ԫ�أ��ÿո��������'0'��������:\n");
	while (1)                                                 //ѭ����ʼ���������������'0'ʱ������ѭ��
	{
		scanf_s("%d", &pa->data);
		if (pa->data == 0)
		{
			free(pa);	                                    //�����������ǡ�0��ʱ���ͷŵ���ǰ�ڵ�
			break;
		}
		pBefore = pa;            //����������ݲ�Ϊ'0'ʱ�����õ�ǰ�ڵ㸳ֵ��PBefore,�ٿ���һ���µĿռ䣬��pa->nextָ�����µĽڵ㣬����paָ��pa->next,����ѭ��
		pa->next = (L*)malloc(m);
		pa = pa->next;
	}
	pBefore->next = NULL;                     //ѭ����������ʱPBeforeΪ�������һ���ڵ㣬������nextָ��NULL
}
/* ��������Lb,������La��ͬ��ע�Ͳο�La*/
void Lbbulid()
{
	pb = (L*)malloc(m);
	L * pBefore = NULL;
	Lbhead = pb;
	pb = (L*)malloc(m);
	Lbhead->next = pb;
	printf("����������Lb��Ԫ�أ��ÿո��������'0'��������:\n");
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
/*La�������*/
void Ladisplay()
{
	pa = Lahead->next; printf("A�����ݣ�");     //��paָ���һ���ڵ㣬ѭ���������������һ���ڵ㣬����ѭ��
	while (pa != NULL)
	{

		printf("%d ", pa->data);

		pa = pa->next;
	}
	printf("\n");
}
/*Lb�����������La�����Լ�ʵ�ַ�ʽ��ͬ*/
void Lbdisplay()
{
	pb = Lbhead->next; printf("B�����ݣ�");
	while (pb != NULL)
	{

		printf("%d ", pb->data);
		pb = pb->next;
	}
}
/* Lc�����������La�����Լ�ʵ�ַ�ʽ��ͬ */
void Lcdisplay()
{
	pc = Lchead->next;

	while (pc != NULL)
	{
		printf("%d ", pc->data);
		pc = pc->next;
	}
}
/* �ϲ����������������ϵĲ��� */
void merger()
{
	pa = Lahead->next; /* ����pa,pb��������ָ��ָ����Եĵ�һ���ڵ� */
	pb = Lbhead->next;
	Lchead = pc = Lahead;

	while (pa&&pb)    /* �ж����������Ԫ���Ƿ������*/ 
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
	/*  �ж���������Ԫ�ص�ֵ��С�����������,��La�е�Ԫ�ر�LbС��
	�򽫴�ʱLa�д�ʱ����ָ��ָ��Ľڵ����ӵ�Lc�ж�Ӧ�Ľڵ��next��
	��֮����Lb�еı���ָ��ָ��Ľڵ����ӵ�Lc��Ӧ�Ľڵ��next��
	��La��Lb�е�Ԫ����ȣ���La��Lb�еĽڵ����Ӹ�Lc��Ӧ�ڵ��next */
	if (pa->data < pb->data)/* ��һ����� */

	{
		/* �Ƚ�pc->nextָ���ʱԪ��ֵС�Ľڵ㣬����Lc�ı���ָ�����ƣ�ָ��pa;������La�ı���ָ�����ƣ��ж��¸��ڵ��ֵ�Ĵ�С*/
		pc->next = pa; pc = pa; pa = pa->next;
	}

	else
		if (pa->data == pb->data)
		{
			/* ����ֵ���ʱ��pc���¸��ڵ����������һ������ʱ��������ֵ��ȣ�����La��Lb�ı���ָ�붼Ҫ����*/
			pc->next = pa; pc = pa; pa = pa->next; pb = pb->next;
		}
		else
		{
			/* �þ�͵�һ��Ĺ�����ͬ��ֻ��pa����pb����Ϊ��ʱLb�е�Ԫ��ֵС*/
			pc->next = pb; pc = pb; pb = pb->next;
		}
}
/* ѭ��������˵����һ�������Ѿ����������ˣ�
��La������������Lb��ʣ��Ľڵ����ӵ�Lc,
��Lb������������La��ʣ��Ľڵ����ӵ�Lc*/
pc->next = pa ? pa : pb;
free(Lbhead);   //֮���ͷŵ�Lb��head�ڵ㣬��Ϊ����Lahead��ΪLc��head;
}

/*���������Ͻ�������,*/
void intersect()
{
	L *palast, *pblast;
	pa = Lahead->next; pb = Lbhead->next;
	Lchead = pc = Lahead;
	/* �жϣ�������������Ԫ��ֵ��ȣ���Lc������������*/
	
		while (pa)            //��La��Ϊ����,�������ͬ��Ԫ�أ��ͽ�La�з��ϵ�Ԫ����Lc������
		{
			while(pb)                        // ��Lb�б������ж�Ԫ���Ƿ���ͬ
			{ 
			if (pa->data == pb->data)
			{
				pc->next = pa; pc = pc->next;  break;                //�����ͬ����pc������ϣ�Ȼ��ֱ������ѭ�����ж��Ƿ�LΪ��
			}
			else
			{
				 pb = pb->next;
			}
			}
			if (pb == NULL)          //���Ϊ�� ���ͷŵ�La��ǰ�ڵ㣬Ȼ������ָ���¸��ڵ�
			{
				palast = pa;   pa = pa->next;  free(palast); pb = Lbhead->next;
			}
			else
			{
				pa = pa->next; pb = Lbhead->next;  //����  ˵������ͬ��Ԫ�أ���pc���Ӻ�ֱ����paָ���¸��ڵ㣬��������
			}
		}
		pc->next = NULL; //pb = Lbhead->next;             //�����pcd��nextָ��NULL
		/*while (pb->next  )
		{
			free(pb); pb = pb->next;
		}
		free(Lbhead); free(pb);*/
}

/* �������ϵĲ����              */

void disparity()
{
	L *palast=NULL, *pblast=NULL;
	pa = Lahead->next; pb = Lbhead->next;
	Lchead = pc = Lahead;
	while (pa && pb)                   //��whileѭ������ʼ����
	{
		if (pa->data < pb->data)
		{
			pc->next = pa; pc = pa;  pa = pa->next;   //����Ԫ�ز���ͬʱ����pc����������paֻ���¸��ڵ�
		}else
		if (pa->data == pb->data)
		{
			palast = pa; pblast = pb;pa = pa->next; pb = pb->next; free(palast); free(pblast);  //����ͬʱ���ͷŵ㵱ǰ�Ľڵ㣬Ȼ������¸��ڵ�
		}else
		
		{
			pc->next = pb; pc = pb; pb = pb->next;                         //����Ԫ�ز���ͬʱ����pc����������paֻ���¸��ڵ�
		}
		
	}/*����ѭ�����ĸ�����Ϊ�գ�������һ����������Lc��*/
	if (!pa)pc->next  = pb;                        
	if (!pb)pc->next = pa; free(Lbhead);
}
int main()                   //������
{
	/*������������������������*/
		Labulid();
		Lbbulid(); Ladisplay(); Lbdisplay(); merger(); printf("\n"); printf("�����ϵĲ���Ϊ:"); Lcdisplay(); printf("\n");
		Labulid();
		Lbbulid(); Ladisplay(); Lbdisplay(); intersect(); printf("\n"); printf("�����ϵĽ���Ϊ:"); Lcdisplay(); printf("\n");
		Labulid();
		Lbbulid(); Ladisplay(); Lbdisplay(); disparity(); printf("\n"); printf("�����ϵĲΪ:"); Lcdisplay(); printf("\n");
	system("pause");
	return 0;
}