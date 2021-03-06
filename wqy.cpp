#include"wqy.h"

int Graph::get_length(int a, int b){
	return ptr[a][b];
}

void Graph::add_Edges(){
	int count1 = 0;
	int count2 = 0;
	fstream infile("Graph_edges.txt", ios::in);
	if (!infile){
		cerr << "open error!" << endl;
		exit(1);
	}
	ptr = new int*[Max_vertexs];
	while (count1<Max_vertexs){
		ptr[count1] = new int[Max_vertexs];
		count1++;
	}
	for (count1 = 0; count1 < Max_vertexs; count1++){
		for (count2 = 0; count2 < Max_vertexs; count2++){
			infile >> ptr[count1][count2];
		}
	}
}

void Graph::get_Max_vertexs(){
	fstream infile("Graph_edges.txt", ios::in);
	int a;
	if (!infile){
		cerr << "open error!" << endl;
		exit(1);
	}
	while (!infile.eof()){
		infile >> a;
		Max_vertexs++;
	}
	Max_vertexs =(int) sqrt(Max_vertexs);
}
void Graph::inc_Edges(int x){
	fstream infile("Graph_edges.txt", ios::out);
	int i = 0, j = 0;
	if (!infile){
		cerr << "open error!" << endl;
		exit(1);
	}
	for (i=0; i < Max_vertexs; i++){
		if (i != x)
			for (j = 0; j < Max_vertexs; j++){
			if (j != x){
				if (j != Max_vertexs - 1)
					infile << ptr[i][j] << "	";
				else
					infile << ptr[i][j] << endl;
			}
			else if (j == x){
				if (j != Max_vertexs - 1)
					infile << Max_dis << "	";
				else
					infile << Max_dis << endl;
			}
			}
		if (i == x){
			for (j = 0; j < Max_vertexs; j++){
				if (j != Max_vertexs - 1)
					infile << Max_dis << "	";
				else
					infile << Max_dis << endl;
			}
		}
	}
}
void Graph::del_list(int a, int b){
	fstream infile("Graph_edges.txt", ios::out);
	int i = 0, j = 0;
	if (!infile){
		cerr << "open error!" << endl;
		exit(1);
	}
	for (i = 0; i < Max_vertexs; i++){
		if (i != a&&i != b)
			for (j = 0; j < Max_vertexs; j++){
			if (j != Max_vertexs - 1)
				infile << ptr[i][j] << "	";
			else
				infile << ptr[i][j] << endl;
			}
		else if (i == a){
			for (j = 0; j < Max_vertexs; j++){
				if (j == b){
					if (j != Max_vertexs - 1)
						infile << Max_dis << "	";
					else
						infile << Max_dis << endl;
				}
				else{
					if (j != Max_vertexs - 1)
						infile << ptr[i][j] << "	";
					else
						infile << ptr[i][j] << endl;
				}

			}
		}
		else if (i == b){
			for (j = 0; j < Max_vertexs; j++){
				if (j == a){
					if (j != Max_vertexs - 1)
						infile << Max_dis << "	";
					else
						infile << Max_dis << endl;
				}
				else{
					if (j != Max_vertexs - 1)
						infile << ptr[i][j] << "	";
					else
						infile << ptr[i][j] << endl;
				}

			}
		}
	}
}


Graph::Graph()
{
	get_Max_vertexs();
}

Graph::~Graph()
{
	delete []ptr;
}