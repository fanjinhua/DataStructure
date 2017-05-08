/** /
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using namespace std;
queue<char> postord;

void construct(string pre, string in)
{
	if (pre.size() == 0)
		return;
	else if (pre.size() == 1)
	{
		postord.push(pre[0]);
		return;
	}
	char root = pre[0];
	int len = in.find_first_of(root);
	string pre_left(pre.begin() + 1, pre.begin() + 1 + len);
	string pre_right(pre.begin()+ 1 + len, pre.end());
	string in_left(in.begin(), in.begin()+len);
	string in_right(in.begin()+len+1, in.end());
	construct(pre_left, in_left);
	construct(pre_right, in_right);
	postord.push(root);
}

int main()
{
	string preord, inord;
	ifstream fin("in");
	while (fin >> preord >> inord)
	{
		// postord is empty
		construct(preord, inord);
		while (!postord.empty())
		{
			cout << postord.front();
			postord.pop();
		}
		cout << endl;
	}
	return 0;
}
/**/