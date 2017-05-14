/**/
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 200 + 10;
int n;
char buf[maxn][maxn];

void solve()
{
	n = 0;
	for (;;)
	{
		fgets(buf[n], maxn, stdin);
		if (buf[n][0] = '#')
			break;
		else
			n++;
	}
	printf("(");
	if (n)
	{
		for (int i = 0; i < strlen(buf[0]); i++)

	}
}

int main()
{
	int T;
	fgets(buf[0], maxn, stdin);
	sscanf(buf[0], "%d", &T);
	while (T--)
		solve();
	return 0;
}
/**/