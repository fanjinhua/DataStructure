#include <stack>
#include <cstdio>

void convert(int num, const int base)
{
	static char digit[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	std::stack<char> s;
	while (num)
	{
		s.push(digit[num%base]);
		num /= base;
	}
	while (!s.empty())
	{
		std::printf("%c", s.top());
		s.pop();
	}
}

bool paren(const char exp[], int lo, int hi)
{// exp[lo, hi)
	std::stack<char> s;
	while (lo < hi)
	{
		if (exp[lo] == '(')
			s.push(exp[lo]);
		else if (!s.empty()) // ÓöÓÒÀ¨ºÅ
			s.pop();
		else //ÓöÓÒÀ¨ºÅ²¢ÇÒÕ»¿Õ
			return false;
		lo++;
	}
	return s.empty();
}
