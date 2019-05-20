#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int n = 0, testCase = 0;
	fscanf(inp, "%d", &testCase);

	while (n < testCase) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		fscanf(inp, "%d %d %d %d", &x1, &y1, &x2, &y2);

		int dotx = 0, doty = 0, linearDis = 0, angleDis = 0;
		fscanf(inp, "%d %d", &dotx, &doty);

		if ((x1 <= dotx && dotx <= x2) && (y1 <= doty && doty <= y2)) {
			linearDis = 0;
			angleDis = 0;
		}
		else if (x1 <= dotx && dotx <= x2) {
			if (doty <= y1) {
				linearDis = (y1 - doty) * (y1 - doty);
				angleDis = y1 - doty;
			}
			else {
				linearDis = (doty - y2) * (doty - y2);
				angleDis = doty - y2;
			}
		}
		else if (y1 <= doty && doty <= y2) {
			if (dotx <= x1) {
				linearDis = (x1 - dotx) * (x1 - dotx);
				angleDis = x1 - dotx;
			}
			else {
				linearDis = (dotx - x2) * (dotx - x2);
				angleDis = (dotx - x2);
			}
		}
		else {
			if (dotx > x2 && doty > y2) {
				linearDis = (dotx - x2)*(dotx - x2) + (doty - y2)*(doty - y2);
				angleDis = dotx - x2 + doty - y2;
			}
			else if (dotx < x1 && doty > y2) {
				linearDis = (x1 - dotx)*(x1 - dotx) + (doty - y2)*(doty - y2);
				angleDis = x1 - dotx + doty - y2;
			}
			else if (dotx < x1 && doty < y1) {
				linearDis = (x1 - dotx)*(x1 - dotx) + (y1 - doty)*(y1 - doty);
				angleDis = x1 - dotx + y1 - doty;
			}
			else if (dotx > x2 && doty < y1) {
				linearDis = (dotx - x2)*(dotx - x2) + (y1 - doty)*(y1 - doty);
				angleDis = dotx - x2 + y1 - doty;
			}
		}
		std::cout << linearDis << " " << angleDis << std::endl;
		++n;
	}
	system("pause");
}