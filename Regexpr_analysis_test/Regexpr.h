#pragma once
#include "Word.h"
#include <string>
#include <stack>

class Regexpr {
	std::string alphabet;
	std::string regexpr;
	std::stack<Word> parsing_stack;

public:
	Regexpr(const std::string& expr, const std::string& alphabet);

	int get_words(Word& left, Word& right);

	int longest_Xprefix_len(char x);
};