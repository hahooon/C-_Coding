#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int n = 0, testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (n < testCase) {
		int x1, x2, y1, y2, a1, a2, b1, b2;  // xy °¡ ¼öÁ÷
		fscanf(inp, "%d %d %d %d", &x1, &y1, &x2, &y2);
		fscanf(inp, "%d %d %d %d", &a1, &b1, &a2, &b2);
		
		if (a1 == a2) {
			int temp[4];
			temp[0] = x1; temp[1] = y1; temp[2] = x2; temp[3] = y2;
			x1 = a1; x2 = a2; y1 = b1; y2 = b2;
			a1 = temp[0]; b1 = temp[1]; a2 = temp[2]; b2 = temp[3];
		}
		if (y1 > y2) {
			int temp = y2;
			y2 = y1;
			y1 = temp;
		}
		if (a1 > a2) {
			int temp = a2;
			a2 = a1;
			a1 = temp;
		}

		if ((a1 < x1 && x1 < a2) && (y1 < b1 && b1 < y2 )){
			std::cout << "1\n";
		}

		else if ((a1 > x1 || x1 > a2) || (y1 > b1 || y2 < b1)) {
			std::cout << "0\n";
		}
		else { std::cout << "2\n"; }
		++n;
	}
	system("pause");
}