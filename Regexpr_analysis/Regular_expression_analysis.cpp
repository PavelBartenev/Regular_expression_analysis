#include <iostream>
#include <string>
#include "Regexpr.h"

int main() {
	std::string str;
	std::cin >> str;
	char symbol;
	std::cin >> symbol;

	std::string alphabet = { 'a', 'b', 'c', '.', '+', '*', '1' };

	Regexpr expr{ str, alphabet };

	int Xprefix_len = expr.longest_Xprefix_len(symbol);

	if (Xprefix_len == -1)
		std::cout << "ERROR";
	else if (Xprefix_len == std::numeric_limits<int>::max())
		std::cout << "INF";
	else
		std::cout << Xprefix_len;

	return 0;
}
