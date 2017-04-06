/** /
#include <string>
#include <set>
#include <iostream>
#include <sstream>
using namespace std;

set<string> dict;

int main()
{
	string s, buf;
	while (cin >> s)
	{
		for (int i = 0; i < s.length(); ++i)
			if (isalpha(s[i]))
				s[i] = tolower(s[i]);
			else
				s[i] = ' ';
		stringstream ss(s);
		while (ss >> buf)
			dict.insert(buf);
	}
	for (auto f : dict)
		cout << f << "\n";
	return 0;
}
/**/