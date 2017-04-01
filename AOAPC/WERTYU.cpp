/** /
#include <stdio.h>

static char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(void)
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		int i;
		for (i = 1; s[i] && s[i] != ch; ++i);
		if (s[i])
			putchar(s[i - 1]);
		else
			putchar(ch);
	}
	return 0;
}
/**/