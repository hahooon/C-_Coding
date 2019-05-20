#include <iostream>
#include <fstream>

class Stack {
public:
	int stack[100]; int top;	//스택에 row,col,dir 순으로 쌓는다.
	Stack() { top = -1; }
	void push(int val) { stack[++top] = val; }
	int pop() { return stack[top--]; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == 99; }
	void clear() {
		while (top != -1) {
			int a = 0;
			a = pop();
		}
	}
};

struct ConnectFour {
private:
	int checkerBoard[9][8] = { 0, };
	int count1 = 0;
	int count2 = 0;
public:
	void inputStones(int check, int data);
	void format();
	void printBoard();
	int findWinner();
};

struct offsets {
	short int vert;
	short int horiz;
};

offsets move[8];

void makeMove() {
	move[2].vert = 0;  move[2].horiz = 1;   //e
	move[3].vert = 1;  move[3].horiz = 1;   //se
	move[4].vert = 1;  move[4].horiz = 0;   //s
	move[5].vert = 1;  move[5].horiz = -1;  //sw
}

int ConnectFour::findWinner() {
	makeMove();

}

void ConnectFour::printBoard() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 8; ++j) {
			std::cout << checkerBoard[i][j];
		}
		std::cout << std::endl;
	}
}

void ConnectFour::format() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 8; ++j) {
			checkerBoard[i][j] = 0;
		}
	}
}

void ConnectFour::inputStones(int check, int data) {
	int index = 1;
	while (checkerBoard[data][index] != 0) {
		++index;
	}
	if (check == 1) {
		checkerBoard[data][index] = 1;
	}
	else {
		checkerBoard[data][index] = 2;
	}
}

int main() {
	int testCase;
	FILE* inp;
	inp = fopen("input.txt", "r");
	fscanf(inp, "%d", &testCase);
	
	while (testCase--) {
		ConnectFour connectFour;
		int subTestCase, check = 1;
		fscanf(inp, "%d", &subTestCase);
		connectFour.format();

		while (subTestCase--) {
			int data;
			fscanf(inp, "%d", &data);
			connectFour.inputStones(check, data);
			check = check == 1 ? 2 : 1;
		}
		connectFour.printBoard();
	}
	system("pause");
}