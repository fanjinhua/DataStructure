/** /
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int maxn = 8 + 2;
int id[256], letter[maxn];

int main()
{
	FILE* fin = fopen("in", "r");
	char input[1000];
	while (fscanf(fin, "%s", input) == 1 && input[0] != '#')
	{
		int n = 0;
		for (char ch = 'A'; ch <= 'Z'; ch++)
			if (strchr(input, ch) != NULL)
			{
				id[ch] = n++;
				letter[id[ch]] = ch;
			}

		int len = strlen(input), p = 0, q = 0;
		std::vector<int> u, v;
		for (;;)
		{
			while (p < len && input[p] != ':') p++;
			if (p == len) break;
			while (q < len && input[q] != ';') q++;
			for (int i = p + 1; i < q; ++i)
			{
				u.push_back(id[input[p - 1]]);
				v.push_back(id[input[i]]);
			}
			p++; q++;
		}

		// 枚举全排列
		int P[maxn], bestP[maxn], pos[maxn], ans = n;
		for (int i = 0; i < n; i++) P[i] = i;
		do 
		{
			for (int i = 0; i < n; i++) pos[P[i]] = i; // 每个字母的位置
			int bandwidth = 0;
			for (int i = 0; i < u.size(); i++)
				bandwidth = std::max(bandwidth, abs(pos[u[i]] - pos[v[i]])); // 计算带宽
			if (bandwidth < ans) 
			{
				ans = bandwidth;
				memcpy(bestP, P, sizeof(P));
			}
		} while (std::next_permutation(P, P + n));

		for (int i = 0; i < n; ++i)
			printf("%c ", letter[bestP[i]]);
		printf("-> %d\n", ans);
	}
	return 0;
}
/**/