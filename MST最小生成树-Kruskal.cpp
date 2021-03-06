// MST最小生成树-Kruskal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct  edge
{
	int u, v, w;//边的2个顶点  权值
}edges[100];
int parent[100];//parent[i]用户并查集

int n, m;//顶点数目，边的数目
int i, j;
void UFSet()//初始化
{
	for (i = 0; i < n; i++)
		parent[i] = i;
}
int Find(int x)  //查找x节点的根
{
	if (x == parent[x])
		return x;
	int result = Find(parent[x]);//递归查找结果，递归返回前，先路径压缩
	parent[x] = result;
	return result;
}
void Union(int r1, int r2)
{
	int R1 = Find(r1);
	int R2 = Find(r2);
	parent[R1] = R2;
}
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

void Kruskal()
{
	int sum = 0;
	int num = 0;//记录所选的边数目 不超过n-1
	int u, v;
	UFSet();//初始化并查集
	int the_num=0;
	for (i = 0; i < m; i++)
	{
		u = edges[i].u;
		v = edges[i].v;
		if (Find(u) != Find(v))  //如果不在同一颗树上，那么合并它们
		{
			cout << u <<" "<< v<<" " << edges[i].w << endl;
			sum += edges[i].w;
			Union(u, v);
			the_num++;
		}
		if(the_num==n-1)
			break;

	}
	cout << " " << sum << endl;
}


int main()
{

	int u, v, w;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >>edges[i].u >>edges[i].v >>edges[i].w;
		
	}
	sort(edges, edges + m, cmp);
	Kruskal();
    return 0;
}

