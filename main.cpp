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
	
		cout << "��������ʽ��";
		cin >> infix;
		splie = infix;
		cout << "������Ϊ��" << str.eval(splie.split()) << endl;
	}
	return 0;
}
