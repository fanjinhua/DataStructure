/** /
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
typedef std::pair<int, int> dot;

int main()
{
	int T, n;
	std::vector<dot> dots;

	FILE* fin = fopen("in", "r");
	fscanf(fin, "%d", &T);
	while (T--)
	{
		dots.clear();
		fscanf(fin, "%d", &n);
		if (n == 1)
		{
			printf("YES\n");
			continue;
		}

		for (int i = 0; i < n; ++i)
		{
			int x, y;
			fscanf(fin, "%d %d", &x, &y);
			dots.push_back(dot(x, y));
		}
		std::sort(dots.begin(), dots.end());

		double midx = n % 2 ? static_cast<double>(dots[n / 2].first) : \
			static_cast<double>(dots[n / 2 - 1].first + dots[n / 2].first) / 2;
		
		bool symmetry = true;
		for (int h = 0, t = dots.size() - 1; h < t; ++h, --t)
		{
			dot except = dot(dots[h].first + 2 * (midx-dots[h].first), dots[h].second);
			int p = std::lower_bound(dots.begin(), dots.end(), except) - dots.begin();
			if (dots[p] != except)
			{
				printf("NO\n");
				symmetry = false;
				break;
			}
		}
		if (symmetry) printf("YES\n");
	}
	return 0;
}
/**/