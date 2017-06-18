/** /
#include <algorithm>


int main()
{
	int n = 10;
	int p[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::sort(p, p + n);
	do
	{
		for (int i = 0; i < n; ++i)
			std::cout << p[i] << " ";
		std::cout << std::endl;
	} while (std::next_permutation(p, p + n));
	return 0;
}
#include <iostream>
void print_permutation(int n, int* A, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; ++i)
			std::cout << A[i];
		std::cout << std::endl;
	}
	for (int i = 1; i <= n; ++i)
	{
		int ok = 1;
		for (int j = 0; j < cur; ++j)
			if (A[j] == i)
				ok = 0;
		if (ok)
		{
			A[cur] = i;
			print_permutation(n, A, cur + 1);
		}
	}
}

int main()
{
	int a[5] = { 7, 8, 9, 22, 6 };
	print_permutation(5, a, 0);
	return 0;
}
/**/
