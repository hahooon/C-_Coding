#include <iostream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int test_case = 0;
	int num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		++num;
		int cnt = 0;
		fscanf(inp, "%d", &cnt);
		std::cout << cnt << std::endl;
		for (int i = 0; i < cnt; ++i) {
			if (i <= cnt / 2) {
				int star_cnt = cnt/2 - i;
				int dia_cnt = (2 * i + 1);
				for(int j = 0; j < star_cnt; ++j){
					std::cout << "*";
				}
				for (int j = 0; j < dia_cnt; ++j) {
					std::cout << "+";
				}
				for (int j = 0; j < star_cnt; ++j) {
					std::cout << "*";
				}
			}
			else {
				int star_cnt = i - cnt/2;
				int dia_cnt = (2*(cnt - i-1)+1);
				for (int j = 0; j < star_cnt; ++j) {
					std::cout << "*";
				}
				for (int j = 0; j < dia_cnt; ++j) {
					std::cout << "+";
				}
				for (int j = 0; j < star_cnt; ++j) {
					std::cout << "*";
				}
			}
			std::cout << std::endl;
		}
	}
}