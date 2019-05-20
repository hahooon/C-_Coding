#include <iostream>
#include <string>

class Book {
private:
	int isbn;
	std::string title;
public:
	Book() : isbn(0), title("unknown")
	{	
	}
	Book(int isbn) {
		this->isbn = isbn;
		this->title = "unknown";
	}
	void display() {
		std::cout << isbn << ":" << title << std::endl;
	}
};

int main() {
	Book b1 = 13241234;
	b1.display();
	Book b2 = Book(56785678);
	b2.display();
	system("pause");
}