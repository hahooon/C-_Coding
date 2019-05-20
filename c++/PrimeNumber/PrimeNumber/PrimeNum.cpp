#include <vector>
#include <iostream>

int main() {
	int N = 7;
	long long answer = 0;
	std::vector<bool> check_Map(N + 1);
	for (int i = 2; i <= N; ++i) {
		if (check_Map[i] == false) {
			answer += i;
		}
		for (int j = i; j < N; j += i) {
			check_Map[j] = true;
		}
	}

	std::cout << answer << std::endl;


	system("pause");
}