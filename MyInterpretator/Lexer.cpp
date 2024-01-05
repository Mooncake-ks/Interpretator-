#include "Lexer.h"

Lexer::Lexer(std::string text) :textCode{ text } {}

bool Lexer::Pars(std::string e)
{
	if (e == "+")
	{
		tokenList.push_back(Token(TypeToken::PLUS, e));
		return true;
	}
	if (e == ":")
	{
		tokenList.push_back(Token(TypeToken::ASSIGNMENT, e));
		return true;
	}
	if (e == "Print")
	{
		tokenList.push_back(Token(TypeToken::PRINT, e));
		return true;
	}
	if (e == ";")
	{
		tokenList.push_back(Token(TypeToken::ENDSTRING, e));
		return true;
	}
	if (e == " ")
	{
		tokenList.push_back(Token(TypeToken::SPACE, e));
		return true;
	}
	if (ParsNumber(e))
	{
		tokenList.push_back(Token(TypeToken::NUMBER, e));
		return true;
	}
	if (ParsVariable(e))
	{
		tokenList.push_back(Token(TypeToken::VARIABLE, e));
		return true;
	}

	return false();
}

bool Lexer::ParsVariable(std::string e)
{
	for (int i = 0; i < e.length(); i++)
	{
		if (!(e[i] >= 'A' && e[i] <= 'Z') && !(e[i] >= 'a' && e[i] <= 'z') && !(e[i] >= '0' && e[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}

bool Lexer::ParsNumber(std::string e)
{
	for (int i = 0; i < e.length(); i++)
	{
		if (e[i] < '0' || e[i]>'9')
		{
			return false;
		}
	}
	return true;
}

std::vector<Token> Lexer::LexerAnalysis()
{
	std::string temp{ "" };
	if (!textCode.empty())
	{
		for (auto el : textCode)
		{
			if ((el >= 'A' && el <= 'Z') || (el >= 'a' && el <= 'z') || (el >= '0' && el <= '9'))
			{
				temp += el;
				continue;
			}
			else if (!temp.empty())
			{
				Pars(temp);
				temp.clear();
			}
			temp = el;
			Pars(temp);
			temp.clear();
		}
		if (!temp.empty())
		{
			Pars(temp);
		}
	}

	return tokenList;
}
