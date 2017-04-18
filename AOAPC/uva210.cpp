/**/
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n, t_assign, t_print, t_lock, t_unlock, t_end, quantum;
deque<int> ready;
queue<int> blocked;
map<string, int> vars;
vector<string> prog;
vector<int> ip;

void run(int pid)
{
	vector<string> tokens;
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

int main()
{
	
	ifstream fin("in");
	fin >> n >> t_assign >> t_print >> t_lock >> t_unlock >> t_end >> quantum;
	string stat;
	int line = 1;
	ip.push_back(1);
	while (getline(fin, stat))
	{
		prog.push_back(stat);
		if (stat == "end")
			ip.push_back(line + 1);
		line++;
	}
	ip.pop_back();
	for (int i = 0; i < n; ++i)
		ready.push_back(i);

	return 0;
}
/**/