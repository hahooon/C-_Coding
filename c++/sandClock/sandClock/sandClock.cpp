#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int num = 0;
	int test_case = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		int cnt = 0;
		fscanf(inp, "%d", &cnt);
		int mid_num = cnt / 2;
		int minus_cnt = 0;
		for (int i = 0; i <= mid_num; ++i) {
			for (int j = 0; j < minus_cnt; ++j) {
				std::cout << '-';
			}
			for (int j = minus_cnt; j < (cnt - minus_cnt); ++j) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						std::cout << "*";
					}
					else { std::cout << "+"; }
				}
				else {
					if (j % 2 == 0) {
						std::cout << "+";
					}
					else { std::cout << "*"; }
				}
			}
			for (int j = (cnt - minus_cnt); j < cnt; ++j) {
				std::cout << '-';
			}
			++minus_cnt;
			std::cout << std::endl;
		}
		--minus_cnt;
		for (int i = mid_num+1; i < cnt; ++i) {
			--minus_cnt;
			for (int j = 0; j < minus_cnt; ++j) {
				std::cout << "-";
			}
			for (int j = minus_cnt; j < (cnt - minus_cnt); ++j) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						std::cout << "*";
					}
					else { std::cout << "+"; }
				}
				else {
					if (j % 2 == 0) {
						std::cout << "+";
					}
					else { std::cout << "*"; }
				}
			}
			for (int j = cnt - minus_cnt; j < cnt; ++j) {
				std::cout << "-";
			}
			std::cout << std::endl;
		}
		++num;
	}
	system("pause");
}