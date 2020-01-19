/*
	1、编写一函数，利用二分查找算法在一个有序表中查找关键字为x的结点
	若不存在，则插入一个元素x，并保持表的有序性。
*/
#include<stdio.h>
int main()
{
	int i,flag=0,index,j,n,k,t,low,high,mid;
	int a[50];
	/*创建初始数据表*/ 
	printf("请输入有序表的元素个数:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	/*原数据排序*/
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("请输入要查找的数据：");
	scanf("%d",&k);
	/*二分查找*/
	low=0,high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==a[mid])
		{
			printf("\n找到该节点，下标为：%d",mid);
			break;
		}
		if(k<a[mid])
		{
			high=mid-1;
		}
		if(k>a[mid])
		{
			low=mid+1;
		}
	}
	/*找不到*/ 
	if(low>high)
	{
		printf("\n该节点不存在\n");
		/*找到插入的位置*/
		for(i=0;i<n;i++)
		{
			if(k<a[i])
			{
				flag=1;
				index=i;
				break;
			}
		}
		if(flag==0)/*插入的数比原数据都大*/
		{
			a[n]=k;
		}
		else
		{
			/*插入位置后面的数后移*/
			for(i=n-1;i>=index;--i)	/*必须从后往前遍历*/
			{
				a[i+1]=a[i];		/*从后往前的每个数后移*/ 
			}
			/*插入*/
			a[index]=k; 
		}
		printf("插入x后，数据为：\n");
		for(i=0;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
	}
	return 0;
}

