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

		cout << "��������ʽ��";
		cin >> infix;
		splie = infix;
		cout << "������Ϊ��" << splie.eval(splie.split()) << endl;
	}
	return 0;
}
