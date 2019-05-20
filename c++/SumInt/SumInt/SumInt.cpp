#include <iostream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int test_case = 0;
	int num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case){
		++num;
		int cnt = 0;
		fscanf(inp, "%d", &cnt);
		int sum = 0;
		for (int i = 0; i < cnt; ++i) {
			int a = 0;
			fscanf(inp, "%d", &a);
			sum += a;
		}
		std::cout << sum << std::endl;
	}
}