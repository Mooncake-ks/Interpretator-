#include <iostream>
#include "Lexer.h"

int main()
{
	Lexer test("rex :5+9;34 54");
	std::vector<Token> testAnalysis = test.LexerAnalysis();

	return 0;
}

