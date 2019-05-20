#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int n = 0, testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (n < testCase) {
		int ax, bx, cx, ay, by, cy, signedArea = 0, clockDir = 0;
		fscanf(inp, "%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
		signedArea = (ax*by + bx * cy + cx * ay) - (bx*ay + cx * by + ax * cy);
		if (signedArea > 0) {
			clockDir = 1;
		}
		else if (signedArea == 0) {
			clockDir = 0;
		}
		else { 
			clockDir = -1;
			signedArea *= (-1);
		}
		std::cout << signedArea << " " << clockDir << std::endl;
		++n;
	}
	system("pause");
}