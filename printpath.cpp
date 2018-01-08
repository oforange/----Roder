#include "Graph.h" 
void Graph::printpath(Graph &g, int dist[], int path[], int v)            //起始路由表序号，目的路由表序号
{
	
	int i, j, k, sign;
	sign = 0;
	int n = g.Max_vertexs;
	int *d = new int[n];
	for (i = 0; i < n; i++)
	{
		if(i != v)
		{
			k = i;
			if (path[i] != -1)
			{
				while (1)
				{
					j = path[k];
					if (j == v)
					{
						cout << "从路由器" << v + 1 << "到" << i + 1 << "路由器的下一跳为：" << k + 1 << endl;
						sign++;
						break;
					}
					if (j != v)
					{
						k = j;
					}
				}
			}
		}
	}
	if(sign==0)
		cout << "该路由器不存在或已被删除！" << endl;
}
