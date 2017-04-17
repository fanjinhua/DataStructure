/**/
#include <iostream>
#include <sstream>
#include <fstream>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n, t_assign, t_print, t_lock, t_unlock, t_end, quantum;
	ifstream fin("in");

	fin >> n >> t_assign >> t_print >> t_lock >> t_unlock >> t_end >> quantum;

	deque<int> ready;
	queue<int> blocked;
	string stat;
	vector<string> tokens;
	map<string, int> vars;
	while (getline(fin, stat))
	{
		stringstream ss(stat);
		string buf;
		while (ss >> buf)
			tokens.push_back(buf);
		if (tokens.size() == 3)
		{
			int constant;
			ss << tokens.back();
			ss >> constant;
			vars[tokens.front()] = constant;
		}
		else if (tokens.size() == 2)
		{
			cout << vars[tokens.back()];
		}
		else if (tokens.size() == 1)
		{
			if (tokens.front() == "end")
				;
			else if (tokens.front() == "lock")
				;
			else if (tokens.front() == "unlock")
				;

		}
	}

	return 0;
}
/**/