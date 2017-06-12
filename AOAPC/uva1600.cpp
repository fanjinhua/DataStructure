/**/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxm = 20 + 5;
const int maxn = 20 + 5;
int m, n, k;
int mp[maxm][maxn];
int or[] = { 0,-1, 0, 1 };
int oc[] = { -1,0, 1, 0 };

struct Vertex
{
	int r, c, st;
	int visited;
	Vertex(int row, int col, int steps = 0, int v = 0) : r(row), c(col), st(steps), visited(v) {}
	vector<Vertex> next()
	{
		vector<Vertex> vs;
		int row, col;
		for (int i = 0; i < 4; ++i)
		{
			row = r + or [i];
			col = c + oc[i];
			if (row >= 0 && row < m && col >= 0 && col < n)
				vs.push_back(Vertex(row, col));
		}
		return vs;
	}
};
int bfs()
{
	queue<Vertex> Q;
	Q.push(Vertex(0, 0));
	while (!Q.empty())
	{
		Vertex u = Q.front(); Q.pop();
		if (u.r == m - 1 && u.c == n - 1)
			return u.st;
		auto vs = u.next();

	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> m >> n >> k;
		for (int r = 0; r < m; ++r)
			for (int c = 0; c < n; ++c)
				cin >> mp[r][c];

		cout << bfs() << endl;
	}
	return 0;
}
/**/