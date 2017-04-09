/** /
#include <cstdlib>
#include <cstdio>
using namespace std;
const int maxn = 15+5;
int ducci[maxn];

int main()
{
	int T;
	FILE* fin = fopen("in", "r");
	fscanf(fin, "%d", &T);
	while (T--)
	{
		int n;
		fscanf(fin, "%d", &n);
		for (int i = 0; i < n; ++i)
			fscanf(fin, "%d", ducci + i);
		int zero_num;
		for (int step = 0; step <= 1000; ++step)
		{
			int head = ducci[0];
			for (int i = 0; i < n - 1; ++i)
				ducci[i] = abs(ducci[i] - ducci[i + 1]);
			ducci[n - 1] = abs(ducci[n - 1] - head);
			for (zero_num = 0; ducci[zero_num] == 0 && zero_num < n; ++zero_num)
					;
			if (zero_num == n)
			{
				printf("ZERO\n");
				break;
			}
		}
		if (zero_num != n)
			printf("LOOP\n");
	}
	return 0;
}
/**/