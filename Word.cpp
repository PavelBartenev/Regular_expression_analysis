#include "Word.h"
#include <algorithm>

Word::Word() : Xprefix_len{ 0 }, Xword_len{ 0 }, empty{ false } {};

Word::Word(int Xprefix_len, int Xword_len, bool empty) : Xprefix_len{ Xprefix_len }, Xword_len{ Xword_len }, empty{ empty } {};

Word Word::operator +(const Word& right_word) {
	Word new_word;
	new_word.Xprefix_len = std::max(Xprefix_len, right_word.Xprefix_len);
	new_word.Xword_len = std::max(Xword_len, right_word.Xword_len);
	new_word.empty = empty || right_word.empty;

	return new_word;
}

Word Word::operator &(const Word& right_word) {
	Word new_word;
	new_word.Xword_len = ((Xword_len > 0 || empty) && (right_word.Xword_len > 0 || right_word.empty) ? Xword_len + right_word.Xword_len : 0);
	new_word.Xprefix_len = (Xword_len > 0 || empty ? std::max(Xword_len + right_word.Xprefix_len, Xprefix_len) : 0);
	new_word.empty = empty && right_word.empty;

	return new_word;
}

Word Word::operator *() {
	Word new_word;
	new_word.Xword_len = (Xword_len == 0 ? 0 : std::numeric_limits<int>::max());
	new_word.Xprefix_len = std::max(new_word.Xword_len, Xprefix_len);
	new_word.empty = true;

	return new_word;
}
