/** /
#include <stdio.h>
#include <string.h>
#define maxn 105

int less(const char*s, int p, int q)
{
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
		if (s[(p + i) % n] != s[(q + i) % n])
			return s[(p + i) % n] < s[(q + i) % n];
	return 0;  // equal
}

int main(void)
{
	int T;
	char s[maxn];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int len = strlen(s);
		int start_pos = 0;
		for (int i = 0; i < len; ++i)
			if (less(s, i, start_pos))
				start_pos = i;
		for (int i = 0; i < len; ++i)
			putchar(s[(start_pos + i) % len]);
		putchar('\n');
	}
	return 0;
}
/**/