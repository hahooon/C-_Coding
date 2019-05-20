#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int test_case = 0, num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		int cnt = 0;
		fscanf(inp, "%d", &cnt);
		int max_num = 0;
		int second_max_num = 0;
		int last_num = 0;
		int a = 0;
		for (int i = 0; i < cnt; ++i) {
			fscanf(inp, "%d", &a);
			if (max_num < a) {
				second_max_num = max_num;
				max_num = a;
			}
			else if (second_max_num < a) {
				second_max_num = a;
			}
		}
		std::cout << second_max_num << std::endl;
		++num;
	}
	system("pause");
}