/** /
#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <cassert>
using namespace std;

const int maxr = 10000 + 10;
const int maxc = 10 + 5;
int db[maxr][maxc];
map<string, int> ids;

int main()
{
	int row, col;
	FILE* fin = fopen("in", "r");
	while (fscanf(fin, "%d %d", &row, &col) == 2)
	{
		int ch, id = 0;
		string s;
		ids.clear(); 
		if ((ch = fgetc(fin)) == '\n')
			;//ungetc(ch, fin);
		for (int r = 0; r < row; ++r)
			for (int c = 0; c < col; ++c)
			{
				while ((ch = fgetc(fin)) != ',' && ch != '\n')
					s += ch;
				if (ids.count(s)) db[r][c] = ids[s];
				else ids[s] = db[r][c] = id++;
				s = "";
			}
		bool flag = true;
		for (int c1 = 0; c1 < col && flag; ++c1)
			for (int c2 = c1 + 1; c2 < col && flag; ++c2)
			{
				map<pair<int, int>, int> mp;
				for (int r2 = 0; r2 < row; ++r2)
				{
					pair<int, int> p(db[r2][c1], db[r2][c2]);
					if (!mp.count(p)) mp[p] = r2;
					else 
					{
						cout << "NO" << "\n" << mp[p]+1 << " " << r2+1 << "\n" << c1+1 << " " << c2+1 << "\n";
						flag = false;
						break;
					}
				}
				mp.clear();
			}
		if (flag) cout << "YES" << "\n";
	}
	return 0;
}
/**/