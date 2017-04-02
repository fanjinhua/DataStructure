/** /
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	double M[10][31];
	double binary_m, decimal_m;
	double log10number;
	long long E[10][31];
	long long binary_e, decimal_e;
	int i, j;
	for (i = 0; i < 10; ++i)
	{
		binary_m = 1 - pow(2, -i - 1);
		for (j = 1; j < 31; ++j)
		{
			binary_e = pow(2, j) - 1;
			log10number = log10(binary_m) + binary_e*log10(2);
			decimal_e = floor(log10number);
			decimal_m = pow(10, log10number - decimal_e);
			M[i][j] = decimal_m;
			E[i][j] = decimal_e;
		}
	}

	char s[30];
	double m;
	int e;
	while (scanf("%s", s) == 1)
	{
		if (s == "0e0")
			return 0;
		s[17] = ' ';
		sscanf(s, "%lf %d", &m, &e);
		for (i = 0; i < 10; ++i)
			for (j = 0; j < 31; ++j)
				if (fabs(M[i][j] - m) < 1e-5 && E[i][j] == e)
					printf("%d %d\n", i, j);
	}
	return 0;
}
/**/