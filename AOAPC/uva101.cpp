/** /
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];

void put_above(int a, int b)
{
	pile[b].insert(pile[b].end(), pile[a].begin(), pile[a].end());
	pile[a].clear();
}

void find_block(int a, int& p, int& h)
{
	for (p = 0; p < n; ++p)
		for (h = 0; h < pile[p].size(); ++h)
			if (pile[p][h] == a)
				return;
}

void clear_above(int p, int h)
{
	for (int i = h + 1; i < pile[p].size(); ++i)
	{
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h + 1);
}

void pile_onto(int p, int h, int p2)
{
	for (int i = h; i < pile[p].size(); ++i)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);
}

int main()
{
	int a, b;
	n = 10;//scanf("%d", &n);
	string s1, s2;
	for (int i = 0; i < n; ++i)
		pile[i].push_back(i);
	stringstream ss(string("move 9 onto 1\nmove 8 over 1\nmove 7 over 1\nmove 6 over 1\npile 8 over 6\npile 8 over 5\nmove 2 over 1\nmove 4 over 9\nquit"));
	
	while (ss >> s1 >> a >> s2 >> b, s1 != "quit")
	{
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if (pa == pb)
			continue;
		if (s2 == "onto")
			clear_above(pb, hb);
		if (s1 == "move")
			clear_above(pa, ha);
		pile_onto(pa, ha, pb);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d: ", i);
		for (int f: pile[i])
			printf(" %d", f);
		printf("\n");
	}
	return 0;
}
/**/