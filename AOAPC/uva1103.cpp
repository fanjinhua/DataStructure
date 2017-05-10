/** /
#include <cstdio>
#include <cstring>
const int maxh = 200 + 5, maxw = 50 + 5;
int h, w;
char matrix[maxh][maxw];

int main()
{
	while (scanf("%d%w", &h, &w) == 2 && h && w)
	{
		memset(matrix, 0, sizeof(matrix));
		for (int r = 0; r < h; ++r)
			scanf("%s", matrix[r]);

	}
}
/**/