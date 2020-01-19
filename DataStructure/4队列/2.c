#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<malloc.h>
typedef int DataType; 		
#define MAXNUM 20 			/*队列中最大元素个数*/
#define ERROR 1

typedef struct LQNode
{
	DataType info;
	struct LQNode *next;
}LQNode; 					/*队列的元素类型*/

typedef struct
{ 
	LQNode *rear,*front; 	/*队尾、队头指针*/
}LinkQueue;					/*队列类型*/

LinkQueue *LQueueCreateEmpty();/*创造空队列*/
bool LQueueIsEmpty(LinkQueue *LQ);/*判队空函数*/
void LQueueEnQueue(LinkQueue *LQ,DataType x);/*入队*/
void LQueueDeQueue(LinkQueue *LQ,DataType *x);/*出队:将队头元素出队，并由x带回队头元素信息*/
DataType LQueueFront(LinkQueue *LQ);
void MyEnQueue(LinkQueue *ql,LinkQueue *q2,DataType d,int priority);
DataType MyDeQueue(LinkQueue *ql,LinkQueue *q2);

int main()
{
	LinkQueue *q1;			/*优先级低的病人队列*/
	LinkQueue *q2;			/*优先级高的病人队列*/
 	int menu;				/*存储用户选择的菜单编号*/
 	int priority;			/*病人看病的优先级别*/
 	DataType id;			/*按照病人到达医院的先后领取号码牌*/
	DataType e;				/*病人看病的优先级别*/
	int n=0;
	q1=LQueueCreateEmpty();
	q2=LQueueCreateEmpty();
 	id=1;
	printf("****************欢迎进入排队看病模拟系统*******\n");
	printf("*********1：新的病人力加入队列候诊 ********\n");
	printf("*********2：医生根据优先级别为病人诊治*****\n");
	printf("*********3：退出系统 **********************\n");
	printf("**********************************************\n");
	while(1)
	{
		printf("\n一一一一一一一一一一一一一一一一一一一一一一一一一一一一一\n");
		printf("******请按菜单编号选择相应的操作(系统只处理数值型数据):******\n");
		scanf("%d",&menu);
		while(menu>3||menu<1)
		{ 					/*如果输入格式错误不为空*/
			printf("\n输入错误，请按菜单编号输入:");
			scanf("%d",&menu);
		}
		switch(menu)
		{
			case 1: 		/*如果有新的病人，则加入队列*/
				printf("请输入病人的优先级别(本模拟系统只设置两个优先级别：1或2(2优先))\n");
	 			scanf("%d",&priority);
	 			if(1==priority || 2==priority) 	/*如果级别输入的正确*/
	 			{
	 				printf("***该病人的ID为：%d***\n",id);
			 		MyEnQueue(q1,q2,id,priority);		/*根据优先级选择对应队列入队*/
	 				id++;
	 			}
				else 		/*如果级别输入的不正确, 直到输入1、2为止*/
	 				printf("\n请输入病人的优先级别(本模拟系统只设置两个优先级别：1或2)\n");
	 			break;
 			case 2: 		/*如果有病人出院*/
 				e = MyDeQueue(q1,q2);	
 				if(-1!=e) 	/*如果队列不为空*/
 					printf("***当前被诊治的病人的ID为：%d***\n",e);
 				else 		/*如果队列为空*/
 					printf("***无病人，队列为空***\n");
 				break;
 			case 3: exit(0);
 		}
	}
	return 0;
}


LinkQueue *LQueueCreateEmpty() /*初始化空队*/
{
	LinkQueue *q=(LinkQueue *)malloc(sizeof(LinkQueue));
	LQNode *p = (LQNode *)malloc(sizeof(LQNode));
	p->next = NULL;
	q->front = p;
	q->rear = q->front;
	return q;
}

bool LQueueIsEmpty(LinkQueue *LQ) /*判队空函数*/
{
	if(LQ->front==LQ->rear)
	{
		return true;
	}
	else
		return false;
}

void LQueueEnQueue(LinkQueue *LQ,DataType x) /*入队*/
{
	LQNode *p = (LQNode *)malloc(sizeof(LQNode));
	if(p == NULL)
	{
		printf("内存分配失败\n");
	}
	else
	{
		p->info = x;
		p->next = NULL;
		LQ->rear->next = p;
		LQ->rear = p;
	}
}

void LQueueDeQueue(LinkQueue *LQ,DataType *x)/*出队:将队头元素出队，并由x带回队头元素信息*/
{
	LQNode * p = (LQNode *)malloc(sizeof(LQNode));
	if(LQ->front->next == LQ->rear)
	{
		LQ->front = LQ->rear;
		*x = LQ->rear->info;
	}
	else
	{
		p = LQ->front->next;
		LQ->front->next = p->next;
		*x = p->info;
		free(p); 
	}
}

DataType LQueueFront(LinkQueue *LQ) /*读队头元素*/
{
	if(LQ->front==LQ->rear)
	{
		printf("队列为空\n");
	}
	return LQ->front->info;
}

void MyEnQueue(LinkQueue *q1,LinkQueue *q2,DataType d,int priority)
{
	if(priority==2)
		LQueueEnQueue(q2,d); 
	else
		LQueueEnQueue(q1,d);
}

DataType MyDeQueue(LinkQueue *q1,LinkQueue *q2)
{
	DataType e;
	if(!LQueueIsEmpty(q2))
		LQueueDeQueue(q2,&e);
	else
		if(!LQueueIsEmpty(q1))
			LQueueDeQueue(q1,&e);
		else return -ERROR;
	return e;
}

