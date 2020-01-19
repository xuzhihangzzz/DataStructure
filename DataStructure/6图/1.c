/*
	建立无向图的邻接矩阵存储并输出（矩阵形式）。
	无向图可以带权或不带权，要求分别编写邻接矩阵建立函数和矩阵输出函数来实现。
*/
#include<stdio.h>
#define MAXSIZE 100		/*图的最大顶点个数*/
typedef char HeadType;	/*顶点数据类型*/
typedef int EdgeType;	/*边数据类型*/
typedef struct
{
	HeadType head[MAXSIZE];	/*存放顶点数据的数组*/
	EdgeType edges[MAXSIZE][MAXSIZE]; 	/*存放边数据的二维数组*/
	int headNum;			/*顶点数*/
	int edgeNum;			/*边数*/
}Graph; 

Graph CreateGraph();			/*函数声明：邻接矩阵建立函数*/
void PrintGraph(Graph g);		/*函数声明：矩阵输出函数*/

int main()
{
	Graph g;
	g = CreateGraph();			/*建立邻接矩阵*/
	PrintGraph(g);				/*输出邻接矩阵*/
	return 0;
}

Graph CreateGraph()
{
	int i,j,k;
    Graph g;
    printf("请输入顶点个数：");
    scanf("%d",&g.headNum);			/*顶点个数*/
    printf("请输入边的条数：");
    scanf("%d",&g.edgeNum);			/*边条数*/
    printf("请输入%d个顶点的数据：\n",g.headNum);
    scanf("%s",g.head);				/*顶点字符表示符*/
    /*初始化边的二维数组的数据(初始化边的权值)*/
    for(i=0;i<MAXSIZE;++i)
    {
		for(j=0;j<MAXSIZE;++j)
		{
			if(i != j)
			{
				g.edges[i][j] = 0;
			}
			else
			{
				g.edges[i][i] = 0;			/*顶点到本身的距离值为0*/
			}
		}           
    }
    
    for(k=0;k<g.edgeNum;k++)
    {
		printf("输入第%d条边起点序号和终点序号,用空格隔开：",k+1);
        scanf("%d %d",&i,&j);		/*输入对应边起点序号和终点序号*/
	    while(i<1|| i>g.headNum || j<1 || j>g.headNum)
	    {
			printf("错误的边序号！,请重新输入i,j\n");
			scanf("%d %d",&i,&j);
		}
	    getchar();
	    g.edges[i-1][j-1] = 1;
		g.edges[j-1][i-1] = 1;
	}
    return g;
}

void PrintGraph(Graph g)
{
	int i,j;
	printf("\n顶点数据如下：\n");
	printf("%s\n",g.head);
	printf("\n邻接矩阵如下：\n");
	for(i=0;i<g.headNum;i++)
	{
		for(j=0;j<g.headNum;j++) 
		{
			printf("%5d",g.edges[i][j]);
		}
		printf("\n");
	}
}

