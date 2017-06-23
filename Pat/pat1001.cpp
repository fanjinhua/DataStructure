/** /
#include <iostream>
#include <stack>

int main()
{
	int a, b;
	std::cin >> a >> b;
	int sum = a + b;
	if (sum == 0)
	{
		std::cout << 0;
		return 0;
	}
	std::stack<int> s;
	int neg = (sum < 0) ? 1 : 0;
	sum = (sum < 0) ? -sum : sum;
	while (sum != 0)
	{
		s.push(sum % 1000);
		sum /= 1000;
	}
	if (neg)
		std::cout << "-";
	while (!s.empty())
	{
		std::cout << s.top();
		s.pop();
		if (!s.empty())
			std::cout << ",";
		else
			break;
	}
	std::cout << std::endl;
	return 0;
}
/**/