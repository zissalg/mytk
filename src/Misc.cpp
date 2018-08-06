#include "Misc.h"

int hex2Dec(std::string hex) {
	using std::string;

	for (int i = 0; i < hex.length(); ++i)
		hex[i] = (hex[i] >= 'a' && hex[i] <= 'z') ? hex[i] - 32 : hex[i];

	int 	dec = 0;
	string 	hexTab = "0123456789ABCDEF";
	int 	decTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	for (int i = 0; i < hex.length(); ++i) {
		for (int j = 0; j < 16; ++j) {
			if (hex[i] == hexTab[j]) {
				dec += decTab[j] * pow(16, hex.length() - i - 1);
			}
		}
	}

	return dec;
}

int randomInt(int from, int to) {
	static bool first = true;
	if (first) {
		srand(time(nullptr));
		first = false;
	}

	return from + (rand() % (to - from) + 1);
}
