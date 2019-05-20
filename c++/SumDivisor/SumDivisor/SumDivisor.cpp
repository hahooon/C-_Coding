#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int n = 0, testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (n < testCase) {
		int cnt = 0, sum = 0, amount = -1;
		fscanf(inp, "%d", &cnt);
		sum = (-1)*cnt;
		for (int i = 1; i * i <= cnt; ++i) {
			if (cnt % i == 0) {
				amount += 2;
				sum += (i*i == cnt) ? i, amount -= 1 : i + (cnt / i);
			}
		}
		std::cout << amount << " " << sum << std::endl;
		++n;
	}
	system("pause");
}