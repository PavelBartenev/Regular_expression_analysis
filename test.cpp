#include "pch.h"
#include <gtest/gtest.h>
#include "Word.cpp"
#include "Regexpr.cpp"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestOverloadedOperators, Plus) {
	Word right_word = { 2, 0, true };
	Word left_word = { 6, 5, false };

	Word result_word = left_word + right_word;

	ASSERT_EQ(result_word.empty, true);
	ASSERT_EQ(result_word.Xprefix_len, 6);
	ASSERT_EQ(result_word.Xword_len, 5);
}

TEST(TestOverloadedOperators, Concatenation) {
	Word right_word = { 2, 0, true };
	Word left_word = { 6, 5, false };

	Word result_word = left_word & right_word;

	ASSERT_EQ(result_word.empty, false);
	ASSERT_EQ(result_word.Xprefix_len, 7);
	ASSERT_EQ(result_word.Xword_len, 5);
}

TEST(TestOverloadedOperators, Power) {
	Word word = { 2, 0, true };

	word = *word;

	ASSERT_EQ(word.Xprefix_len, 2);
	ASSERT_EQ(word.Xword_len, 0);

	word = { 3, 1, false };

	word = *word;

	ASSERT_EQ(word.Xprefix_len, std::numeric_limits<int>::max());
	ASSERT_EQ(word.Xword_len, std::numeric_limits<int>::max());
}

TEST(TestRegexpr, GeneralExpr) {
	std::string str = "ab+c.aba.*.bac.+.+*";
	char symbol = 'a';

	std::string alphabet = { 'a', 'b', 'c', '.', '+', '*', '1' };

	Regexpr expr{ str, alphabet };

	int Xprefix_len = expr.longest_Xprefix_len(symbol);

	ASSERT_EQ(Xprefix_len, 2);
}

TEST(TestRegexpr, InvalidExpr) {
	std::string str = "ab+caba.*.bac.+.+*";
	char symbol = 'a';

	std::string alphabet = { 'a', 'b', 'c', '.', '+', '*', '1' };

	Regexpr expr{ str, alphabet };

	int Xprefix_len = expr.longest_Xprefix_len(symbol);

	ASSERT_EQ(Xprefix_len, -1);
}

