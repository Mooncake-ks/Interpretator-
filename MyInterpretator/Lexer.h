#pragma once
#include <string>
#include <vector>
#include "Token.h"
class Lexer
{
public:

	Lexer(std::string text);
	bool Pars(std::string);
	bool ParsVariable(std::string);
	bool ParsNumber(std::string);
	std::vector<Token> LexerAnalysis();

private:
	std::string textCode;
	std::vector<Token> tokenList;
};