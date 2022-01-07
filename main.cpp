#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "lexical.h"
#include "eval.h"
using namespace std;

int main()
{
	string infix;
	Solution str;
	Lexical splie;
	while (1)
	{
	
		cout << "请输入表达式：";
		cin >> infix;
		splie = infix;
		cout << "计算结果为：" << str.eval(splie.split()) << endl;
	}
	return 0;
}
