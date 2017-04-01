#include <cstdio>
#include <cstdlib>

int bin_search_left(int* A, int elem, int lo, int hi)
{
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		(A[mid] < elem) ? lo = mid + 1 : hi = mid;
	}
	return hi;
}

int bin_search_right(int* A, int elem, int lo, int hi)
{
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		(elem < A[mid]) ? hi = mid : lo = mid + 1;
	}
	return --lo;
}

int main()
{
	int len, queries, index;
	int elem, left, right;
	std::scanf("%d%d\n", &len, &queries);

	int* array = new int[len];

	for (index = 0; index != len; ++index)
	{
		std::scanf("%d", &elem);
		array[index] = elem;
	}
	std::qsort(array, len, sizeof(int), [](const void* a, const void* b) { return *static_cast<const int*>(a) - *static_cast<const int*>(b); });
	int* res = new int[queries];
	index = 0;

	for (index = 0; index < queries; ++index)
	{
		std::scanf("%d%d", &left, &right);
		res[index] = bin_search_right(array, right, 0, len) - bin_search_left(array, left, 0, len) + 1;
	}
	index = 0;
	while (index < queries - 1)
		std::printf("%d\n", res[index++]);
	std::printf("%d", res[index]);
	delete[] array;
	delete[] res;
	return 0;
}
