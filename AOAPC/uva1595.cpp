/**/
#include <cstdio>
#include <algorithm>
#include <utility>
const int maxn = 1000 + 10;

struct Pair
{
	int first;
	int second;

	Pair& operator=(const Pair& right)
	{
		first = right.first;
		second = right.second;
		return *this;
	}
};

Pair dot[maxn];
void quick_sort_recursive(Pair* arr, int start, int end)
{
	if (start >= end) return;
	Pair mid = arr[end];
	int left = start, right = end - 1;
	while (left < right)
	{
		while (arr[left].first < mid.first && left < right) left++;
		while (arr[right].first >= mid.first && left < right) right++;
		Pair temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	if (arr[left].first >= arr[end].first)
	{
		Pair temp = arr[left];
		arr[left] = arr[end];
		arr[end] = temp;
	}
	else left++;

	quick_sort_recursive(arr, start, left + 1);
	quick_sort_recursive(arr, left + 1, end);
}

int main()
{
	int T, n;
	FILE* fin = fopen("in", "r");
	fscanf(fin, "%d", &T);
	while (T--)
	{
		fscanf(fin, "%d", &n);
		if (n == 1)
		{
			printf("YES\n");
			continue;
		}
		for (int i = 0; i < n; ++i)
			fscanf(fin, "%d %d", &dot[i].first, &dot[i].second);
		quick_sort_recursive(dot, 0, n - 1);

		double midx = n % 2 ? static_cast<double>(dot[n / 2].first) : \
			static_cast<double>((dot[n / 2 - 1].first + dot[n / 2].first) / 2);
		
		bool symmetry = true;
		for (int h = 0, t = n - 1; h < n && t >= 0; ++h, --t)
			if (dot[h].second != dot[t].second || (dot[h].first + dot[t].first != 2 * midx))
			{
				printf("NO\n");
				symmetry = false;
				break;
			}
		if (symmetry) printf("YES\n");
	}
	return 0;
}
/**/