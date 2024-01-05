#pragma once
#include <string>

enum TypeToken
{
	NUMBER,
	VARIABLE,
	ENDSTRING,
	ASSIGNMENT,
	PLUS,
	SPACE,
	PRINT
};

class Token
{
public:
	Token(TypeToken _type, std::string _text);
private:
	TypeToken type;
	std::string text;
};
