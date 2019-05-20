#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (testCase--) {
		int guessNum = 0, strikeCount = 0, ballCount = 0, myStrikeCount = 0, myBallCount = 0;
		int cnt = 0, guessarr[4], myGuessarr[4], arr[10000], answerArr[10000], count = 0;
		fscanf(inp, "%d", &cnt);

		for (int i = 0; i < 10000; ++i) {
			arr[i] = i;
		}

		for (int i = 0; i < cnt; ++i) {
			fscanf(inp, "%d %d %d", &guessNum, &strikeCount, &ballCount);
			count = 0;
			for (int j = 0; j < 10000; ++j) {
				myStrikeCount = 0, myBallCount = 0;

				guessarr[0] = guessNum / 1000; guessarr[1] = guessNum % 1000 / 100;
				guessarr[2] = guessNum % 100 / 10; guessarr[3] = guessNum % 10;

				myGuessarr[0] = arr[j] / 1000; myGuessarr[1] = arr[j] % 1000 / 100;
				myGuessarr[2] = arr[j] % 100 / 10; myGuessarr[3] = arr[j] % 10;

				for (int k = 0; k < 4; ++k) {
					if (guessarr[k] == myGuessarr[k]) {
						guessarr[k] = 10;
						myGuessarr[k] = 10;
						++myStrikeCount;
					}
				}

				for (int k = 0; k < 4; ++k) {
					for (int p = 0; p < 4; ++p) {
						if (guessarr[p] == 10) {
							continue;
						}
						if (myGuessarr[k] == guessarr[p]) {
							myGuessarr[k] = 10;
							guessarr[p] = 10;
							++myBallCount;
						}
					}
				}
				if ((strikeCount != myStrikeCount) || (ballCount != myBallCount)) {
					arr[j] = 10000;
				}
				if (arr[j] != 10000) {
					answerArr[count] = arr[j];
					++count;
				}
			}
		}
		if (count > 1) {
			answerArr[0] = -1;
		}
		else if (count == 0) {
			answerArr[0] = -2;
		}
		std::cout << answerArr[0] << std::endl;
	}
	system("pause");
}