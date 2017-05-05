/** /
#include <iostream>
using namespace std;

bool solve(int& W)
{
	int W1, D1, W2, D2;
	cin >> W1 >> D1 >> W2 >> D2;
	bool b1 = true, b2 = true;
	if (!W1) b1 = solve(W);
	if (!W2) b2 = solve(W);
	W = W1 + W2;
	return b1 && b2 && (W1*D1 == W2*D2);
}

int main()
{
	int T, W;
	cin >> T;
	while (T--)
	{
		cout << (solve(W) ? "YES\n" : "NO\n");
		if (T) cout << "\n";
	}
	return 0;
}
/**/