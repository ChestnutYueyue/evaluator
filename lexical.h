#ifndef LEXICAL_H
#define LEXICAL_H
#include <iostream>
#include <string>
#include <vector>
#include "eval.h"
using namespace std;

//Lexical继承Solution
class Lexical : public Solution
{
private:
	string Str;
	//多态函数重载
	bool judgement(const char ch);
	bool judgement(const string str);

public:
	//自定义构造函数优先
	Lexical() = default;
	//有参构造
	Lexical(string str);
	//有参构造重载运算符=
	Lexical &operator=(string &str);
	//拷贝函数重载运算符=
	Lexical &operator=(const Lexical &st);
	//重构eval方法
	auto eval();
};

inline Lexical::Lexical(string str)
{
	Str = str;
}
inline Lexical &Lexical::operator=(string &str)
{
	if (this->Str == str)
	{
		return *this;
	}
	this->Str = str;
	return *this;
}
inline Lexical &Lexical::operator=(const Lexical &st)
{
	if (this == &st)
	{
		return *this;
	}
	this->Str = st.Str;
	return *this;
}
inline bool Lexical::judgement(const char ch)
{
	string result = "+-/*()";
	for (auto &i : result)
	{
		if (ch == i)
		{
			return true;
		}
	}
	return false;
}
inline bool Lexical::judgement(const string str)
{
	vector<string> temp = {"+", "-", "*", "/"};
	for (auto &i : temp)
	{
		if (str == i)
		{
			return true;
		}
	}
	return false;
}
inline auto Lexical::eval()
{
	string temp = Str;
	vector<string> result;
	//分拆字符串
	for (auto i = 0; i < (int)Str.size(); i++)
	{
		if (judgement(Str[i]))
		{
			int pos = temp.find(Str[i]);
			string st = temp.substr(0, pos);
			if (!st.empty())
			{
				result.push_back(st);
			}
			string ch(1, Str[i]);
			result.push_back(ch);
			temp = temp.substr(pos + 1, temp.size());
		}
		else if (i == (int)Str.size() - 1)
		{
			result.push_back(temp);
		}
	}
	//处理负号
	for (auto i = 0; i < (int)result.size(); i++)
	{
		//如果-出现在第一个位置
		if (result[0] == "-")
		{
			result[0] += result[1];
			result.erase(result.begin() + 1);
		}
		else if ((result[i] == "(" && result[i + 1] == "-") || (judgement(result[i]) && result[i + 1] == "-"))
		{
			result[i + 1] += result[i + 2];
			result.erase(result.begin() + i + 2);
		}
	}
	//调用父类的eval方法
	return Solution::eval(result);
}
#endif