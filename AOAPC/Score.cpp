/** /
#include <stdio.h>
#include <string.h>
#define maxn 85

int main(void)
{
	int T, score, flag;
	char s[maxn];
	scanf("%d", &T);
	while (T--)
	{
		score = flag = 0;
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == 'O')
				score += (1 + flag++);
			else
				flag = 0;
		}
		printf("%d\n", score);
	}
	return 0;
}
/**/