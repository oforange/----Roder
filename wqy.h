#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
#ifndef _A_
#define _A_
class Graph
{
public:
	int get_length(int a,int b);	//获得结点间的距离
	void add_Edges();				//从文件读入邻接矩阵
	int Max_vertexs;				//存储点的最大数目
	void get_Max_vertexs();			//获取点的最大数目
	const int Max_dis = 16;
	void inc_Edges(int x);
	void del_list(int a, int b);
	Graph();
	~Graph();

private:
	int **ptr;
};
#endif _A_