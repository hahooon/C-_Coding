#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int testCase;
	fscanf(inp, "%d", &testCase);
	while (testCase--) {
		int subTest;
		unsigned int maxNum = 4294967295;
		std::vector<unsigned int> arr;
		fscanf(inp, "%d", &subTest);

		for (int i = 1; ; i *= 2) {
			for (int j = i; ; j *= 3) {
				for (int k = j; ; k *= 5) {
					arr.push_back(k);
					if (k > maxNum / 5) break;
				}
				if (j > maxNum / 3) break;
			}
			if (i > maxNum / 2) break;
		}
		std::sort(arr.begin(), arr.end());
		std::cout << arr[subTest - 1] << std::endl;
	}
	system("pause");
}