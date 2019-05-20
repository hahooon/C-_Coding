#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int testCase;
	fscanf(inp, "%d", &testCase);
	while (testCase--) {
		unsigned int setA[132] = { 0, }, setB[132] = { 0, }, hop[132] = { 0, }, kyo[132] = { 0, }, cha[132] = { 0, };
		int subTest1 = 0, subTest2 = 0, hopCount = 0, kyoCount = 0, chaCount = 0;
		fscanf(inp, "%d", &subTest1);
		for (int i = 0; i < subTest1; ++i) {
			int a = 0;
			fscanf(inp, "%d", &a);
			setA[a] = 1;
		}
		fscanf(inp, "%d", &subTest2);
		for (int i = 0; i < subTest2; ++i) {
			int a = 0;
			fscanf(inp, "%d", &a);
			setB[a] = 1;
		}
		for (int i = 0; i < 132; ++i) {
			if (setA[i] == 1 || setB[i] == 1) {
				hop[i] = 1;
				hopCount += 1;
			}
			if (setA[i] == 1 && setB[i] == 1) {
				kyo[i] = 1;
				kyoCount += 1;
			}
			if (setA[i] == 1 && setB[i] != 1) {
				cha[i] = 1;
				chaCount += 1;
			}
		}
		std::cout << kyoCount << " ";
		for (int i = 0; i < 132; ++i) {
			if (kyo[i] == 1)	printf("%d ", i);
		}
		std::cout << "\n" << hopCount << " ";
		for (int i = 0; i < 132; ++i) {
			if (hop[i] == 1)	printf("%d ", i);
		}

		std::cout << "\n" << chaCount << " ";
		for (int i = 0; i < 132; ++i) {
			if (cha[i] == 1)	printf("%d ", i);
		}
		std::cout << std::endl;
	}
	system("pause");
}