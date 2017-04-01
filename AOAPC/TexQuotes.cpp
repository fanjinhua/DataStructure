/** /
#include <stdio.h>

int main(void)
{
	int ch, flag = 1;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '"')
		{
			printf("%c", flag ? "``" : "''");
			flag = !flag;
		}
		else
			printf("%c", ch);
	}
	return 0;
}
/**/