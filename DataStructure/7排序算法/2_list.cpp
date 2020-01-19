///*链表实现*/
//#include<stdio.h>
//#include<stdlib.h>
///*链表实现*/ 
//#include<malloc.h>
//#include<string.h>
//typedef struct student		/*学生信息结构体*/ 
//{
//	int id;
//	char name[20];
//	float math_score;
//	float chinese_score;
//	float english_score;
//	float total_score;
//	int rank;
//	struct student * next;	/*指针域*/
//}Student, *pStudent;
//
//pStudent Create_list();
//void sort(pStudent list);
//
//int main()
//{
//	pStudent head = (pStudent)malloc(sizeof(Student));
//	head = Create_list();
//	sort(head);
//	return 0;
//}
//
///*创建学生信息链表*/
//pStudent Create_list()
//{
//	int i,len;
//	int Tid;
//	char Tname[20];
//	float Tmath_score,Tchinese_score,Tenglish_score;
//
//	pStudent head = (pStudent)malloc(sizeof(Student));
//	if(NULL ==  head)
//	{
//		printf("分配失败\n");
//		exit(0);
//	}
//	pStudent pTail;
//	pTail = head;
//	pTail->next = NULL;
//	
//	printf("请输入学生人数：");
//	scanf("%d",&len);
//	
//	for(i=0;i<len;i++)
//	{
//		printf("请输入第%d个学生的学号：",i+1);
//		scanf("%d",&Tid);
//		printf("请输入第%d个学生的姓名：",i+1);
//		scanf("%s",Tname);
//		printf("请输入第%d个学生的数学成绩：",i+1);
//		scanf("%d",&Tmath_score);
//		printf("请输入第%d个学生的语文成绩：",i+1);
//		scanf("%d",&Tchinese_score);
//		printf("请输入第%d个学生的英语成绩：",i+1);
//		scanf("%d",&Tenglish_score);
//		
//		pStudent pNew = (pStudent)malloc(sizeof(Student));	/*for循环每次都会分配一个内存，存放临时节点pNew*/
//		if(NULL == pNew)
//		{
//			printf("分配失败\n");
//			exit(0);
//		}
//		pNew->id = Tid;
//		strcpy(pNew->name, Tname);
//		pNew->math_score = Tmath_score;
//		pNew->chinese_score = Tchinese_score;
//		pNew->english_score = Tenglish_score;
//		pNew->total_score = Tmath_score+Tchinese_score+Tenglish_score;	/*总成绩*/
//		
//		pTail->next = pNew;
//		pNew->next = NULL;
//		pTail = pNew;
//	}
//	return head; 
//}
//
///*排序*/ 
//void sort(pStudent list)
//{
//
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define Path "D:\\dos\\studata.txt"
typedef struct Student{
	char Num[MAX] ; // 序号
	int Sumofscore ; // 成绩总和
	int Chinese ;
	int Math ;
	int English ;
	int science ;
 
}Stu;
 
int main()
{
 
	int n ,i = 0, j;
	Stu *p[MAX] ; // p 是一个 指针数组 ，他是个数组,只是数组的每一个元素
				  // 用来存储指针 ；
	Stu t ;
	Stu a[MAX] ;  // 定义一个结构体数组，每一个元素都是一个结构体变量
	FILE *fp  ;
	if((fp =fopen(Path,"r"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0 );
	}
 
	while(!feof(fp)) // 只要没读取到文件最后,就一直循环
	{
		//
		
		fscanf(fp,"%s %d %d %d %d %d",a[i].Num ,&a[i].Sumofscore ,&a[i].Chinese ,&a[i].Math ,&a[i].English ,&a[i].science);
		// 从文件中分别 读取 文件中的 第一个赋给 a[i].Num ,第二个赋值给a[i].Sumscore 。。。。
		p[i] = &a[i] ;
		/* p[0] 存储 a[0]的地址 ,也就是我们常说的 p[0] 指向 a[0]，p[1] = a[1] p[1] 存储 a[1]的地址...
		
		*/
		i++;
	}
	n = i ;
	rewind(fp);// 将文件指针定位到文件开头 ，因为一开始读取完 文件里的数据 ，文件指针会指向文件末尾
/*
	j =  0;
	printf("学号\t总分\t语文\t数学\t英语\t理综\n"); //  简单的ui界面
	while(j<i)
	{
		// 开始输出
		printf("%s\t%d\t%d\t%d\t%d\t%d\n",a[j].Num ,a[j].Sumofscore ,a[j].Chinese ,a[j].Math ,a[j].English ,a[j].science);
		j++;
	}*/
 
	//  先对总分进行排序;
	for(i = 0 ;i<n-1 ;i++)
	{
		for(j = 0 ;j<n-1-i ;j++)
		{
			if(p[j]->Sumofscore < p[j+1]->Sumofscore )
			{
				t = a[j] ;
				a[j] = a[j+1 ] ;
				a[j+1] =t ;
			}
		}
	}
 
	/*
    排序前
    学号    总分    语文    数学    英语    理综
	001     505     113     115     112     165
	002     520     105     115     120     180
	003     505     113     117     100     175
	004     515     114     117     120     164
	005     511     120     105     111     175
    排序后 (总分从大到小)
    002     520     105     115     120     180
	004     515     114     117     120     164
	005     511     120     105     111     175
	001     505     113     115     112     165
	003     505     113     117     100     175
	*/
	
	
	for (i = 0 ; i < n-1 ; i++ )
	{
		// 对结构体数组进行n-1次的排序
		if((p[i]->Sumofscore == p[i+1]->Sumofscore ))
		{
			// 如果 成绩总分相等执行下面语句
			if((p[i]->Chinese != p[i+1]->Chinese ) &&(p[i]->Chinese < p[i+1]->Chinese) )
			{
				// 如果总分相等并且 语文不相等 并且前面一位的语文成绩要小于后面一位的语文成绩
				// 则将这两个人的位置互换
				// t 是一个中间变量;
				// 类似于冒泡排序
				t = a[i] ;
				a[i] = a[i+1];
				a[i+1] = t ;
 
			}
			else if (p[i]->Chinese == p[i+1]->Chinese)
			{
				// 如果语文成绩也相等 执行下面语句
 
				if((p[i]->Math != p[i+1]->Math )&& (p[i]->Math < p[i+1]->Math)  )
				{
					// 如果数学成绩  前一位的数学成绩不等于后一位同学的数学成绩,并且前一位的
					// 数学成绩比后一位得数学成绩小 ，则互换位置
					t = a[i] ;
					a[i] = a[i+1];
					a[i+1] = t ;
 
				}
				else if (p[i]->Math == p[i]->Math)
				{
					// 如果数学成绩也一样执行下面
					if( ( p[i]->English != p[i+1]->Math)&& ( p[i]->English < p[i+1]->Math ) )
					{
						// 分析和上面一样
						t = a[i] ;
						a[i] = a[i+1];
						a[i+1] = t ;
					}
					else if ( p[i]->English == p[i+1]->English)
					{
 
						if( p[i]->science < p[i+1]->science )
						{
							t = a[i] ;
							a[i] = a[i+1];
							a[i+1] = t ;
						}
 
					}
 
				}
 
			}
 
		}
 
 
	}
 
	j =  0;
	while(j<n)
	{
		printf("%s\n",a[j].Num);
		j++;
	}
 
	return 0 ;
}