/*
	P(n) = {  
			  1						n = 0;
			  2						n = 1;
			  2p(n-1)-2(n-1)p(n-2)  n > 1; 
			}
*/
const int maxn = 1000;
struct stackframe
{
	int val;
};

int p(int n)
{
	stackframe sf[maxn];
	sf[0].val = 1;
	sf[1].val = 2;
	for (int i = 3; i <= n; ++i)
		sf[i].val = 2 * sf[i - 1].val - 2 * (i - 1)*sf[i - 2].val;
	return sf[n].val;
}
