#include <stack>
#include <string>
#include <map>
#include <cassert>
using std::string; using std::stack;

string shunting_yard(const string& intfix)
{
	string postfix;
	stack<char> ops;
	ops.push('#');
	std::map<char, int> pred = { {'#', 0}, {')', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3} };

	int index = 0;
	while (index < intfix.size())
	{
		if (isalpha(intfix[index]))
		{
			while (isalpha(intfix[index]))
				postfix += intfix[index++];
			postfix += ' ';
		}
		else
		{
			while (pred[ops.top()] >= pred[intfix[index]])
			{
				if (ops.top() == '(')
				{
					if (intfix[index] == ')')
						ops.pop();
					break;
				}
				postfix += ops.top();
				postfix += ' ';
				ops.pop();
			}
			if (intfix[index] != ')')
				ops.push(intfix[index]);
			index++;
		}
	}
	while (ops.size() > 1)
	{
		postfix += ops.top(); 
		postfix += ' ';
		ops.pop();
	}
	return postfix;
}

int rpn(const string& postfix)
{
	stack<int> nums;
	stack<int> ops;
	int number;

	for (int index = 0; index < postfix.size(); ++index)
	{
		if (isdigit(postfix[index]))
		{	
			number = 0;
			while (isdigit(postfix[index]))
				number = number * 10 + (postfix[index++] - '0');
			nums.push(number);
		}
		if (postfix[index] == ' ')
			continue;

		assert(nums.size() > 1);
		int num1 = nums.top(); nums.pop();
		int num2 = nums.top(); nums.pop();
		
		switch (postfix[index])
		{
		case '+':
			nums.push(num2 + num1);
			break;
		case '-':
			nums.push(num2 - num1);
			break;
		case '*':
			nums.push(num2 * num1);
			break;
		case '/':
			assert(num1 != 0);
			nums.push(num2 / num1);
			break;
		default:
			break;
		}
	}
	if (nums.size() == 1)
		return nums.top();
	else
		return 0;
}
