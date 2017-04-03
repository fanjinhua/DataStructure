/**/
// only sample passed.
#include <stdio.h>	
#include <string.h>
#define maxn 1010
int ips[maxn][4];
int mask[4] = { 255, 255, 255, 255 };
int net_add[4] = { 0, 0, 0, 0 };

int find_firstdiff(int T)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < T; ++j)
			if (ips[j][i] != ips[0][i])
				return i;
	return 3;
}

int main()
{
	int T;
	//memset(ips, 0, sizeof(ips));
	char* debug[3] = { "194.85.160.177", "194.85.160.183", "194.85.160.178"};

	//if (T = 3) //
	while (scanf("%d", &T) != EOF)
	{
		for (int i = 0; i < T; ++i)
			scanf("%d.%d.%d.%d", &ips[i][0], &ips[i][1], &ips[i][2], &ips[i][3]);
			 //sscanf(debug[i], "%d.%d.%d.%d", &ips[i][0], &ips[i][1], &ips[i][2], &ips[i][3]);

		int k = find_firstdiff(T);
		int maxi = 0, mini = 0;
		for (int i = 1; i < T; ++i)
		{
			if (ips[maxi][k] < ips[i][k])
				maxi = i;
			if (ips[i][k] < ips[mini][k])
				mini = i;
		}

		int mask_bit = 0; 
		int r = ips[mini][k] ^ips[maxi][k];
		while (r)
		{
			r >>= 1;
			mask_bit++;
		}
		mask[k] = mask[k] >> mask_bit << mask_bit;
		if (k < 3)
			for (int i = k + 1; i < 4; ++i)
				mask[i] = 0;

		for (int i = 0; i <= k; ++i)
			net_add[i] = ips[mini][i];
		net_add[k] = net_add[k] >> mask_bit << mask_bit; // or net_add[i-1], not net_add[i]

		printf("%d.%d.%d.%d\n", net_add[0], net_add[1], net_add[2], net_add[3]);
		printf("%d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
	}
	return 0;
}
/**/