/**/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const int inf = 1000000000;
const int maxn = 500 + 5;
int n, m, from, to;
bool vis[maxn];
int w[maxn][maxn], num[maxn], teams[maxn], dist[maxn], way[maxn];

void dijkstra(int s) 
{
	for (int i = 0; i < n; ++i) 
	{
		dist[i] = inf;
		vis[i] = false;
		num[i] = way[i] = 0;
	}
	num[s] = teams[s];
	way[s] = 1;
	dist[s] = 0;
	for (int j = 0; j < n; ++j) 
	{
		int k = -1;
		int m = inf;
		for (int i = 0; i < n; ++i) 
			if ((!vis[i]) && (dist[i] <= m))
				m = dist[k = i];

		vis[k] = true;

		for (int i = 0; i < n; ++i) 
			if (dist[k] + w[k][i] < dist[i])
			{
				dist[i] = dist[k] + w[k][i];
				num[i] = num[k] + teams[i];
				way[i] = way[k];
			}
			else if (dist[k] + w[k][i] == dist[i])
			{
				num[i] = max(num[k] + teams[i], num[i]);
				way[i] += way[k];
			}

	}
}

int main()
{
	ifstream fin("patin");
	fin >> n >> m >> from >> to;
	
	for (int i = 0; i < n; ++i)
	{
		fin >> teams[i];
		for (int j = 0; j < n; ++j)
			w[i][j] = inf;
	}

	for (int i = 0; i < m; ++i)
	{
		int n1, n2, wight;
		fin >> n1 >> n2 >> wight;
		w[n1][n2] = w[n2][n1] = min(w[n1][n2], wight);
	}
	
	dijkstra(from);
	cout << way[to] << " " << num[to];
	return 0;
}
/**/