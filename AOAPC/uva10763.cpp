/** /
#include <cstdio>
#include <algorithm>
const int maxn = 500000 + 10;
int cand[maxn];
int target[maxn];

int main()
{
	int n;
	FILE* fin = fopen("in", "r");
	while (fscanf(fin, "%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
			fscanf(fin, "%d %d", cand + i, target + i);
		
		std::sort(cand, cand + n);
		std::sort(target, target + n);
		int i;
		for (i = 0; i < n; ++i)
			if (cand[i] != target[i])
			{
				printf("NO\n");
				break;
			}
		if (i == n)
			printf("YES\n");
	}
	return 0;
}
/**/