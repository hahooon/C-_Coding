#include <iostream>
#include <fstream>
#include <string>

int findCheckSome(std::string subTestCase) {
	int sum = 0, length = subTestCase.length();
	for (int i = 0; i < length - 1; ++i) {
		if (length % 2 == 0) {
			if (i % 2 == 0) {
				if ((subTestCase[i] - '0') * 2 >= 10) {
					sum += (subTestCase[i] - '0') * 2 - 9;
				}
				else {
					sum += (subTestCase[i] - '0') * 2;
				}

			}
			else {
				sum += (subTestCase[i] - '0');
			}
		}
		else {
			if (i % 2 == 0) {
				sum += (subTestCase[i] - '0');
			}
			else {
				if ((subTestCase[i] - '0') * 2 >= 10) {
					sum += (subTestCase[i] - '0') * 2 - 9;
				}
				else {
					sum += (subTestCase[i] - '0') * 2;
				}
			}
		}
	}
	if (sum % 10 == 0) {
		return 0;
	}
	else {
		return 10 - (sum % 10);
	}
}

void discriminateCheckSome(std::string subTestCase) {
	int checkSome, length = subTestCase.length();
	checkSome = findCheckSome(subTestCase);

	if (checkSome == subTestCase[length - 1] - '0')
		std::cout << 1 << std::endl;
	
	else
		std::cout << 0 << std::endl;
}

int main() {
	std::ifstream inp;
	inp.open("input.txt");
	int test = 0;
	inp >> test;

	while (test--) {
		std::string subTestCase;
		inp >> subTestCase;
		int length = subTestCase.length(), sum = 0;

		if (subTestCase[0] == '3' && (length == 15 || length == 14)) {
			discriminateCheckSome(subTestCase);
		}
		else if (subTestCase[0] == '6' && length == 16) {
			discriminateCheckSome(subTestCase);
		}
		else if (subTestCase[0] == '5' && length == 16) {
			discriminateCheckSome(subTestCase);
		}
		else if (subTestCase[0] == '4' && (length == 13 || length == 16)) {
			discriminateCheckSome(subTestCase);
		}
		else {
			std::cout << 0 << std::endl;
		}
	}
	inp.close();
	system("pause");
	return 0;
}