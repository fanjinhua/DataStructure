/**/
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int dr[] = { -1, -2, -2, -1, 1, 2,  2,  1 };
int dc[] = {-2, -1,  1,  2, 2, 1, -1, -2 };

struct node
{
	int x, y;
	int steps;
}a, nex;

int mp[13][13];
int ans;
char s[10];

int mx[] = { 0, -2, -1,  1,  2, 2, 1, -1, -2 };
int my[] = { 0, -1, -2, -2, -1, 1, 2,  2,  1 };

int BFS()
{
	memset(mp, 0, sizeof(mp));
	queue<node> q;
	a.x = s[0] - 'a' + 1;
	a.y = s[1] - '0';
	a.steps = 0;
	q.push(a);
	while (!q.empty())
	{
		nex = q.front();
		q.pop();
		if (nex.x == s[3] - 'a' + 1 && nex.y == s[4] - '0')
			return nex.steps;
		for (int i = 1; i < 9; ++i)
		{
			int x = nex.x + mx[i];
			int y = nex.y + my[i];
			if (x > 0 && x < 9 && y > 0 && y < 9 && !mp[x][y])
			{
				mp[x][y] = 1;
				a.x = x;
				a.y = y;
				a.steps = nex.steps + 1;
				q.push(a);
			}
		}
	}
}

int main()
{
	FILE* fin = fopen("in","r");
	
	while (fgets(s, 10, fin) != NULL)
		printf("To get from %c%c to %c%c takes %d knight moves.\n", s[0], s[1], s[3], s[4], BFS());
	return 0;
}

/**/