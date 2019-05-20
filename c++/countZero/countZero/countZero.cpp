#include <iostream>
#include <fstream>

int main() {
/*	FILE *inp;
	inp = fopen("input.txt", "r");
	int n = 0, testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (n < testCase) {
		unsigned int multiple = 1, newNumber = 0;
		int cnt = 0, zeroCount = 0, twoCount = 0, fivecount = 0;
		fscanf(inp, "%d", &cnt);
		for (int i = 0; i < cnt; ++i) {
			fscanf(inp, "%d", &newNumber);
			while ((newNumber % 2 == 0) || (newNumber % 5 == 0)) {		// 2의 배수이거나 5의배수인 동안
				if (newNumber % 2 == 0) {
					++twoCount;
					newNumber /= 2;
				}
				if (newNumber % 5 == 0) {
					++fivecount;
					newNumber /= 5;
				}
			}
			newNumber %= 10;
			multiple *= newNumber;
			multiple %= 10;
		}
		while (twoCount > 0 && fivecount > 0) {
			++zeroCount;
			--twoCount;
			--fivecount;
		}
		for (int i = 0; i < twoCount; ++i) {
			multiple *= 2;
			multiple %= 10;
		}
		for (int i = 0; i < fivecount; ++i) {
			multiple *= 5;
			multiple %= 10;
		}
		++n;
		std::cout << multiple << " " << zeroCount << std::endl;
	}*/

	for (int i = 0; i < 10; ++i) {
		++i;
		std::cout << i << std::endl;
	}
	system("pause");
}