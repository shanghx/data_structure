#define _CRT_SECURE_NO_WARNINGS  1
#include"�ؼ�·��.h"

/*����ͼ�ж����Ӧ��λ�ú���*/
int LocateVex(ALGraph G, VertexType v)
{
	int i = 0;
	for (i = 0; i<G.vernum; i++)
	{
		if (strcmp(G.vertex[i].data, v) == 0) return  i;
		 return -1;
	}
}
void CreatGraph(ALGraph *G)
{
	ArcNode *p;
	VertexType v1, v2;
	//int weight, m, n; int i , j ;
	int i, j, k, w;
	cout << "�����붥��ͱߵĸ���,�ÿո����:";
	cin >> G->vernum >> G->arcnum;
	cout << endl<<"������"<<G->vernum<<"���������Ϣ\n";
	for (i = 0; i < G->vernum; i++)               //���붥�����Ϣ
	{
		//cin >> G->vertex[i].data;
		scanf("%s", G->vertex[i].data);
		G->vertex[i].firstarc = NULL;
	}
	cout << "�����뻡����Ϣ(��ͷ ��β Ȩ��)\n";
	for (k = 0; k < G->arcnum; k++)                 //���뻡����Ϣ
	{
		//fflush(stdin);
		/*cin >> v1;
		cin >> v2;
		cin>> weight;*/
		scanf("%s%s%*c%d", v1, v2, &w);
		i = LocateVex(*G, v1);
		j = LocateVex(*G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = (InfoType*)malloc(sizeof(InfoType));
		*(p->info) = w; //cout << *(p->info);
		p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = p;
	}
	//(*G).kind = DN;
}
	
void DestoryGraph(ALGraph *G)
{
	int i; ArcNode *p, *q;
	for (i = 0; i < G->vernum; i++)
	{
		p = G->vertex[i].firstarc;
		if (p != NULL)
		{
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	(*G).vernum = 0;
	(*G).arcnum = 0;
}
void PrintGraph(ALGraph &G)
{
	int i = 0;
	ArcNode *p;
	//cout << "��������" << G.vernum << "������" << endl;
	for (i = 0; i < G.vernum; i++)
	{
	//	cout << G.vertex[i].data << " ";
	}
//	cout << "��������" << G.arcnum  << "����" << endl;
	for (i = 0; i < G.vernum ; i++)
	{
		p = G.vertex[i].firstarc;
		while (p)
		{
			//cout << G.vertex[i].data << " " << G.vertex[p->adjvex].data << " " << *(p->info);
			p = p->nextarc;
		}
		//cout << endl;
	}
}
int CriticalPath(ALGraph &G)
{
	int i, k, e, l;
	int * Ve, *Vl;
	ArcNode * p;

	//*****************************************    
	//��������ʱ�����緢��ʱ��    
	//*****************************************    

	Ve = new int[G.vernum];
	Vl = new int[G.vernum];

	for (i = 0; i < G.vernum; i++)              //ǰ��    
		Ve[i] = 0;

	for (i = 0; i < G.vernum; i++)
	{
		ArcNode * p = G.vertex[i].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;
			if (Ve[i] + *(p->info )> Ve[k])
				Ve[k] = Ve[i] + *(p->info);
			p = p->nextarc;
		}
	}
	//*****************************************    
	//����������ٷ���ʱ��    
	//*****************************************    
	for (i = 0; i < G.vernum; i++)
		Vl[i] = Ve[G.vernum - 1];
	for (i = G.vernum - 2; i >= 0; i--)                 //����    
	{
		p = G.vertex[i].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;
			if (Vl[k] - *(p->info) < Vl[i])
				Vl[i] = Vl[k] -*( p->info);
			p = p->nextarc;
		}
	}
	//******************************************    
	for (i = 0; i < G.vernum; i++)
	{
		p = G.vertex[i].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;
			e = Ve[i];              //���翪ʼʱ��Ϊʱ��vi�����緢��ʱ��    
			l = Vl[k] - *(p->info);             //��ٿ�ʼʱ��    
			char tag = (e == l) ? '*' : ' '; //�ؼ��    
			//cout<< G.vertex[i].data<<" "<<G.vertex[k].data<<" "<<e<<" "<<l<<" "<<tag;
			p = p->nextarc;
		}
	}
	//delete[] Ve;
	//delete[] Vl;
	return 0;
}
int main()
{
	ALGraph N;
	CreatGraph(&N); //DestoryGraph(&N);
	//PrintGraph(N);
	//CriticalPath(N);
	system("pause");
	return 0;
}