#include <iostream>

int main() {
	int test_case = 0;
	FILE *inp;
	inp = fopen("input.txt", "r");
	int num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		++num;
		int cnt = 0;
		fscanf(inp, "%d", &cnt);
		for (int i = 1; i <= cnt; ++i) {
			int add_num = cnt - 1;
			int print_num = i;
			for (int j = 0; j < i; ++j) {
				if (j == 0) {
					std::cout << print_num << " ";
				}
				else {
					print_num += add_num;
					std::cout << print_num << " ";
					--add_num;
				}
			}
			std::cout << std::endl;
		}
	}
}