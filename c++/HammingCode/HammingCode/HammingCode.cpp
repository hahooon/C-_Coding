#include <iostream>
#include <fstream>

int main() {
	FILE* inp;
	inp = fopen("input.txt", "r");
	int testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (testCase--) {
		int subCase, inspectedNumber, countP1 = 0, countP2 = 0;
		int  countP4 = 0, countP8 = 0, countP16 = 0;
		fscanf(inp, "%d %d", &subCase, &inspectedNumber);

		int temp[32];
		int binaryNumber[32];
		int idx = 1;

		while (inspectedNumber != 0) {
			temp[idx] = (inspectedNumber % 2);
			inspectedNumber /= 2;
			if(idx)
			idx += 1;
		}
		temp[0] = 0;
		for (int i = 0; i < temp.size(); ++i) {
			if (i % 2 == 0) {
				countP1 += temp[i];
			}
			if (i % 4 == 1 || i % 4 == 2) {
				countP2 += temp[i];
			}
			if ((i % 8 == 3) || (i % 8 == 4) || (i % 8 == 5) || (i % 8 == 6)) {
				countP4 += temp[i];
			}
			if (i % 16 == 7 || i % 16 == 8 || i % 16 == 9 || i % 16 == 10 || i % 16 == 11 || i % 16 == 12 || i % 16 == 13 || i % 16 == 14) {
				countP8 += temp[i];
			}
			if (i == 15 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23 || i == 24 || i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30) {
				countP16 += temp[i];
			}
		}

		if (countP1 % 2 == 1) {
			temp[0] = 1;
		}
		if (countP2 % 2 == 1) {
			temp[1] = 1;
		}
		if (countP4 % 2 == 1) {
			temp[3] = 1;
		}
		if (countP8 % 2 == 1) {
			temp[7] = 1;
		}
		if (countP16 % 2 == 1) {
			temp[15] = 1;
		}

		for (int i = temp.size() - 1; i >= 0; --i) {
			binaryNumber.push_back(temp[i]);
		}
		for (int i = 0; i < binaryNumber.size(); ++i) {
			std::cout << binaryNumber[i];
		}
	}
	system("pause");
}