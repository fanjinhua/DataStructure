/** /
#include <cstdio>
const int maxn = 1000 + 10;
int IPs[maxn][4];
int find_firstdiff(int m) {
	for (int i = 0; i<4; i++)
		for (int j = 0; j<m; j++)
			if (IPs[j][i] != IPs[0][i])return i;
	return 3;
}

void printIP(int ser, int equ, int k) {
	int is_first = 0;
	for (int i = 0; i<4; i++)
	{
		if (is_first)
			printf("."); 
		else 
			is_first = 1;

		if (i == k)
			printf("%d", equ);
		else if (i<k) 
			printf("%d", ser == -1 ? IPs[0][i] : ser);
		else 
			printf("0");
	}
	printf("\n");
}
int main() {
	int m;
	char* debug[5] = { "194.85.160.177", "194.85.163.183", "194.85.165.178", "194.85.153.123", "194.85.170.145" };
	if (m = 1) //while (scanf("%d", &m) != EOF) 
	{
		for (int i = 0; i < m; i++)
			sscanf(debug[i], "%d.%d.%d.%d", &IPs[i][0], &IPs[i][1], &IPs[i][2], &IPs[i][3]);
		int k = find_firstdiff(m);
		int maxi = 0, mini = 0;
		for (int i = 0; i < m; i++) {
			if (IPs[maxi][k] < IPs[i][k])maxi = i;
			if (IPs[mini][k] > IPs[i][k])mini = i;
		}

		int mask_bit = 0, mask = IPs[maxi][k];
		if (maxi != mini) 
		{
			int d = IPs[maxi][k] ^ IPs[mini][k];
			mask_bit = 0;
			if (!d)
				mask_bit = 1;
			else 
				while (d) 
				{
					d /= 2;
					mask_bit++;
				}
			mask = IPs[maxi][k] >> mask_bit << mask_bit;
		}
		printIP(-1, mask, k);
		printIP(255, 256 - (1 << mask_bit), k);
	}
	return 0;
}
/**/