/**/
#include <stdio.h>	
#include <string.h>
#define maxn 1000
char ip[32];
char mask[32];
char* ips[maxn];

int main()
{
	int T, binary, seg = 0;
	char each_ip[24];
	memset(each_ip, 0, sizeof(each_ip));
	scanf("%d", &T);
	memset(ips, 0, sizeof(ips));
	while (T--)
	{
		int ch;
		for (int i = 0; i < 4; ++i)
		{
			while ((ch = getchar()) != '.')
				seg = seg * 10 + ch;
			while (seg > 0)
			{
				binary = seg & 1;
				seg >> 1;
			}
			
			//sprintf(each_ip + i * 8, "%");
		}

	}
}


/**/