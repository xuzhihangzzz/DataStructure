#include<stdio.h>
#include<malloc.h>
typedef struct list 
{
	int Date;					/*数据域*/
	struct list * next;			/*指针域*/ 
}List, *PList;

PList create_list();				//创建链表		
void traverse_list(PList pHead);	//遍历 
void insert_list(PList pHead);		//插入  

int main()
{
	PList pHead = NULL;
	pHead = create_list();			/*头指针返回给pHead*/ 
	printf("该链表数据为：\n"); 
	traverse_list(pHead);
	insert_list(pHead);
	printf("插入后的数据为：\n");
	traverse_list(pHead);
	return 0;
}

PList create_list()
{
	int len,i,val;
	PList p = NULL;
	PList L = (PList)malloc(sizeof(List));			/*头节点*/
	p = L;											/*头指针p指向头节点L*/
	printf("请输入需要生成的链表的节点个数：len = ");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);
		PList pNew = (PList)malloc(sizeof(List));	/*for循环每次都会分配一个新节点*/
		pNew->Date = val;							/*数据存进节点的数据域*/
		p->next = pNew;								/*节点插入*/ 
		pNew->next = NULL;
		p = pNew;									/*指针p后移实现尾插法*/ 
	}
	return L;
}

void traverse_list(PList pHead)
{
	PList p = pHead->next;							/*头节点不存数据，所以从头节点后一节点(首节点)开始遍历*/
	while(p!=NULL)
	{
		printf("%d  ",p->Date);
		p = p->next;
	}
	printf("\n");
}

void insert_list(PList pHead)
{
	int x;
	int i = 0;
	int j = 0;
	PList p = pHead;
	printf("请输入要插入的数：");
	scanf("%d",&x);
	while(NULL!=p && x<(p->Date))
	{
		p = p->next;
		++i;
	}
	/*i就是要插入的位置，无法前插*/
	p = pHead;									/*让p回到头节点*/ 
	while(NULL!=p && j<i-1)						/*j=i+1终止循环，把数据插入到j后（即i前）*/
	{
		p = p->next;
		++j;
	}
	PList pNew = (PList)malloc(sizeof(List));	/*插入数据需要新分配内存空间*/ 
	pNew->Date = x;
	pNew->next = p->next;						/*新结点指向p的后一个节点*/
	p->next = pNew;								/*p指向新节点*/ 
}

