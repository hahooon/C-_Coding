#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::ifstream inp("input.txt");
	std::string temp = "";
	int testCase;
	inp >> testCase;

	std::string morseToAlpha[26][2] = {
		{".-","A"}, {"-...","B"}, {"-.-.","C"}, {"-..","D"}, {".","E"}, {"..-.","F"},
	{"--.","G"}, {"....","H"}, {"..","I"}, {".---","J"}, {"-.-","K"},
	{".-..","L"}, {"--","M"}, {"-.","N"}, {"---","O"}, {".--.","P"},
	{"--.-","Q"}, {".-.","R"}, {"...","S"}, {"-","T"}, {"..-","U"},
	{"...-","V"}, {".--","W"}, {"-..-","X"}, {"-.--","Y"}, {"--..","Z"}
	};

	while (testCase--) {
		std::string morseCode, subMorse, decodeMorseToAlpha;
		inp >> morseCode;
		int index = 0, len = 0, lastIndex = 0, check = 0;
		for (int i = 0; i < morseCode.length(); ++i) {
			if (morseCode[i] == '|') {
				check = 1;
				lastIndex = i;
				if (index == 0) {
					subMorse = morseCode.substr(index, len);
					for (int j = 0; j < 26; ++j) {
						if (morseToAlpha[j][0] == subMorse) {
							decodeMorseToAlpha += morseToAlpha[j][1];
							break;
						}
					}
					len = 0;
					index = i + 1;
				}

				else {
					subMorse = morseCode.substr(index, len);
					for (int j = 0; j < 26; ++j) {
						if (morseToAlpha[j][0] == subMorse) {
							decodeMorseToAlpha += morseToAlpha[j][1];
							break;
						}
					}
					len = 0;
					index = i + 1;
				}
			}

			else if (morseCode[i] == '#') {
				subMorse = morseCode.substr(index, len);
				for (int j = 0; j < 26; ++j) {
					if (morseToAlpha[j][0] == subMorse) {
						decodeMorseToAlpha += morseToAlpha[j][1];
						break;
					}
				}
				decodeMorseToAlpha += "_";
				len = 0;
				index = i + 1;
			}
			else {
				++len;
			}
		}
		if (check == 0) {
			for (int j = 0; j < 26; ++j) {
				if (morseToAlpha[j][0] == morseCode) {
					decodeMorseToAlpha = morseToAlpha[j][1];
					break;
				}
			}
		}
		if (lastIndex != 0) {
			subMorse = morseCode.substr(lastIndex+1, len);
			for (int j = 0; j < 26; ++j) {
				if (morseToAlpha[j][0] == subMorse) {
					decodeMorseToAlpha += morseToAlpha[j][1];
					break;
				}
			}
		}
		std::cout << decodeMorseToAlpha << std::endl;
	}
	inp.close();
	system("pause");
	return 0;
}