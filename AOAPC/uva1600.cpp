/** /
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxm = 20 + 5;
const int maxn = 20 + 5;
const int maxk = 20 + 5;

int m, n, k;
int mp[maxm][maxn];
bool visit[maxm][maxn][maxk];
int offset_row[4] = {0, -1, 0, 1};
int offset_col[4] = { -1,0, 1, 0 };

struct Vertex
{
	int r, c, st;
	int lives;
	Vertex(int row, int col, int steps = 0, int l = k) : r(row), c(col), st(steps), lives(l) {}
	vector<Vertex> nbrs()
	{
		vector<Vertex> vs;
		for (int i = 0; i < 4; ++i)
		{
			Vertex v(r + offset_row[i], c + offset_col[i], st + 1, lives);
			if (v.r >= 0 && v.r < m && v.c >= 0 && v.c < n)
			{
				if (mp[v.r][v.c])
					v.lives--;
				else
					v.lives = k;
				if (v.lives >= 0)
					vs.push_back(v);
			}
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

		for (auto v : u.nbrs())
			if (!visit[v.r][v.c][v.lives])
			{
				Q.push(v);
				visit[v.r][v.c][v.lives] = true;
			}
	}
	return -1;
}

int main()
{
	int T;
	//ifstream fin("in");
	cin >> T;
	while (T--)
	{
		memset(visit, false, sizeof(visit));
		cin >> m >> n >> k;
		for (int r = 0; r < m; ++r)
			for (int c = 0; c < n; ++c)
				cin >> mp[r][c];

		cout << bfs() << endl;
	}
	return 0;
}
/**/