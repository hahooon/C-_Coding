#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int test_case = 0, num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		int cnt = 0, search_num = 0, count_num = 0;
		fscanf(inp, "%d %d", &cnt, &search_num);

		for (int i = 0; i < cnt; ++i) {
			int a = 0;
			fscanf(inp, "%d", &a);
			if (search_num == a) {
				++count_num;
			}
		}
		std::cout << count_num << std::endl;
		++num;
	}
	system("pause");
}