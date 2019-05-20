#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	int testCase;
	inp = fopen("input.txt", "r");
	fscanf(inp, "%d", &testCase);
	while (testCase--) {
		unsigned int num, parity;
		int	count = 0;
		fscanf(inp, "%d", &num);
		parity = num;
		while (num / 2 != 0) {
			if (num % 2 == 1) {
				count += 1;
			}
			num /= 2;
		}
		if (num == 1) {
			count += 1;
		}
		if (count % 2 == 1) {
			parity += 2147483648;
		}
		std::cout << parity << std::endl;
	}
	system("pause");
}