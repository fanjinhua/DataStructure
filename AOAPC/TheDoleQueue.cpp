/** /
#include <stdio.h>	
#define maxn 25
int n, k, m, a[maxn];

int go(int pos, int step, int nsteps)
{
	while (nsteps--)
	{
		do
		{
			pos = (pos + step + n - 1) % n + 1;
		} while (a[pos] == 0);
	}
	return pos;
}

int main()
{
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
	{
		for (int i = 1; i <= n; i++)
			a[i] = i;
		int left = n;
		int p1 = n, p2 = 1;
		while (left)
		{
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1); left--;
			if (p2 != p1) {	printf("%3d", p2); left--; }
			a[p1] = a[p2] = 0;
			if (left)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}
/**/