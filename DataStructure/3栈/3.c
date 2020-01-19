#include<stdio.h>
#include<stdlib.h>
#define m 6									/* 迷宫的实际行  */ 
#define n 8									/*迷宫的实际列*/ 
#define STACK_INIT_SIZE 100      			//存储空间初始分配量
#define STACKINCREMENT 10      				//存储空间分配增量

typedef struct
{ 
	int x,y,d;    							/*横纵坐标及方向*/ 
} SElemType; 
typedef struct
{     
	SElemType stack[STACK_INIT_SIZE];     
	int top;            
} SeqStack;          						/*定义顺序栈类型*/ 
typedef struct
{
	int x,y;   
} Item; 
SElemType XX={-1,-1,-1};
int maze[m+2][n+2]=
{  /*        0,1,2,3,4,5,6,7,8,9      */
	{1,1,1,1,1,1,1,1,1,1},/*0*/
	{1,0,1,1,1,0,1,1,1,1},/*1*/
	{1,1,0,1,0,1,1,1,1,1},/*2*/
	{1,0,1,0,0,0,0,0,1,1},/*3*/
	{1,0,1,1,1,0,1,1,1,1},/*4*/
	{1,1,0,0,1,1,0,0,0,1},/*5*/
	{1,0,1,1,0,0,1,1,0,1},/*6*/
	{1,1,1,1,1,1,1,1,1,1}/*7*/
};
Item move[8]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
/* 8个移动方向*/ 
int Empty_SeqStack(SeqStack *s);					/*函数声明：栈是否为空*/
void Push_SeqStack(SeqStack *s,SElemType x);		/*函数声明：压栈*/
SElemType Gettop_SeqStack(SeqStack *s);				/*函数声明：栈顶值*/
SElemType Pop_SeqStack(SeqStack *s);				/*函数声明：出栈*/
void * OnePath(int maze[m+2][n+2],Item move[8],SeqStack *s);/*函数声明*/
 
int main()
{
	SElemType temp;
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));  
	if(!s)
	{
		exit(0);
	}
	else
	{
		s->top = -1;
	}
	OnePath(maze,move,s);						/*探索路径*/ 
	
	if(s->top==-1)								/*栈为空，迷宫无出路*/ 
	{
		printf ("此迷宫无路径\n");
	}
	else										/*栈非空，给出迷宫路径*/ 
	{ 
		printf ("迷宫路径为：\n") ; 
		while(!Empty_SeqStack(s))				/*栈非空,将栈中的元素出栈并打印*/
		{
			temp=Pop_SeqStack(s);
			printf("(%d,%d)-",temp.x,temp.y);
		}
		while(getchar()!='0')
		{
			printf("请输入0，退出程序！");
		}
	}
	return 0;
}

int Empty_SeqStack(SeqStack *s)
{ 
	/*判栈空。要求：空栈栈顶指针为-1,返回1,否则返回0*/
	if(s->top == -1)
	{
		return 1;
	}
	else
		return 0;
} 
void Push_SeqStack(SeqStack *s,SElemType x)
{ 
	/*将元素x压入栈s中。要求：栈满,提示栈满信息，完成入栈操作则返回*/
	if(s->top == STACK_INIT_SIZE-1)
	{
		printf("栈满了");
	}
	else
	{
		s->top++;
		s->stack[s->top] = x;
	}
} 
SElemType Gettop_SeqStack(SeqStack *s) 
{
	/*取栈顶元素。要求：栈空不能出栈,返回特殊值XX；否则返回栈顶元素*/
	if(s->top==-1)
	{
		return XX;
	}
	else
	{
		return s->stack[s->top];
	}
} 
SElemType Pop_SeqStack(SeqStack *s)     
{
	/*出栈, ,成功时返回顶元素;不成功时结束程序*/
	if(Empty_SeqStack(s))
	{
		printf("\n 栈为空！");  
		exit(0);
	} 
	else
	{
		s ->top--;                                  
		return s->stack[s->top+1];
	}
}

void* OnePath(int maze[m+2][n+2],Item move[8],SeqStack *s)
{	/*探索一条迷宫路径,成功时返回1,否则返回0。探索成功时,将搜索路径上的顶点放入栈S中*/
	int x,y,d,i,j,dd;
	SElemType temp;
	temp.x=1;    
	temp.y=1;
	temp.d=-1;					/* 入口点坐标及到达该点的方向(设为-1)入栈  */ 
	Push_SeqStack(s,temp);		/*temp入栈*/ 
	maze[temp.x][temp.y]=-1; 
	dd=0;						/*第一个搜索方向*/
	while(!Empty_SeqStack(s))
	{
		temp=Gettop_SeqStack(s);/*取栈顶元素*/
		x=temp.x;
		y=temp.y;
		d=dd;
		while(d<8)
		{
			i=x+move[d].x;
			j=y+move[d].y;
			if(maze[i][j]==0)	/*找到下一步的一个可行顶点*/  
			{
				temp.x=i;
				temp.y=j;
				temp.d=d;		/*下一步的一个顶点temp */
				Push_SeqStack(s,temp);/* 顶点入栈*/   
				dd=0;			/*搜索方向初始化为第一个方向  */   
				maze[i][j]= -1;	/*给已走过的路径做标记*/   
				if(i==m && j==n)
					return 0;	/*找到迷宫出口,结束*/   
				break; 			/*找到下一步的—个顶点之后,就暂时不再沿其他方向搜索  */   
			}
			else
				d=d+1;			/*探索下一个方向*/ 
		}
		if(d==8)				/*无路可走*/ 
		{
			temp= Pop_SeqStack(s);
			dd=temp.d+1;		/*再沿上一步的下一个方向搜索*/ 
		}
	}
	return 0;
}
