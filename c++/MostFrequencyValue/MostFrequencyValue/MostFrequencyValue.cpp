#include <iostream>
#include <fstream>

int main() {
	int testCase = 0;
	FILE *inp;
	inp = fopen("input.txt", "r");
	fscanf(inp, "%d", &testCase);
	while (testCase--) {
		int cnt = 0, numArr[100][2], n, index = 0, maxCount = -1, maxNumCount = 0;
		fscanf(inp, "%d", &cnt);
		for (int i = 0; i < 100; ++i) {
			numArr[i][0] = 20171697;
			numArr[i][1] = 20171697;
		}
		while (cnt--) {
			fscanf(inp, "%d", &n);
			int check = 1;
			for (int i = 0; i < index; ++i) {
				if (numArr[i][0] == n) {
					numArr[i][1] += 1;
					check = 2;
					break;
				}
			}
			if (check == 1) {
				numArr[index][0] = n;
				numArr[index][1] = 1;
				++index;
			}
		}
		for (int i = 0; i < 100; ++i) {
			int pivotIdx = 0, j = 0;
			while (numArr[j][0] != 20171697) {
				if (numArr[pivotIdx][0] < numArr[j][0]) pivotIdx = j;
				else {
					int a = numArr[j][0], b = numArr[j][1];
					numArr[j][0] = numArr[pivotIdx][0];
					numArr[j][1] = numArr[pivotIdx][1];
					numArr[pivotIdx][0] = a;
					numArr[pivotIdx][1] = b;
					if (numArr[pivotIdx][1] > maxCount) {
						maxCount = numArr[pivotIdx][1];
					}
					pivotIdx = j;
				}
				++j;
			}
		}
		for (int k = 0; k < index; ++k) {
			if (numArr[k][1] == maxCount) {
				maxNumCount += 1;
			}
		}
		std::cout << maxNumCount << " " << maxCount << " ";
		for (int i = 0; i < index; ++i) {
			if (numArr[i][1] == maxCount) {
				std::cout << numArr[i][0] << " ";
			}
		}
		std::cout << std::endl;
	}
	system("pause");
}