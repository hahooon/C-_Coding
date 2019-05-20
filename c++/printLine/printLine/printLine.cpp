#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int test_case = 0, num = 0;
	fscanf(inp, "%d", &test_case);
	while (num < test_case) {
		int cnt = 0;
		fscanf(inp, "%d", &cnt);
		
		++num;
	}
}