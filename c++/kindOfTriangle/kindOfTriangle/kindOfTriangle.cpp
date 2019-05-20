#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int test_case = 0;
	int num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		int a = 0, b = 0, c = 0;
		fscanf(inp, "%d %d %d", &a, &b, &c);
		if (a+b > c) {
			if (a == b && b == c) {
				std::cout << 1 << std::endl;
			}
			else if (a*a + b * b == c * c) {
				std::cout << 2 << std::endl;
			}
			else if ((a == b && b != c) || (a != b && b == c)) {
				std::cout << 3 << std::endl;
			}
			else { std::cout << 4 << std::endl; }
		}
		else { std::cout << 0 << std::endl; }
		++num;
	}
	system("pause");
}