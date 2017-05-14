/** /
#include <cstdio>
#include <cstring>
const int maxn = 100000 + 5;
const int vern = 26;
int G[vern][vern];
int in_dgr[vern];
int o_dgr[vern];

bool euler(int u)
{
	for (int v = 0; v < vern; ++v)
	{
		if (G[u][v])
		{

		}
	}
	return true;
}

int main()
{
	int T, N; 
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		memset(G, 0, sizeof(G));
		memset(in_dgr, 0, sizeof(in_dgr));
		char* word;
		while (N--)
		{
			scanf("%s", word);
			int head = *word - 'a';
			int tail = *(word + strlen(word) - 1) - 'a';
			G[head][tail] = 1;
		}

		euler();
	}
}
/**/