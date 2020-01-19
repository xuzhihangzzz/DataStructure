#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX 100

typedef struct node 
{
	char name[10];									/*存放家族成员姓名*/
	struct node *lchild, *rchild;
}BTree;												/*二叉树结构体类型定义*/
 

BTree *q[MAX];										/*全局变量：存储队列元素的队列*/
BTree *CreatBtree();								/*函数声明：创建二叉树 */
void ScanLevel(BTree *bt);							/*函数声明：按层次顺序遍历二叉家族树 */
int FindAncestry(BTree *bt,char *ch);				/*函数声明：找祖先*/ 

int main()
{
	BTree *head;
	int ch;
	char cname[10];
	while(1)
	{
 		printf("请选择以下操作：\n");
	    printf ("一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一\n");
	    printf("1……创建一个二叉家族树\n");
	    printf("2……按层次输出二叉家族树\n");
	    printf("3……输出某个成员的所有祖先成员\n");
	    printf("4……结束程序\n");
	    printf ("一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一\n");
	    printf("请选择(1--4)：");
	    scanf("%d",&ch);
		getchar();
		switch(ch)
		{
			case 1:
				head=CreatBtree(); 					/*创建二叉家族树*/
				printf("\n二叉家族树创建成功！\n");
				printf("\n请按任意键返回主菜单...");
				getchar();
				break;
			case 2:
				printf("按层次输出二叉家族树：\n");
				ScanLevel(head);					/*按层次输出家族树*/
				printf("\n请按任意键返回主菜单...");
				break;
			case 3: 
				printf("\n请输入要查找哪个成员的祖先：\n");
		        scanf("%s",cname);
				getchar();
		    	FindAncestry(head,cname);
				printf("\n请按任意键返回主菜单...");
		        break;
			case 4:
				exit(0);
		}
		getchar();
	}
	return 0;
}

/*层次顺序创建二叉家族树*/
BTree * CreatBtree()
{
	char ch1[10];
	int front,rear;									/*设置队头和队尾指针，并置队列为空*/
	int flag=0;										/*队头指针front移动的判断标志*/ 
	BTree *root,*s;
	front=1,rear=0;									/*front是用来指向父结点下标的*/ 
	root=NULL;
	printf("请按层次顺序输入家族成员姓名，空缺处输入@，结束附为$ \n");
	scanf("%s",ch1);								/* 输入第一个家族成员姓名 */
	while(strcmp(ch1,"$"))							/*不是结束符时重复循环 */
	{	
		s=NULL;
		if(strcmp(ch1, "@"))
		{
			s = (BTree *)malloc(sizeof(BTree));		/*不是空结点时，创建新结点*/
			strcpy(s->name, ch1);
			s->lchild = NULL;
			s->rchild = NULL;
		}
    	rear++;
		q[rear]=s;									/*将新结点地址入队*/  
		if(rear==1)									/*输入的第一个结点为根结点 */
		{
			root=s;
		}
		else										/*如果是虚结点，则申请不到s就不必考虑怎么挂结点s*/
		{
			if(q[front] && s)						/*孩子和双亲结点不是空结点  */
			{
				if(rear%2==0)						/*rear为偶数，新结点是左孩子 */
				{
					q[front]->lchild = s;			/*rear为偶数，新结点是q[front]左孩子*/
				}
 				else
				{
                    q[front]->rchild = s;			/*rear为奇数，新结点是q[front]右孩子 */
					front++;  						/*结点*q[front]的左、右孩子处理完毕，该结点出队，改变父结点的下标front*/
					flag=0;
				}
			}
			else
			{
				flag++;      						 /*添加的结点为空时，左右孩子处理完，该结点出队，front指针增加*/
	        	if(flag==2)
				{
					front++;
					flag=0;
				}
			}
		}
	scanf("%s",ch1);								/*输入下一个字符 */
	}
	return root;									/*返回根结点地址 */
}

/*按层次顺序遍历二叉家族树 */
void ScanLevel(BTree *bt)
{
	int front=0,rear=0; 							/*初始化队列的头、尾指针 */
	if(bt!=NULL)
	{
		rear++;
		q[rear]=bt;									/*将bt所指向的结点入队 */
	}
	while(front!=rear)								/*队列非空 */
	{
		front++;
		bt=q[front];								/*队头结点出队 */
		printf ("%s    ",bt->name);					/*输出该结点的数据 */
		if(bt->lchild!=NULL)
		{
			rear++;
			q[rear] = bt->lchild;					/*将左孩子结点入队 */ 
		}
		if(bt->rchild!=NULL)
		{
			rear++;
			q[rear] = bt->rchild;					/*将右孩子结点入队 */
		}
	}
	printf("\n");
}

/*查找数据为*ch的结点。若有，输出该结点的所有祖先成员，并返回1；若没有，返回0*/
int FindAncestry(BTree *t,char *ch)
{													
	int flagl=0,flag2=0;   							/*设置两个标志变量 */
	int cond;
	if(t==NULL||(t->lchild==NULL&&t->rchild==NULL)) /*树中结点数不大于l*/
	{
		return 0;
	}
	cond=(t->lchild!=NULL)&&(strcmp(t->lchild->name,ch)==0);	/*左孩子是所找结点*/
	cond=cond ||((t->rchild!=NULL)&&(strcmp(t->rchild->name,ch)==0));	/*或右孩子是所找结点*/
	if(cond)										/*左孩子或右孩子是所找结点 */
	{
		printf("%s,",t->name);
		return 1;   								/*找到祖先，返回1值*/
	}
	else
	{	
		flagl=FindAncestry(t->lchild,ch);			/*在左子树上查找，将返回值赋给flag1*/
		flag2=FindAncestry(t->rchild,ch);			/*在右子树上查找，将返回值赋给flag2*/
		if(flagl || flag2)   						/*左子树或右子树上找所有结点 */
		{
			printf("%s,",t->name);
			return 1;								/*满足判断条件的，返回1值 */
		}
		else
		{
			return 0;
		}
	}
	printf("\n");
}

