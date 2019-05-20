#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int n = 0, testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (n < testCase) {
		int x0, y0, x1, x2, y1, y2, cnt, areaSum = 0;
		fscanf(inp, "%d", &cnt);
		for (int i = 0; i < cnt; ++i) {
			if (i == 0) {
				fscanf(inp, "%d %d %d %d", &x1, &y1, &x2, &y2);
				areaSum += (x1 * y2 - y1 * x2);
				x0 = x1; y0 = y1; x1 = x2; y1 = y2;
			}
			else if (i == cnt - 1) {
				areaSum += (x2*y0 - y2 * x0);
			}
			else {
				fscanf(inp, "%d %d", &x2, &y2);
				areaSum += (x1 * y2 - y1 * x2);
				x1 = x2; y1 = y2;
			}
		}
		if (areaSum > 0) {
			std::cout << areaSum << " " << 1 << std::endl;
		}
		else if (areaSum < 0) {
			areaSum *= -1;
			std::cout << areaSum << " " << -1 << std::endl;
		}
		++n;
	}
	system("pause");
}