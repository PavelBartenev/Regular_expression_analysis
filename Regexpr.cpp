class Regexpr {
	std::string alphabet;
	std::string regexpr;
	std::stack<Word> parsing_stack;

public:
	Regexpr(const std::string& expr, const std::string& alphabet)
		: regexpr{ expr }, alphabet{ alphabet } {}

	int get_words(Word& left, Word& right) {
		if (parsing_stack.size() < 2)
			return -1;
		right = parsing_stack.top();
		parsing_stack.pop();
		left = parsing_stack.top();
		parsing_stack.pop();

		return 0;
	}

	int longest_Xprefix_len(char x) {
		for (const auto& symbol : regexpr) {
			if (alphabet.find(symbol) == std::string::npos)
				return -1;

			if (symbol == '+') {
				Word left_word, right_word;
				if (get_words(left_word, right_word) != -1)
					parsing_stack.push(left_word + right_word);
				else
					return -1;
			}
			else if (symbol == '.') {
				Word left_word, right_word;
				if (get_words(left_word, right_word) != -1)
					parsing_stack.push(left_word & right_word);
				else
					return -1;
			}
			else if (symbol == '*') {
				if (parsing_stack.size() < 1)
					return -1;
				Word word = parsing_stack.top();
				parsing_stack.pop();
				parsing_stack.push(*word);
			}
			else if (symbol == '1')
				parsing_stack.push(Word{ 0, 0, true });
			else if (symbol == x)
				parsing_stack.push(Word{ 1, 1, false });
			else
				parsing_stack.push(Word{ 0, 0, false });
		}

		if (parsing_stack.size() != 1)
			return -1;

		return std::max(parsing_stack.top().Xprefix_len, parsing_stack.top().Xword_len);
	}
};

