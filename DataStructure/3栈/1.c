/*从键盘输入一整数的序列a1，a2,...an，
*编写算法实现：
*用顺序栈结构存储输入的整数序列
*，当ai不等于-1时，将ai入栈；
*当ai=-1时，输出栈顶整数并出栈。
*要求能应对入栈满等异常情况，
*并给出提示信息。
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct stack
{
	int data[MAXSIZE];
	int top;
} Stack, * pStack;

bool InitStack(pStack s);		/*初始化栈*/ 
bool push(pStack s, int val);	/*入栈*/
bool pop(pStack s,int * val);	/*出栈*/
bool GetTop(pStack s,int *val);
void showstack(pStack s);		/*遍历输出*/

int main()
{
	int len,a,i,top;
	pStack s = (pStack)malloc(sizeof(Stack));
	InitStack(s);				/*初始化栈*/
	printf("请输入要输入的整数的个数：");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个数:",i+1);
		scanf("%d",&a);
		if(a != -1)
		{
			push(s,a);			/*当ai不等于-1时，将ai入栈*/
		}
		else
		{
			pop(s,&top);
			printf("\n栈顶整数出栈\n");
			printf("栈顶整数为：%d\n\n",top);		/*ai=-1时，输出栈顶整数并出栈*/
		}
	}
	printf("栈里的数为：\n");
	showstack(s);
	free(s); 
	return 0;
}

bool InitStack(pStack s)
{
	s->top = -1;
	return true;
}

bool push(pStack s, int val)
{
	if(s->top==MAXSIZE-1)
	{
		printf("栈满了\n");
		return false;
	}
	else
	{
		s->top++;
		s->data[s->top] = val;
		return true;
	} 
}

bool pop(pStack s,int * val)/*把出栈的元素存入val所指向的变量中，出栈成功返回true，失败返回false*/
{
	if(s->top==-1)
	{
		printf("栈空\n");
		return false;
	}
	*val = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(pStack s,int *val)
{
	if(s->top==-1)
	{
		printf("栈空\n");
		return false;
	}
	else
	{
		*val = s->data[s->top];
		return true;
	}
}

void showstack(pStack s)
{
	int i=0;
	if(s->top==-1)
	{
		printf("栈空\n");
	}
	else
	{
		while(i<s->top||i==s->top)
		{
			printf("%d  ",s->data[i++]);
		}
		printf("\n");
	}
}
