#include <iostream>
#include <fstream>

int main() {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int n = 0, testCase = 0;
	fscanf(inp, "%d", &testCase);
	while (n < testCase) {
		int ax, bx, cx, ay, by, cy, lenAB, lenBC, lenCA, booleanNum;
		fscanf(inp, "%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
		lenAB = (ax - bx)*(ax - bx) + (ay - by)*(ay - by);
		lenBC = (bx - cx)*(bx - cx) + (by - cy)*(by - cy);
		lenCA = (cx - ax)*(cx - ax) + (cy - ay)*(cy - ay);

		//lenAB = (lenAB > 0) ? lenAB : (-1)*lenAB;
		//lenBC = (lenBC > 0) ? lenBC : (-1)*lenBC;
		//lenCA = (lenCA > 0) ? lenCA : (-1)*lenCA;
		int temp = 0;
		if (lenAB > lenBC) {
			if (lenAB > lenCA) {
				temp = lenAB;
				lenAB = lenCA;
				lenCA = temp;
			}
		}
		else {
			if (lenBC > lenCA) {
				temp = lenBC;
				lenBC = lenCA;
				lenCA = temp;
			}
		}
		if (!(ax == ay && bx == by && cx == cy) && (!(ax == bx && ay == by) && !(ax == cx && ay == cy) && !(bx == cx && by == cy))) {
			if (lenCA > lenAB + lenBC) {
				booleanNum = 2;
			}
			else if (lenCA == lenAB + lenBC) {
				booleanNum = 1;
			}
			else { booleanNum = 3; }
		}
		else { booleanNum = 0; }
		std::cout << booleanNum << std::endl;
		++n;
	}
	system("pause");
}