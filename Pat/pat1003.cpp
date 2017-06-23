/**/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
const int inf = 11111111;
const int maxn = 500 + 5;
int w[maxn][maxn];
int n, m, c1, c2;
int teams[maxn], vis[maxn], dist[maxn], path[maxn];
 
int main()
{
	ifstream fin("patin");
	fin >> n >> m >> c1 >> c2;
	memset(vis, 0, sizeof(vis));
	
	for (int i = 0; i < n; ++i)
	{
		dist[i] = inf;
		teams[i] = 0;
		path[i] = -1;
		for (int j = 0; j < n; ++j)
			w[i][j] = inf;
	}

	for (int i = 0; i < n; ++i) fin >> teams[i];
	for (int i = 0; i < m; ++i)
	{
		int n1, n2;
		fin >> n1 >> n2;
		fin >> w[n1][n2];
	}
	for (int i = 0; i < n; ++i)
	{
		dist[i] = w[c1][i];
		if (dist[i] != inf)
			path[i] = c1;
	}
	dist[c1] = 0;

	for (int i = 0; i < n; ++i)
	{
		int x, smallest = inf;
		for (int c = 0; c < n; ++c)
			if (!vis[c] && dist[c] <= smallest)
				smallest = dist[x = c];
		vis[x] = 1;
		for (int c = 0; c < n; ++c)
			if (w[x][c] != inf)
			{
				dist[c] = min(dist[c], dist[x] + w[x][c]);
				path[i] = x;
			}
	}

	int tms = teams[c1];
	for (int i = path[c2]; i != c1; i = path[i])
	{
		tms += teams[i];
		cout << i << " ";
	}
	cout << endl;
	cout << dist[c2] << " " << tms;
	return 0;
}
/**/
