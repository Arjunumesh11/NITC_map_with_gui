#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include"shortestpath.h"
#include".\plplot\plstream.h"
using namespace std;
typedef pair<int, int> pii;							// pair int
typedef vector< pii > vii;							// vector of pair int int
int main()
{
	int N, M, u, v, w, source, destination;
	vector<string> place;
	vector<int> *map_direction;					   // array of vector containing the shortest map
	vector<pair<int, int>> *G;					   // edge matrixwith weighted edge
	string name_place; int index_place;            // temp var for cin
	ifstream fin("map_coordinate.txt");
	fin >> N;
	auto pls = new plstream();
	plsdev("wingcc");
	pls->init();
	plschr(0, 0.5);
	pls->env(0, 90, 0, 90, 0, -1);
	map_direction = new vector<int>[N];
	double *x = new double[N],*y = new double[N],n=N;
	fin >> M;
	G = new vii[N + 1];
	for (int i = 0; i < N; i++)
	{
		fin >> index_place; fin >> name_place;
		place.push_back(name_place);
		fin >> x[i]; x[i] *= 2;
		fin >> y[i]; y[i] *= 3;
		pls->ptex(x[i] + 1, y[i], 0, 0, 0, name_place.substr(0,4).c_str());
	}
	pls->poin(n, x, y, -1);
	for (int i = 0; i < M; ++i)
	{
		fin >> u;
		fin >> v;
		//fin >> w;
		w = int(sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v])));
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
		//pls->join(x[u], y[u], x[v], y[v]);
	}

	cout << "Enter source : \n";
	for (int i = 0; i < N; i++)
	{
		cout << endl << i << " . " << place[i];
	}
	cout << endl << "Enter no 0-" << N - 1 << " : ";
	cin >> source;
	system("CLS");
	make_path(G,source, N,map_direction);
	cout << endl << "Enter destination : \n";
	for (int i = 0; i < N; i++)
	{
		cout << endl << i << " . " << place[i];
	}
	cout << endl << "Enter no 0-" << N - 1 << " : ";
	cin >> destination;
	fin.close();
	system("CLS");
	cout << endl << endl << endl;
	for (int i = 0; i < map_direction[destination].size() - 1; i++)
	{
		cout << place[map_direction[destination][i]] << " -> ";
		pls->join(x[map_direction[destination][i]], y[map_direction[destination][i]], x[map_direction[destination][i+1]], y[map_direction[destination][i+1]]);
	}
	cout << place[map_direction[destination].back()];
	cin.get();
	cin.get();
	return 0;

	//pls->line(NSIZE, x_input, y_input);
	//delete pls;
	//pls->clear();
	plend;
	std::cin.get();
}