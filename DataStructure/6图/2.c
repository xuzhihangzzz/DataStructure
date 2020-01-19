#include<stdio.h>
#include <stdlib.h>
#define VexNum 20		/*图的最多顶点个数*/
#define MAXINT 30000	/*极大值*/
typedef char VexType;	/*顶点数据类型*/
typedef int EdgeType;	/*边数据类型*/

typedef struct
{
	VexType vexs[VexNum];	/*存放顶点数据的数组*/ 
	EdgeType arcs[VexNum][VexNum];	/*存放边数据的二维数组*/
	int vexnum,arcnum;	/*顶点数和边数 */
}Mgraph;				/*图的邻接矩阵表示结构定义 */

typedef struct
{
	int adjvex;			/*集合U中的顶点(始点)*/
	int value;			/*集合u中顶点到非U中的某个顶点的最小距离值*/
}InterEdge;

void Min_SpanTree(Mgraph G,int u);	/*函数声明*/
Mgraph Create_MgraphN();			/*函数声明*/
int MinValue(InterEdge ee[],int n);	/*函数声明*/

int main()
{
	Mgraph G;
	G=Create_MgraphN();
	Min_SpanTree(G,0);
	return 0;
}

/*创建无向带权图的邻接矩阵算法*/
Mgraph Create_MgraphN()				
{  
    int i,j,k;
    EdgeType v;						/* 边的权值 */
    Mgraph G;
    printf("请输入顶点个数：");
    scanf("%d",&G.vexnum);			/*顶点个数*/
    printf("请输入边的条数：");
    scanf("%d",&G.arcnum);			/*边条数*/
    printf("请输入%d个顶点的数据：\n",G.vexnum);
    scanf("%s",G.vexs);				/*顶点字符表示符*/
    /*初始化边的二维数组的数据(初始化边的权值)*/
    for(i=0;i<VexNum;++i)
    {
		for(j=0;j<VexNum;++j)
		{
			G.arcs[i][j] = MAXINT;	/*设置初始距离值为MAXINT*/
			if(i == j)
			{
				G.arcs[i][j] = 0;			/*顶点到本身的距离值为0*/
			}
		}           
    }
    
    for(k=0;k<G.arcnum;k++)
    {
		printf("输入第%d条边起点序号和终点序号,用空格隔开：",k+1);
        scanf("%d %d",&i,&j);		/*输入对应边起点序号和终点序号*/
	    while(i<1|| i>G.vexnum || j<1 || j>G.vexnum)
	    {
			printf("错误的边序号！,请重新输入i,j\n");
			scanf("%d %d",&i,&j);
		}
	    printf("请输入边的权值：");
	    getchar();
	    scanf("%d",&v);				/*输入边的权值*/
	    G.arcs[i-1][j-1] = v;
		G.arcs[j-1][i-1] = v;	/*无向图存储边权值,输入1代表下标0,所以要减1*/
	}
    return G;
}

/*比较求最小距离值,并返回对应下标*/
int MinValue(InterEdge ee[],int n)
{
    int i,j,k;
    for(j=0;j<n;j++)
    if(ee[j].value>0)
    {
		k=j;
		break;
    }
	for(j=1;j<n;j++)
	{
		if(ee[j].value>0 && ee[j].value<ee[k].value)
		{
			k=j;
		}
	}
    return k;
}

/*最小至成树的普里姆算法,以u为起始点,求用邻接矩阵表示的图G的最小生成树,然后输出*/
void Min_SpanTree(Mgraph G,int u)
{
	InterEdge ee[VexNum];
	int  cc=0,pp[VexNum*2];
	int k=0,i,j,s1,in;
	for(i=0;i<G.vexnum;i++)
	{  
		ee[i].adjvex=u;
		ee[i].value=G.arcs[u][i];
	}
	ee[u].value=0;
	for(i=1;i<G.vexnum;i++)			/*求最小生成树的(n一1)条边,n为顶点数G.vexnum*/
	{  
		k=MinValue(ee,G.vexnum);
		s1=ee[k].adjvex;			/*在一个顶点在U中,另一个顶点不在U中的边中,边(s1,k)是一条权值最小的边*/
		ee[k].value=0;				/*将顶点k加入到U中*/
		pp[cc]=s1;
		cc++;
		pp[cc]=k;
		cc++;			/*将最小生成树的一条边(sl,k)记录到数组PP中*/
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[k][j]<ee[j].value)
			{						/*调整最短路径,并保存下标*/
				ee[j].value=G.arcs[k][j];
				ee[j].adjvex=k;
			}
		}
	}
	printf("\n 最小生成树是:\n");
	for(i=0;i<2*(G.vexnum-1);i=i+2)
	{
		printf("(%2c,%2c);",G.vexs[pp[i]],G.vexs[pp[i+1]]);		/*最小生成树组成边输出*/
	}
} 

