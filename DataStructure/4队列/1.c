/*1、编写向顺序分配的循环队列QU[n]中插入一个结点x的函数EnQueue，
和从该队列中删除一个结点的函数DeQueue。*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}SeQueue;

void initQueue(SeQueue *sq);			/*初始化队列*/
bool EnQueue(SeQueue *sq,int e);		/*入队*/
bool DeQueue(SeQueue *sq,int *e);		/*出队*/
void TraverseQueue(SeQueue *sq);				/*遍历队列数据*/

int main()
{
	int val;
	int delData;
	int len,i,agoData;
	SeQueue *sq=(SeQueue *)malloc(sizeof(SeQueue));
	initQueue(sq);
	printf("请输入原循环对列的节点个数：\n");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("原循环对列第%d个节点：\n",i+1);
		scanf("%d",&agoData);
		EnQueue(sq, agoData);
	}
	printf("\n");
	
	printf("请输入要插入的节点的数据：\n");
	scanf("%d",&val);
	EnQueue(sq, val);
	DeQueue(sq, &delData);
	printf("\n删除的节点数据为：%d\n",delData);
	printf("\n循环队列变为了：\n");
	TraverseQueue(sq);
	printf("\n"); 
	return 0;
}

void initQueue(SeQueue *sq)				/*初始化队列*/
{
	sq->front = 0;
	sq->rear = 0;
}

bool EnQueue(SeQueue *sq,int e)			/*入队*/
{
	if(sq->front==((sq->rear+1)%MAXSIZE))
	{
		printf("队列已满\n");
		return false;
	}
	else
	{
		sq->data[sq->rear] = e;
		sq->rear = (sq->rear+1)%MAXSIZE;	/*rear指针后移*/
		return true;
	}
}

bool DeQueue(SeQueue *sq,int *e)		/*出队*/
{
	if(sq->front==sq->rear)
	{
		printf("队列为空\n");
		return false;
	}
	*e = sq->data[sq->front];			/*把出队列的元素存入指针e所指向的变量中*/
	sq->front=(sq->front+1)%MAXSIZE;	/*front指针后移*/ 
	return true;
}

void TraverseQueue(SeQueue *sq)
{
	if(sq->front==sq->rear)
	{
		printf("队列为空\n");
	}
	else
	{
		int i;
		i = sq->front;
		while(i != sq->rear)
		{
			printf("%d ",sq->data[i]);
			i = (i+1)%MAXSIZE;				/*i后移，即i++*/
		}
	}
	
}


