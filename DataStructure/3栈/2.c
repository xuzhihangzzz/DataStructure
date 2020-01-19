#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct stack
{
	int data[MAXSIZE];
	int top;
} Stack, * Seqstack;

bool InitStack(Seqstack s);		/*初始化栈*/ 
bool push(Seqstack s, int val);	/*入栈*/
bool pop(Seqstack s,int * val);	/*出栈*/
bool GetTop(Seqstack s,int *val);
void showstack(Seqstack s);		/*遍历输出*/
bool SeqstackEmpty(Seqstack s);

int main()
{
	int len,b,i,top,num,a[100];
	int n=0; 
	Seqstack s = (Seqstack)malloc(sizeof(Stack));
	InitStack(s);				/*初始化栈*/
	printf("请输入要输入的整数的个数：");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个数:",i+1);
		scanf("%d",&b);
		push(s,b);
	}
	printf("栈为：\n");
	showstack(s);
	printf("\n");
	
	while(!SeqstackEmpty(s))	/*栈不为空，就出栈，出栈数据放在数组a中*/
	{
		pop(s,&num);
		a[n] = num;
		n++;
	}
	for(i=0;i<n;i++)
	{
		push(s,a[i]);		/*数组a又入栈*/ 
	}
	
	printf("经过该算法后栈为：\n");
	showstack(s);
	printf("\n");
	free(s); 
	return 0;
}

bool InitStack(Seqstack s)
{
	s->top = -1;
	return true;
}

bool push(Seqstack s, int val)
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

bool pop(Seqstack s,int * val)/*把出栈的元素存入val所指向的变量中，出栈成功返回true，失败返回false*/
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

bool GetTop(Seqstack s,int *val)
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

void showstack(Seqstack s)
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

bool SeqstackEmpty(Seqstack s)
{
	if(s->top==-1)
	{
		return true;
	}
	else
		return false;
}
