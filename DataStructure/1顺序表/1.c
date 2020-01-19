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
void inversion_List(SxList *List);	/*函数声明 倒置 */ 
void show_List(SxList *List);		/*函数声明 输出顺序表*/

int main()
{
	SxList List;
	InitList(&List);
	CreatList(&List);
	printf("该顺序表为：\n");
	show_List(&List);
	printf("\n");
	printf("倒置后为：\n");
	inversion_List(&List); 
	show_List(&List);			/*倒置后再遍历*/
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

void inversion_List(SxList *List)	/*倒置 */
{
	int t, i=0;
	int j=List->length-1;
	/*将表中的开始结点与末元素节点互换*/
	while(i<j)
	{
		t = List->elem[i];
		List->elem[i] = List->elem[j];
		List->elem[j] = t;
		++i;
		--j;
	}
}
