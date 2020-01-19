#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MaxSize 100
typedef struct DataType
{
	char number[5];    		/*车次*/
	char terminal[9];    	/*目的地*/
	int price;    			/*价格*/
	int count;    			/*剩余票数*/
}DataType;    				/*车票类型*/
typedef struct SequenList
{
	DataType data[MaxSize];	/* 存储各车次信息的数组*/
	int length; 			/*车次数*/
}SequenList ;  				/*顺序表,存储车次列表*/

/*函数声明*/
void FCreat(SequenList *L);	/*读取文件,获取车票信息,存入车次信息结构体*/ 
void SellTicket(SequenList *ticketList,char number[5],int quantity,int money);/*售票*/ 
void OutPut(SequenList L);	/*输出车次信息结构体*/
int SearchBin(SequenList st,char number[5]);/*二分查找*/ 

int main()
{
	SequenList ticketList;
	char number[5];
	int quantity,money;
	
	while(1)
	{
		printf("\n\n1．供票(Supply)");
		printf("\n2．售票(Sell)");
		printf("\n3．查询(Query)");
		printf("\n0．退出(Quit)");
		printf("\n请选择(Select):");
		switch(getche())
		{	
			case '1':	
				FCreat(&ticketList);
				puts("\n供票完成！\n");
				break;
			case '2':	
				puts("\n\n请分别输入要购买的车次  票数  金额(以空格隔开):");
				scanf("%s%d%d",number,&quantity,&money);
				SellTicket(&ticketList, number, quantity, money);	/*进行售票*/
				break;
			case '3':
				OutPut(ticketList);/*进行查询*/
				break;
			case '0':
				return;
		}
	}
}

void FCreat(SequenList *L)		/*读取文件,获取车票信息*/ 
{
	FILE *fp;    
	int i=1;
	fp=fopen("shepiao_info.txt","r"); 
	if(!fp)
	{
		printf("\n数据文件无法打开!");
	}	
	else
	{
		L->length=0;
		while(!feof(fp))
		{
			/*从文件中读取车票信息，存入车次信息结构体*/
			fscanf(fp,"%s%s%d%d\n",L->data[i].number,L->data[i].terminal,&(L->data[i].price),&(L->data[i].count));
			L->length++;
			i++;
		}
	}
}

void OutPut(SequenList L)		/*输出车次信息结构体*/
{
	int i;
	puts("\n\n车票信息表(Tickers List)");
	puts("\n车次    目的地    价格    剩余票数");
	puts("No．Destination    Price    Remainder");
	for(i=1;i<=L.length;i++)
	{
		printf("\n%-7s%-10s%7d%9d",L.data[i].number,L.data[i].terminal,L.data[i].price,L.data[i].count);
	}
}

int SearchBin(SequenList st,char number[5])	/*二分查找*/
{  /*使用折半查找,在有序查找表st中查找关键字值等于number的记录,有则返回该记录的位置序号;没有,则返回特殊值0。*/
	int low, high, mid;
	low=0,high=st.length-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(number, st.data[mid].number)==0)
		{
			return mid;
		}
		if(strcmp(number, st.data[mid].number)<0)
		{
			high=mid-1;
		}
		if(strcmp(number, st.data[mid].number)>0)
		{
			low=mid+1;
		}
	}
	if(low>high)
	{
		return 0;
	}
}

void SellTicket(SequenList *ticketList,char number[5],int quantity,int money)
{/*售票,车次信息表为ticketList,给定的车次number,购买张数scount,金额money*/
	int cc,rr;
	int mremainder,nremainder;				/*剩余金额，剩余数量*/
	int factcount;    						/*实际可购买的张数*/
	cc=SearchBin(*ticketList,number);  		/*查找车次*/
	if(cc==0)  								/*没有该车次*/
	{
		printf("无效号码。您的余款为:%d",money);
		return;
	}
	if(ticketList->data[cc].count==0)  		/*剩余数量为0,已售罄*/
	{
		printf("该次车票已售罄!．您的余款为:%d",money);
		return;
	}
	nremainder=ticketList->data[cc].count-quantity ;	/*剩余数量*/
	if(nremainder>=0)   					/*数量够*/
	{
		factcount=quantity;  				/*购买张数*/
	}
	else    								/*数量不够*/
	{
		factcount=ticketList->data[cc].count;   				/*最多可购买的张数*/
	}
	mremainder=money-ticketList->data[cc].price*factcount ;		/*剩余金额*/
	if(mremainder<0) 						/*金额不够时购买张数不变,金额不够时求最多购买的张数*/
	{
		factcount=(int)(money/ticketList->data[cc].price);    	/*最多购买的张数*/
	}
	if(factcount>0)
	{
		ticketList->data[cc].count-=factcount;
		mremainder=money-ticketList->data[cc].price*factcount;	/*剩余金额*/
		printf("已购买：车次:%s  列车目的地:%s  单价:%d  数量:%d  余额:%d",ticketList->data[cc].number,ticketList->data[cc].terminal,ticketList->data[cc].price,factcount,mremainder);
	}
	else
	{
		printf("无效购买。您剩余的钱为:%d",money);
	}
}

