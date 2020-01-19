#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;								/*数据域*/
	struct Node * next;						/*指针域*/
}Node, *pNode;

pNode CreateList();							/*函数声明：创建链表*/
void RiseSort(pNode head);					/*函数声明：排序*/
void Simplification(pNode head);			/*函数声明：去除相同的集合元素*/
pNode CreateAgg();
void InsertNode(pNode head,int num);
pNode MergeAgg(pNode A,pNode B); 			/*函数声明：求两个集合的并集*/ 
pNode MutualAgg(pNode A,pNode B); 			/*函数声明：求两个集合的交集*/
void PrintList(pNode head);					/*函数声明：遍历链表*/
void freeheap(pNode head);					/*函数声明：释放节点*/

int main() 
{
    pNode A, B, C, D;
    printf("创建集合 A:\n");
    A = CreateAgg();
    printf("\n创建集合 B:\n");
    B = CreateAgg();
    printf("\n集合A的元素有:\n");
    PrintList(A);
    printf("\n集合B的元素有:\n");
    PrintList(B);
    C = MutualAgg(A,B);
    printf("\nA和B的交集为:\n");
    PrintList(C);
    D = MergeAgg(A,B);
	printf("\nA和B的并集为:\n");
    PrintList(D);
    /*****释放内存*****/
    freeheap(A);
    freeheap(B);
    freeheap(C);
    freeheap(D);
    printf("\n");
    return 0;
}

pNode CreateList() 
{ 
    pNode head, p;
    int i,n,val;
    head = p = (pNode)malloc(sizeof(Node)); 
    head->data = 0;
    printf("请输入节点数据,以 0 为结束标志\n");
    do 
	{
        p->next = (pNode)malloc(sizeof(Node));
        scanf("%d",&val);
        p->next->data = val;
        p = p->next;
    }while(val != 0);
    p->next = head;
    return head;
}
 
void RiseSort(pNode head) 
{ 
    pNode p, s, pt; 
    p = head;
    s = p->next;
    while(p->next != head) 
	{
        while(s->next != head) 
		{
            if(p->next->data > s->next->data) 
			{
                pt = p->next;
                p->next = s->next;
                s->next = p->next->next;
                p->next->next = pt;
            }
            else s = s->next;
        }
        p = p->next;
        s = p->next;
    }
}

void Simplification(pNode head) 
{ 
    pNode p, q, s;
    p = head->next;
    q = p->next;
    while(q != head) 
	{
        if(p->data == q->data) 
		{
            p->next = q->next;
            s = q;
            q = q->next;
            free(s);
        }
        else 
		{
            p = p->next;
            q = q->next;
        }
    }
}

pNode CreateAgg() 
{
    pNode head;
    head = CreateList();
    RiseSort(head);						/*排序*/ 
    Simplification(head);				/*去除相同的集合元素*/ 
    return head;
}
 
void InsertNode(pNode head,int num) 
{
    pNode t, p = head;
    while(p->next != head) 
	{
        if(p->next->data == num) return; 
        if(p->next->data < num) p = p->next;
        else 
		{
            t = (pNode)malloc(sizeof(Node));
            t->data = num;
            t->next = p->next;
            p->next = t;
            return;
        }
    }
    t =(pNode)malloc(sizeof(Node));
    t->data = num;
    p->next = t; 
    t->next = head;     // 插入在链表尾的处理
}
 
pNode MergeAgg(pNode A,pNode B) /*函数声明：求两个集合的并集*/ 
{
    pNode head, pa, pb, pc, qc;
    head = pc = (pNode)malloc(sizeof(Node));
    pa = A->next;
    while(pa != A) 
	{
        qc = (pNode)malloc(sizeof(Node));
        qc->data = pa->data;
        pc->next = qc;
        pc = qc;
        pa = pa->next;
    }
    pc->next = head;
    pb = B->next;
    while(pb != B) 
	{
        InsertNode(head,pb->data);
        pb = pb->next;
    }
    return head;
}
 
pNode MutualAgg(pNode A,pNode B) /*函数声明：求两个集合的交集*/
{
    pNode C, pa, pb, pc, qc;
    C = pc = (pNode)malloc(sizeof(Node));
    pc->data = 0;
    pa = A->next;
    pb = B;
    while(pa != A) 
	{
        pb = B->next;
        while(pb != B) 
		{
            if(pb->data == pa->data) 
			{
                qc = (pNode)malloc(sizeof(Node));
                qc->data = pb->data;
                pc->next = qc;
                pc = qc;
            }
            pb = pb->next;
        }
        pa = pa->next;
    }
    pc->next = C;
    return C;
}

void PrintList(pNode head)
{
	pNode p = NULL;
	p = head->next;								/*头节点不存数据，所以从头节点后一节点(首节点)开始遍历*/
	while(p != head)
	{
		printf("%d  ",p->data);
		p = p->next;								/*p后移*/
	}
	printf("\n");
}

void freeheap(pNode head) 
{
    pNode p, q;
    p = head;
    q = p->next;
    while(q != head) 
	{
        p = q;
        q = p->next;
        free(p);
    }
    free(head);
}
 
