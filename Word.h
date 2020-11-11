#pragma once
struct Word {
	int Xprefix_len;
	int Xword_len;
	bool empty;

	Word();

	Word(int Xprefix_len, int Xword_len, bool empty);

	Word operator +(const Word& right_word);

	Word operator &(const Word& right_word);

	Word operator *();
};
