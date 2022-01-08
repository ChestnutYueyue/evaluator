#ifndef EVAL_H
#define EVAL_H
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
	int prio(string op);
	bool isdigit(const string str);
	vector<string> Trans(vector<string> str);

public:
	double eval(vector<string> temp);
};

inline int Solution::prio(string op)
{
	if (op == "*" || op == "/")
		return 2;
	else if (op == "+" || op == "-")
		return 1;
	else
		return 0;
}
inline bool Solution::isdigit(const string str)
{
	vector<string> temp = {"+", "-", "*", "/", "(", ")"};
	for (auto &i : temp)
	{
		if (str == i)
		{
			return true;
		}
	}
	return false;
}
inline vector<string> Solution::Trans(vector<string> str)
{
	vector<string> temp;
	stack<string> stack;
	for (auto i = 0; i < (int)str.size(); i++)
	{
		if (!isdigit(str[i]))
		{
			temp.push_back(str[i]);
		}
		else if (stack.empty())
		{
			stack.push(str[i]);
		}
		else if (str[i] == "(")
		{
			stack.push(str[i]);
		}
		else if (str[i] == ")")
		{
			while (stack.top() != "(")
			{
				temp.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
		else
		{
			while (prio(str[i]) <= prio(stack.top()))
			{
				temp.push_back(stack.top());
				stack.pop();
				if (stack.empty())
					break;
			}
			stack.push(str[i]);
		}
	}
	while (!stack.empty())
	{
		temp.push_back(stack.top());
		stack.pop();
	}
	return temp;
}
inline double Solution::eval(vector<string> temp)
{
	vector<string> tokens = Trans(temp);
	stack<double> stack;
	for (int i = 0; i < (int)tokens.size(); i++)
	{
		if (tokens[i] == "+")
		{
			double Right = stack.top();
			stack.pop();
			double left = stack.top();
			stack.pop();
			stack.push(left + Right);
		}
		else if (tokens[i] == "-")
		{
			double Right = stack.top();
			stack.pop();
			double left = stack.top();
			stack.pop();
			stack.push(left - Right);
		}
		else if (tokens[i] == "*")
		{
			double Right = stack.top();
			stack.pop();
			double left = stack.top();
			stack.pop();
			stack.push(left * Right);
		}
		else if (tokens[i] == "/")
		{
			double Right = stack.top();
			stack.pop();
			double left = stack.top();
			stack.pop();
			stack.push(left / Right);
		}
		else
		{
			stack.push(stod(tokens[i]));
		}
	}
	return stack.top();
}
#endif