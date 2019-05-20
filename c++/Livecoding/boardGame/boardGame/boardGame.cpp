#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int test_case = 0, num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		int a = 0, b = 0, c = 0, d = 0;
		fscanf(inp, "%d %d", &a, &b);
		c = ((a / 16) * 2 + (a % 16));
		d = ((b / 16) * 2 + (b % 16));
		if ( c > d ) {
			std::cout << c << std::endl;
		}
		else {
			std::cout << d << std::endl;
		}
		++num;
	}
	system("pause");
}