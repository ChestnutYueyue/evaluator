#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "lexical.h"
using namespace std;

int main()
{
	string infix;
	Lexical splie;
	while (1)
	{
		cout << "请输入表达式：";
		cin >> infix;
		splie = infix;
		cout << "计算结果为：" << splie.eval() << endl;
	}
	return 0;
}