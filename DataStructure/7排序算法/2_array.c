/*数组实现*/ 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct student		/*学生信息结构体*/ 
{
	int id;
	char name[20];
	int math_score;
	int chinese_score;
	int english_score;
	int total_score;
	int rank;
}xxx;

typedef struct a
{
	xxx elem[100];
}Student;

void sort(Student * stu,int len);

int main()
{
	int len,i;
	Student *stu=(Student *)malloc(sizeof(Student));
	printf("请输入学生人数：");
	scanf("%d",&len);
	/*学生信息录入*/
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个学生的学号：",i+1);
		scanf("%d",&stu->elem[i].id);
		printf("请输入第%d个学生的姓名：",i+1);
		scanf("%s",stu->elem[i].name);
		printf("请输入第%d个学生的数学成绩：",i+1);
		scanf("%d",&stu->elem[i].math_score);
		printf("请输入第%d个学生的语文成绩：",i+1);
		scanf("%d",&stu->elem[i].chinese_score);
		printf("请输入第%d个学生的英语成绩：",i+1);
		scanf("%d",&stu->elem[i].english_score);
		stu->elem[i].total_score = stu->elem[i].math_score+stu->elem[i].chinese_score+stu->elem[i].english_score;	/*总成绩*/
		printf("\n");
	}

	sort(stu,len);
	printf("排序后：\n");
	printf("学号\t\t姓名\t数学\t语文\t英语\t总分\t排名\t\n");
	for(i=0;i<len;i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",stu->elem[i].id,stu->elem[i].name,stu->elem[i].math_score,stu->elem[i].chinese_score,stu->elem[i].english_score,stu->elem[i].total_score,stu->elem[i].rank);
	}
	return 0;
}

void sort(Student * stu,int len)
{
	int i,j;
	xxx temp,t2,t3,t4;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(stu->elem[j].total_score < stu->elem[j+1].total_score)
			{
				temp = stu->elem[j];
				stu->elem[j] = stu->elem[j+1];
				stu->elem[j+1] = temp;
			}
			else if(stu->elem[j].total_score == stu->elem[j+1].total_score)
			{
				if(stu->elem[j].math_score < stu->elem[j+1].math_score)
				{
					t2 = stu->elem[j];
					stu->elem[j] = stu->elem[j+1];
					stu->elem[j+1] = t2;
				}
			}
			else if(stu->elem[j].math_score == stu->elem[j+1].math_score)
			{
				if(stu->elem[j].chinese_score < stu->elem[j+1].chinese_score)
				{
					t3 = stu->elem[j];
					stu->elem[j] = stu->elem[j+1];
					stu->elem[j+1] = t3;
				}
				
			}
			else if(stu->elem[j].chinese_score == stu->elem[j+1].chinese_score)
			{
				if(stu->elem[j].english_score < stu->elem[j+1].english_score)
				{
					t4 = stu->elem[j];
					stu->elem[j] = stu->elem[j+1];
					stu->elem[j+1] = t4;
				}
				
			}
		}
	}
	for(i=0;i<len;i++)
	{
		stu->elem[i].rank=(i+1);
	}
}
