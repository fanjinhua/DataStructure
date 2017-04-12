/**/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cassert>
using namespace std;
map<string, int> arr;
map<char, int> num;
map<char, map<int, int>> arr_num;
#define PASS(p) do { while (*p == '[' || *p == ']') ++p; } while (0)
string line;

int getnum(string a)
{
	int begin, end;
	begin = a.find('[');
	if (begin == string::npos)
	{
		sscanf(a.c_str(), "%d", &begin);
		return begin;
	}
	end = a.find_last_of(']');
	int num = getnum(a.substr(a.find('[') + 1, a.find_last_of(']')));
	if (num == -1) 
		return -1;
	if (arr_num[a[0]].count(num) == 0) 
		return -1;
	else
		return arr_num[a[0]][num];
}

int main()
{
	ifstream fin("in");
	int nowc = 0;
	while (getline(fin, line))
	{
		if (line == "." && nowc != 0)
		{
			cout << 1 << "\n";
			nowc = 0;
			arr.clear();
			num.clear();
			arr_num.clear();
			continue;
		}
		else if (line == "." && nowc == 0) break;

		nowc++;
		int pos = line.find('=');
		if (pos == string::npos)
			arr[line.substr(0, line.find('['))] = getnum(line.substr(line.find_first_of('[') + 1, line.find_last_of(']')));
		else
		{
			int npos = getnum(line.substr(line.find('[') + 1, line.find('=')));
			int fpos = getnum(line.substr(line.find('=') + 1, line.length()));
			if (npos != -1 && fpos != -1 && npos < arr[line.substr(0, 1)] && npos >= 0)
				arr_num[line[0]][npos] = fpos;
			else
			{
				cout << nowc << endl;
				while (getline(fin, line) && line != ".")
					;
				arr.clear();
				num.clear();
				arr_num.clear();
				nowc = 0;;
			}
		}
	}

}
/**/