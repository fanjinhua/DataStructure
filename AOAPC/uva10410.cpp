/** /
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

const int maxn = 1000 + 5;

int pos[maxn];
vector<int> g[maxn];
int main()
{
	int n;
	ifstream fin("in");
	while (fin >> n)
	{
		for (int i = 1; i <= n; ++i)
		{
			int x;
			fin >> x;
			pos[x] = i;
			g[x].clear();
		}
		
		int root;
		fin >> root;
		stack<int> s;
		s.push(root);
		for (int i = 1; i < n; ++i)
		{
			int v;
			fin >> v;

			while (1)
			{
				int u = s.top();
				if (u == root || pos[u] + 1 < pos[v]) //u��v�ĸ����
				{
					g[u].push_back(v);
					s.push(v);
					break;
				}
				else //u��v���ֵ� ���ص�u�ĸ���� 
					s.pop();
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			cout << i << ":";
			for (int j = 0; j < g[i].size(); ++j)
				cout << " " << g[i][j];
			cout << endl;
		}
	}
	
	return 0;
}
/**/