#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#define MM 7								/*彩票中号码的个数*/
#define NN 36								/*备选数的个数*/

typedef int ElemTp;							/*元素类型*/
typedef struct
{
	ElemTp elem[MM+1];
	int len;
}VoteTp;									/*彩票号码表结构体*/

typedef struct
{
	ElemTp elem[NN+1];
	int len;
} SourceTp;									/*备选数表结构体*/

				/*函数声明*/ 
void InitializeVote(VoteTp *vote);			/*初始化彩票号码表*/
void InitializeSource(SourceTp *Source);		/*初始化备选数表Source，在表中放入1～3 6共3 6个数，将表长置为36 */
int SeqLocate(VoteTp v,ElemTp x);			/*在顺序表v中查找值为x的元素，返回该元素的位置序号，没有时返回0*/
void SeqInsertVote(VoteTp *vote,int i,ElemTp x);/*在顺序表*vote的第i个数据元素之前插入数据元素x */
void CreateAVote(SourceTp source,VoteTp *vote);  /*生成一张彩票vote*/
int RightNum(VoteTp vote,VoteTp answervote); /*判断彩票的中奖情况*/
				/*函数体*/ 
void InitializeVote(VoteTp *vote)			/*初始化彩票号码表*/
{
	vote->len=0;
}

void InitializeSource(SourceTp *Source)		/*初始化备选数表Source，在表中放入1～3 6共3 6个数，将表长置为36 */
{
 	int i;
 	Source->len=0;
 	for(i=0;i<NN;i++)
 	{
 		Source->elem[i]=i;
		Source->len++;
 	}
}

int SeqLocate(VoteTp v,ElemTp x)			/*在顺序表v中查找值为x的元素，返回该元素的位置序号，没有时返回0*/
{
	int flag=0;
	int i;
	for(i=0;i<v.len;i++)
	{
		if(v.elem[i]==x)
		{
			flag=1;
			return (i+1);
			break;							/*找到就终止循环*/
		}
	}
	if(flag==0)
	{
		return 0;
	}
}

void SeqInsertVote(VoteTp *vote,int i,ElemTp x)/* 在顺序表*vote的第i个数据元素之前插入数据元素x */
{
	int t;
	for(t = vote->len-1;t>=i-1;--t)
	{
		vote->elem[t+1] = vote->elem[t];
	}
	vote->elem[i-1] = x; 
	(vote->len)++;
}

void CreateAVote(SourceTp source,VoteTp *vote)  /*生成一张彩票vote*/
{
	ElemTp k,temp;
	int i;
	InitializeVote(vote); 
	for(i=0;i<MM;i++)
	{
		srand( (unsigned)time( NULL ) );		/*设置随机数种子，每次的彩票号码才能不同*/
		k= rand() % source.len+1;				/*产生一个1到source.len的随机数k*/
		
		SeqInsertVote(vote,vote->len+1,source.elem[k]);		/*将source.elem[k]插入到彩票号码表vote中 */
		/*将备选数表source中的第k个元素删掉*/
		/*删除算法：Source.el em[k]与source.elem[source.len]交换，将备选数表表长source.1en减1*/
		temp=source.elem[k];
		source.elem[k]=source.elem[source.len];
		source.elem[source.len]=temp;
		source.len=source.len-1;
	}
}

int RightNum(VoteTp vote,VoteTp answervote) /*判断彩票的中奖情况*/
{	/*一张彩票vote和中奖号码表answervote相比，求出并返回猜对的号码个数*/
	int i,k;
	k=0;
	for (i=0;i<MM;i++)
	{
		if(SeqLocate(vote,answervote.elem[i])>0)
		{
			k++;	
		}
	}
	
	return(k);
}

int main()
{ 
	SourceTp source;
 	VoteTp vote;
 	VoteTp answervote;
 	int k,i;
 	InitializeSource(&source); 					/*初始化备选数表Source：放入36个数，将表长置为36*/		
 	printf("\n 本次中奖号码: "); 
 	CreateAVote(source,&answervote); 			//生成一组中奖号码
 	for (i=0;i<MM;i++)							/*i必须从0开始*/ 
 	{
	 	printf("%3d ",answervote.elem[i]); 		/*遍历输出本次中奖号码*/ 
	}	
	while(getchar()!='0')	
	{
		printf("\n 你的彩票编码:\n");
	 	CreateAVote(source,&vote);				/*生成你的彩票号码*/
	  	for (i=0;i<MM;i++)
	  	{
	  		printf("  %-2d  ",vote.elem[i]);	/*遍历输出你的彩票号码*/ 
	  	}	
		printf("\n兑奖：");
	  	k=RightNum(vote,answervote);			/*调用判断彩票的中奖情况函数*/
	  	printf("恭喜你中了%d 位数字！！！\n",k);
	 	printf("\n 按回车键继续，按0结束...");
	}
 	return 0;
}
