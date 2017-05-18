/**/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
int dr[] = { -1, -2, -2, -1, 1, 2,  2,  1 };
int dc[] = { -2, -1,  1,  2, 2, 1, -1, -2 };

struct Vertex
{
	Vertex() = default;
	Vertex(int r, int c) : r(r), c(c) {}
	Vertex& operator=(const Vertex& v)
	{
		r = v.r;
		c = v.c;
		return *this;
	}
	bool operator==(const Vertex& v)
	{
		return r == v.r && c == v.c;
	}
	bool operator<(const Vertex& v)
	{
		return r < v.r;
	}
	int r, c;

};

Vertex src, dest;
vector<Vertex> label;

#define LEGAL(r, c) ((r) >= 0 && (r) <= 8 && (c) >= 0 && (c) <= 8)

vector<Vertex> next(Vertex u)
{
	int r = u.r, c = u.c;
	vector<Vertex> nbs;
	for (int i = 0; i < 8; ++i)
		if (LEGAL(r + dr[i], c + dc[i]))
			nbs.push_back(Vertex(r + dr[i], c + dc[i]));

	return nbs;
}

int bfs()
{
	queue<Vertex> Q;
	Q.push(src);
	int steps = -1;
	if (src == dest)
		return 0;
	while (!Q.empty())
	{
		Vertex u = Q.front(); Q.pop();
		for (Vertex v : next(u))
		{
			if (std::find(label.begin(), label.end(), v) == label.end())
			{
				if (v == dest)
					return steps;
				label.push_back(v);
				Q.push(v);
			}
		}
		steps++;
	}
	return -1;
}

int main()
{
	string a, b;
	ifstream fin("in");
	while (fin >> a >> b)
	{
		src.r = a[1] - '0', src.c = b[0] - 'a' + 1;
		dest.r = b[1] - '0', dest.c = b[0] - 'a' + 1;
		cout << "To get from " << a << " to " << b << " takes " << \
			bfs() << " knight moves." << endl;
	}
	return 0;
}

/**/