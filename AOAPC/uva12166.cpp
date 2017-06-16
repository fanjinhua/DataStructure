/** /
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

char expr[1048576];
map<long long, int> R;
void dfs(int l, int r, int dep) 
{
	if (expr[l] == '[') 
	{
		int p = 0;
		for (int i = l + 1; i <= r - 1; i++) 
		{
			if (expr[i] == '[')	
				p++;
			if (expr[i] == ']')	
				p--;
			if (p == 0 && expr[i] == ',') 
			{
				dfs(l + 1, i - 1, dep + 1);
				dfs(i + 1, r - 1, dep + 1);
			}
		}
	}
	else 
	{
		int w;
		expr[r + 1] = '\0';
		sscanf(expr + l, "%d", &w);
		R[(long long)w << dep]++;
	}
}
int main() {
	int testcase;
	FILE* fin = fopen("in", "r");
	fscanf(fin, "%d", &testcase);
	while (testcase--) 
	{
		fscanf(fin, "%s", expr);
		R.clear();
		dfs(0, strlen(expr) - 1, 0);
		int sum = 0, mx = 0;
		for (map<long long, int>::iterator it = R.begin(); it != R.end(); it++)
			sum += it->second, mx = max(mx, it->second);
		printf("%d\n", sum - mx);
	}
	return 0;
}
/**/