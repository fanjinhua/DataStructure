/** /
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> exist;
vector<string> words;

int main()
{
	string wd;
	while (cin >> wd)
	{
		words.push_back(wd);
		exist[wd] = 1;
	}

	string sec1, sec2;
	for (int i = 0; i < words.size(); ++i)
		for (int j = 1; j < words[i].size(); ++j)
		{
			sec1 = words[i].substr(0, j);
			sec2 = words[i].substr(j);
			if (exist.count(sec1) && exist.count(sec2))
			{
				cout << words[i] << "\n";
				break;
			}
		}
	return 0;
}
/**/