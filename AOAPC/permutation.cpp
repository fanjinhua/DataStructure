/** /
#include <algorithm>
#include <iostream>

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
/**/

void print_permutation(int n, int* A, int cur)
{

	for (int i = 0; i < n; ++i)
	{
		print_permutation(n, A, i);
	}
}