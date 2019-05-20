#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int testCase = 0;
	
	fscanf(inp, "%d", &testCase);
	while (testCase--) {
		int numCase[100][2], cnt = 0, n = 0, index = 0;
		fscanf(inp, "%d", &cnt);
		for (int i = 0; i < 100; ++i) {
			numCase[i][0] = 101;
			numCase[i][1] = 0;
		}
		for (int i = 0; i < cnt; ++i) {
			fscanf(inp, "%d", &n);
			int check = 1, j = 0;
			while (numCase[j][0] != 101) {
				if (numCase[j][0] == n) {
					numCase[j][1] += 1;
					check = 2;
					break;
				}
				++j;
			}
			if (check == 1) {
				numCase[index][0] = n;
				numCase[index][1] = 1;
				index += 1;
			}
		}
		int buf = 0;
		for (int i = 0; i < 100; ++i) {
			int pivotIdx = 0,j = 1;
			while (numCase[j][0] != 101) {
				if (numCase[pivotIdx][0] < numCase[j][0]) pivotIdx = j;
				else {
					int a = numCase[j][0], b = numCase[j][1];
					numCase[j][0] = numCase[pivotIdx][0];
					numCase[j][1] = numCase[pivotIdx][1];
					numCase[pivotIdx][0] = a;
					numCase[pivotIdx][1] = b;
					pivotIdx = j;
				}
				++j;
			}
		}
		while (numCase[buf][0] != 101) {
			printf("%d %d ", numCase[buf][0], numCase[buf][1]);
			++buf;
		}
		printf("\n");
	}
	system("pause");
}
