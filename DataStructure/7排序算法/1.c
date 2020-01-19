#include<stdio.h> 
void insort(int a[], int n)
{
    int i,j,k,num=0;		/*i:排序的数的下标，j:已排序的数的下标*/ 
    for(i=2;i<n;i++)		/*一开始，a[1]作为已排序的数，所以这里未排序的数从a[2]开始*/
    {
        a[0]=a[i];			/*a[0]：监视哨;	a[i]:未排序的数中的第一个数*/ 
        j=i-1;				/*a[j]为已排序的数中的最后一个数*/
        /*这个while循环是让已排序的数后移*/ 
        while(a[0]<a[j])	/*查找a[i]的插入位置*/
        {
            a[j+1]=a[j];	/*将大于a[i]的数后移*/ 
            j--;			/*从后往前遍历已排序的数*/ 
        }
        a[j+1]=a[0];		/*插入a[i]	(a[i]的数是存在a[0]这个监视哨里的)*/ 
        num++;				/*记录趟数*/
        printf("第%d趟排序后：",num);
        for(k=1;k<n;k++)	/*在每趟排序后，输出显示排序后的记录*/
        {
        	printf("%d  ",a[k]);
		}
		printf("\n");
    }
}
int main()
{
	int i;
    int arr[9]={0,49,38,65,97,76,13,27,18};/*a[0]不放数据，做监视哨的*/
    printf("原数据为：");
	for(i=1;i<9;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
    insort(arr,9);
}

