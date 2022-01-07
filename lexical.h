#ifndef LEXICAL_H
#define LEXICAL_H
#include <iostream>
#include <string>
#include <vector>
#include "eval.h"
using namespace std;

//Lexical¼Ì³ÐSolution
class Lexical: public Solution
{
	private:
		string Str;
		bool judgement(const char ch);
		bool judgement(const string str);
	public:
		Lexical() = default;
		Lexical(string str)
		{
			Str = str;
		}
		Lexical &operator=(string & str)
		{
			if (this ->Str == str)
			{
				return *this;
			}
			this->Str = str;
			return *this;
		}
		Lexical &operator=(const Lexical & st)
		{
			if (this == &st)
			{
				return *this;
			}
			this->Str = st.Str;
			return *this;
		}
		auto split();
};

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
inline auto Lexical::split()
{
	string temp = Str;
	vector<string> result;
	for (auto i = 0; i < (int)Str.size(); i++)
	{
		if (judgement(Str[i]))
		{
			int pos = temp.find(Str[i]);
			string temp1 = temp.substr(0, pos);
			if (!temp1.empty())
			{
				result.push_back(temp1);
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
	for (auto i = 0; i < (int)result.size(); i++)
	{
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
	return result;
}
#endif
