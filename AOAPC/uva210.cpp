/** /
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n, t_assign, t_print, t_lock, t_unlock, t_end, quantum;
bool locked;
deque<int> ready;
queue<int> blocked;
map<string, int> vars;
vector<string> prog;
vector<int> ip;

void run(int pid)
{
	int quan = quantum;
	while (quan > 0)
	{
		vector<string> tokens;
		stringstream ss(prog[ip[pid]]);
		string buf;
		while (ss >> buf)
			tokens.push_back(buf);
		if (tokens.size() == 3)  // assign
		{
			int constant = 0;
			buf = tokens.back();
			for (int i = 0; i < buf.size(); ++i)
				constant = constant * 10 + (buf[i] - '0');
			vars[tokens.front()] = constant;
			quan -= t_assign;
		}
		else if (tokens.size() == 2)  // print
		{
			cout << pid + 1 << ": " << vars[tokens.back()] << endl;
			quan -= t_print;
		}
		else if (tokens.size() == 1)
		{
			if (tokens.front() == "end")
			{
				quan -= t_end;
				return;
			}
			else if (tokens.front() == "lock")
			{
				if (locked)
				{
					blocked.push(pid);
					return;
				}
				locked = true;
				quan -= t_lock;
			}
			else if (tokens.front() == "unlock")
			{
				locked = false;
				if (!blocked.empty())
				{
					int pid2 = blocked.front();
					blocked.pop();
					ready.push_front(pid2);
				}
				quan -= t_unlock;
			}
		}
		ip[pid]++;
	}
	ready.push_back(pid);
}

int main()
{
	int T;
	ifstream fin("in");
	cin >> T;
	while (T--)
	{
		prog.clear();
		ip.clear();
		vars.clear();
		
		fin >> n >> t_assign >> t_print >> t_lock >> t_unlock >> t_end >> quantum;
		int line = 0;
		for (int i = 0; i < n; ++i)
		{
			string stat;
			ip.push_back(line);
			while (stat != "end")
			{
				getline(fin, stat);
				prog.push_back(stat);
				line++;
			}
			ready.push_back(i);
		}
		
		locked = false;
		while (!ready.empty())
		{
			int pid = ready.front();
			ready.pop_front();
			run(pid);
		}
		if (T)
			cout << "\n";
	}
	return 0;
}
/**/