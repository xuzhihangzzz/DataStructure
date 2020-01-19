#include<stdio.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct
{
	Elemtype elem[MAXSIZE];
	int length;
}SxList;
void InitList(SxList *List);		/*函数声明 初始化顺序表*/
void CreatList(SxList *List);		/*函数声明 创建顺序表*/
void find_List(SxList *List,int val);/*函数声明 查找 */ 
void show_List(SxList *List);		/*函数声明 输出顺序表*/

int main()
{
	int needFind,i,j,temp;
	SxList List;
	InitList(&List);
	CreatList(&List);
	for(i=0;i<List.length-1;i++)			/*线性表中元素递增有序*/
	{
		for(j=0;j<List.length-i-1;j++)
		if(List.elem[j]>List.elem[j+1])
		{
			temp = List.elem[j];
			List.elem[j] = List.elem[j+1];
			List.elem[j+1] = temp;
		}
	}
	printf("该顺序表为：\n");
	show_List(&List);
	printf("\n");
	printf("请输入要查找的数\n");
	scanf("%d",&needFind);
	find_List(&List,needFind);	
	show_List(&List);			/*查找并处理后再遍历*/
	return 0;
}

void InitList(SxList *List)		/*初始化顺序表*/
{
	List->length = 0;
}

void CreatList(SxList *List)	/*创建顺序表*/
{
	int num,i;
	printf("请输入元素个数:");
	scanf("%d",&num);
	printf("请输入%d个元素\n",num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&List->elem[i]);
		++List->length;
	}
}

void show_List(SxList *List)	/*输出顺序表*/ 
{
	int i;
	if(0 == List->length)
	{
		printf("该数组为空。\n");
	}
	else
	{
		for(i=0;i<(List->length);++i)
		{
			printf("%d ",List->elem[i]);
		} 
		printf("\n");
	}
}

void find_List(SxList *List,int val)	/*查找 */
{
	int i,temp,j;
	int flag = 0;
	for(i=0;i<List->length;++i)
	{
		if(val==List->elem[i])
		{
			flag = 1;
			temp = List->elem[i];
			List->elem[i] = List->elem[i+1];
			List->elem[i+1] = temp;				/*若找到将其与后继元素位置相交换*/
			printf("找到!\n");
			printf("找到后将其与后继元素位置相交换，如下：\n");
			break;
		}
	}
	if(flag == 0)
	{
		printf("没找到!\n");
		(List->length)++;
		List->elem[List->length-1] = val;						/*若找不到将其插入表中*/
			/*并使表中元素仍递增有序*/
		printf("没找到的话将其插入表中并使表中元素仍递增有序，如下：\n");
		for(i=0;i<List->length-1;i++)
		{
			for(j=0;j<List->length-i-1;j++)
			if(List->elem[j]>List->elem[j+1])
			{
				temp = List->elem[j];
				List->elem[j] = List->elem[j+1];
				List->elem[j+1] = temp;
			}
		}
	}
	
}

