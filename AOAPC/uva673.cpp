/** /
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int T;
	ifstream fin("in");
	fin >> T;
	string b;
	getline(fin, b);  // b == ""
	while (T--)
	{
		string buf;
		stack<char> s;
		bool no_extra_right = true;
		getline(fin, buf);
		if (buf == "")
		{
			cout << "Yes" << endl;
			continue;
		}

		for (auto it = buf.begin(); it != buf.end() && no_extra_right; ++it)
		{
			switch (*it)
			{
			case '(':
				s.push(*it);
				break;
			case '[':
				s.push(*it);
				break;
			case ')':
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
					no_extra_right = false;
				break;
			case ']':
				if (!s.empty() && s.top() == '[')
					s.pop();
				else
					no_extra_right = false;
				break;
			}
			
		}
		if (s.empty() && no_extra_right)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
/**/