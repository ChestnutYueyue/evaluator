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
	while (1)
	{
		cout << "��������ʽ��";
		cin >> infix;
		Lexical splie(infix);
		Solution str;
		cout << "������Ϊ��" << str.eval(splie.split()) << endl;
	}
	return 0;
}
