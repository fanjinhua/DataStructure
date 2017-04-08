/** /
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

const int maxline = 1000 + 10;
const int maxc = 180 + 5;
string words[maxline][maxc];
int cols[maxline] = { 0 };
int maxlength[maxc] = { 0 };

int main()
{
	int row = 0;
	string line;
	//ifstream ifs("in");
	while (getline(cin, line))
	{
		int col = 0;
		stringstream ss(line);
		while (ss >> words[row][col])
		{
			cols[row]++;
			maxlength[col] = max(maxlength[col], (int)words[row][col].length());
			col++;
		}
		row++;
	}

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < cols[r]; ++c)
		{
			cout << words[r][c];
			if (c != cols[r] - 1)
				for (int i = maxlength[c] + 1 - (int)words[r][c].length(); i > 0; --i)
					cout << ' ';
		}
		cout << "\n";
	}
	return 0;
}
/**/