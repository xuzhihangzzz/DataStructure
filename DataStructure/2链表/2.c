/*
	2、算法编程：
	将一个带头结点的单链表 A 分解成两个带头结点的单链表 B 和 C，
	其中 B 表的结点为 A 表中值小于零的结点，
	而 C 表的结点为 A 表中值大于等于零的结点
	（链表 A 的元素类型为整型，要求 B、C 表利用 A 表的结点）。
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;					/*数据域*/
	struct node * next;			/*指针域*/
}Node, *pNode;

pNode create_list();								/*函数声明：创建链表*/
void traverse_list(pNode pHead);					/*函数声明：遍历链表*/
void split_list(pNode LA, pNode LB, pNode LC);		/*函数声明：分解链表*/

int main()
{
	pNode LA = (pNode)malloc(sizeof(Node));
	pNode LB = (pNode)malloc(sizeof(Node));
	pNode LC = (pNode)malloc(sizeof(Node));
	LA->next = NULL;
	LB->next = NULL;
	LC->next = NULL;
	LA = create_list();
	printf("单链表A为：\n");
	traverse_list(LA);
	printf("\n\n");
	
	split_list(LA,LB,LC);
	printf("分解后，单链表B为：\n");
	traverse_list(LB);
	printf("\n");
	printf("分解后，单链表C为：\n");
	traverse_list(LC);
	printf("\n");
	return 0;
}

pNode create_list()
{
	int len,i,val;
	pNode pHead = (pNode)malloc(sizeof(Node));		/*头节点*/
	pNode p = (pNode)malloc(sizeof(Node));
	p = pHead;										/*头指针指向头节点*/
	printf("请输入需要生成的链表的节点个数：len = ");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);
		pNode pNew = (pNode)malloc(sizeof(Node));	/*for循环每次都会分配一个内存，存放临时节点pNew */ 
		pNew->data = val;							/*数据存入新节点*/
		p->next = pNew;								/*新节点插入*/
		p = p->next;								/*p指向pNew，即实现p指针移向新节点*/ 
		pNew->next = NULL; 
	}
	return pHead;									/*返回头节点*/
}

void traverse_list(pNode pHead)
{
	pNode p = NULL;
	p = pHead->next;								/*头节点不存数据，所以从头节点后一节点(首节点)开始遍历*/
	while(p)
	{
		printf("%d  ",p->data);
		p = p->next;								/*p后移*/
	}
}

void split_list(pNode LA, pNode LB, pNode LC)
{
	pNode pb = LB;
	pNode pc = LC;
	pNode pa = LA->next;							/*指针从首节点开始遍历*/
	while(pa!=NULL)
	{												/*遍历A，当pa->data<0时，就将pa指向的结点插入到LB的后面*/
		if(pa->data<0)
		{
			pb->next = pa;
			pb = pa;								/*指针pb后移*/
			pa = pa->next;
			pb->next = NULL;
		}											/*当pa->data>=0时，就将pa指向的结点插入到LC的后面*/
		else if(pa->data>0 || pa->data==0)
		{
			pc->next = pa;
			pc = pa;								/*指针pc后移*/
			pa = pa->next;
			pc->next = NULL;
		}
	}	
}

