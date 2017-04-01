#include <stack>
#include <string>
#include <unordered_map>
#include <cassert>
using std::string; using std::stack;

string shunting_yard(const string& infix_expr)
{
	string postfix_expr;
	stack<char> ops;
	ops.push('#');
	std::unordered_map<char, int> precedence = { {'#', 0}, 	{')', 1}, {'+', 2}, \
												{'-', 2}, {'*', 3}, {'/', 3}, {'(', 4},};

	int index = 0;
	while (index < infix_expr.size())
	{
		if (isdigit(infix_expr[index]))
		{
			while (isdigit(infix_expr[index]))
				postfix_expr += infix_expr[index++];
			postfix_expr += ' ';
		}
		else
		{
			while (precedence[infix_expr[index]] <= precedence[ops.top()] && ops.top() != '(')
			{
				postfix_expr += ops.top();
				postfix_expr += ' ';
				ops.pop();
			}
			if (infix_expr[index] == ')')
				ops.pop();
			else
				ops.push(infix_expr[index]);
			index++;
		}
	}
	while (ops.size() > 1)
	{
		postfix_expr += ops.top(); 
		postfix_expr += ' ';
		ops.pop();

	}

	return postfix_expr;
}

int rpn(const string& postfix_expr)
{
	stack<int> nums;
	stack<int> ops;
	int number;

	for (int index = 0; index < postfix_expr.size(); ++index)
	{
		if (isdigit(postfix_expr[index]))
		{	
			number = 0;
			while (isdigit(postfix_expr[index]))
				number = number * 10 + (postfix_expr[index++] - '0');
			nums.push(number);
		}
		if (postfix_expr[index] == ' ')
			continue;

		assert(nums.size() > 1);
		int num1 = nums.top(); nums.pop();
		int num2 = nums.top(); nums.pop();
		
		switch (postfix_expr[index])
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
