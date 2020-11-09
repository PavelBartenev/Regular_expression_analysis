#include "pch.h"
#include <gtest/gtest.h>
#include "../Regular_expression_analysis/Regular_expression_analysis.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//TEST(TestOverloadedOperators, Plus) {
//	Word right_word = { 2, 0, true };
//	Word left_word = { 4, 5, false };
//
//	Word result_word = left_word + right_word;
//
//	ASSERT_EQ(result_word.empty, true);
//	ASSERT_EQ(result_word.Xprefix_len, 4);
//	ASSERT_EQ(result_word.Xword_len, 9);
//}