/** /
#include <fstream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int T;
	FILE* fin = fopen("in", "r");
	fscanf(fin, "%d", &T);
	while (T--)
	{
		int n, m;
		fscanf(fin, "%d %d", &n, &m);
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int pri;
		for (int i = 0; i < n; ++i)
		{
			fscanf(fin, "%d", &pri);
			q.push(make_pair(pri, i));
			pq.push(pri);
		}

		pair<int, int> now;
		int time = 0;
		while (1)
		{
			now = q.front(), q.pop();
			if (now.first == pq.top())
			{
				time++;
				pq.pop();
				if (now.second == m)
				{
					printf("%d\n", time);
					break;
				}
			}
			else
				q.push(now);
		}
	}
	return 0;
}
/**/