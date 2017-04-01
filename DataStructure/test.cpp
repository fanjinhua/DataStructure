#include <iostream>
#include "deceleration.h"

using std::cout; using std::endl;

int main()
{
	const string expr = "32+4*(72+9)-83";   //"9+(3-1)*3+10/2";
	cout << shunting_yard(expr) << endl;
	cout << rpn(shunting_yard(expr)) << endl;
	return 0;
}
