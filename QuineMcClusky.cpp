#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct node {
	std::string binary_number;
	std::vector<int> decimal_number;
	int group;
	node* next;
	node() {
		binary_number = "";
		decimal_number = {};
		next = NULL;
		group = -1;
	}
};

struct binary_list {
	node* head;
	binary_list() { head = 0; }
	void insert_node(std::string bin, int dec);
	void insert_node(std::string bin, std::vector<int> dec);
	void print_list();
	bool isEmpty();
	int size();
};

int binary_list::size() {
	node* p;
	int counter = 0;
	p = head;
	while (p) {
		counter += 1;
		p = p->next;
	}
	return counter;
}

bool binary_list::isEmpty() {
	if (head == 0) return true;
	else return false;
}

int countOne(std::string bin) {
	int cnt = 0, j = 0;
	char c = ' ';
	while (c != 0) {
		c = bin[j];
		if (c == '1') {
			cnt += 1;
		}
		j += 1;
	}
	return cnt;
}


void binary_list::insert_node(std::string bin, std::vector<int> dec) {
	node* temp = new node;
	node* p = new node, *q = new node;
	temp->binary_number = bin;
	temp->decimal_number = dec;
	temp->group = countOne(bin);

	if (head == 0) {
		head = temp;
	}
	else {
		p = head;
		while (p != 0) {
			q = p; p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else q->next = temp;
	}

}


void binary_list::insert_node(std::string bin, int dec) {
	node* temp = new node;
	node* p = new node, *q = new node;
	temp->binary_number = bin;
	temp->decimal_number.push_back(dec);
	temp->group = countOne(bin);

	if (head == 0) {
		head = temp;
	}
	else {
		p = head;
		while (p != 0) {
			q = p; p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else q->next = temp;
	}
}

void print_vector(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); ++i) {
		if (i == vec.size() - 1) {
			std::cout << vec[i];
		}
		else std::cout << vec[i] << ", ";
	}
}

void binary_list::print_list() {
	node *p;
	if (!isEmpty()) {
		p = head;
		while (p) {
			std::cout << "Binary :    " << p->binary_number << "  Decimal :    ";
			print_vector(p->decimal_number);
			std::cout << "  Group :    " << p->group;
			p = p->next;
			std::cout << std::endl;
		}
	}
	else std::cout << "List is Empty\n";
}


std::string reverseString(std::string s) {
	size_t size = s.length();
	char temp;

	for (size_t i = 0; i < size / 2; i++) {
		temp = s[i];
		s[i] = s[(size - 1) - i];
		s[(size - 1) - i] = temp;
	}

	return s;
}

std::string decimal_Convert(int conversion_Number, int maxNum) {
	std::string binary_num = "";
	while (maxNum > 0) {
		if (conversion_Number % 2 == 1) {
			binary_num += "1";
		}
		else binary_num += "0";
		conversion_Number /= 2;
		maxNum -= 1;
	}
	return reverseString(binary_num);
}

int count_different(std::string str1, std::string str2) {
	int output = 0;
	for (int i = 0; i < str1.length(); ++i) {
		if ((str1[i] != str2[i]) && (str1[i] == '0' || str2[i] == '1')) {
			output += 1;
		}
	}
	return output;
}

int different_index(std::string str1, std::string str2) {
	for (int i = 0; i < str1.length(); ++i) {
		if ((str1[i] != str2[i]) && (str1[i] == '0' || str1[i] == '1' || str2[i] == '0' || str2[i] == '1')) {
			return i;
		}
	}
	return -1;
}

binary_list find_PI(binary_list binary) {
	binary_list outputList = binary_list();
	node *p, *q, *r;
	p = binary.head;
	q = p->next;
	int difCnt = 0;

	while (p) {
		q = p->next;
		while (q) {
			if ((q->group - p->group) == 1) {
				difCnt = count_different(p->binary_number, q->binary_number);
				if (difCnt == 1) {
					int difIDX = different_index(p->binary_number, q->binary_number);
					std::string temp = q->binary_number;
					temp.replace(difIDX, 1, "-");
					r = outputList.head;
					bool doubleCheck = false;
					while (r) {
						if (r->binary_number.compare(temp) == 0) {
							doubleCheck = true;
							break;
						}
						r = r->next;
					}
					if (doubleCheck == false) {
						std::vector<int> tempVEC = p->decimal_number;
						tempVEC.insert(tempVEC.end(), q->decimal_number.begin(), q->decimal_number.end());
						outputList.insert_node(temp, tempVEC);
					}
				}
				else if ((q->next != NULL) && (q->next->group - p->group == 1)) {
					if ((count_different(p->binary_number, q->next->binary_number) == 1)) {
						q = q->next;
						continue;
					}
				}
				else break;
				q = q->next;
			}
			else if (q->group - p->group == 0) {
				q = q->next;
			}
			else break;
		}
		p = p->next;
	}
	return outputList;
}

bool compare_list(binary_list list1, binary_list list2) {	//둘이 binary number가 모두 같으면 true, 다른게 하나라도 있으면 false
	node *p, *q;
	p = list1.head;
	q = list2.head;
	bool check = true;
	while ((p != NULL) && (q != NULL)) {
		if (p->binary_number.compare(q->binary_number) != 0) {
			check = false;
			break;
		}
		p = p->next;
		q = q->next;
	}
	return check;
}

binary_list guess_EPI(binary_list list, std::vector<int> decimalVEC) {
	node* p;
	binary_list outputList = binary_list();
	p = list.head;
	int size = list.size();
	std::vector<std::vector<int>> guessMap;
	for (int i = 0; i < decimalVEC.size(); ++i) {
		guessMap.push_back({ decimalVEC[i], 0 });
	}

	while (p) {
		for (int i = 0; i < p->decimal_number.size(); ++i) {
			for (int j = 0; j < guessMap.size(); ++j) {
				if (p->decimal_number[i] == guessMap[j][0]) {
					guessMap[j][1] += 1;
				}
			}
		}
		p = p->next;
	}

	node *r;
	for (int i = 0; i < guessMap.size(); ++i) {
		if (guessMap[i][1] == 1) {
			p = list.head;
			while (p) {
				for (int j = 0; j < p->decimal_number.size(); ++j) {
					if (guessMap[i][0] == p->decimal_number[j]) {
						bool doubleChecker = false;
						r = outputList.head;
						for (int i = 0; i < outputList.size(); ++i) {
							if (p->binary_number.compare(r->binary_number) == 0) {
								doubleChecker = true;
								break;
							}
						}
						if (doubleChecker == false) {
							outputList.insert_node(p->binary_number, p->decimal_number);
						}
					}
				}
				p = p->next;
			}
		}
	}

	return outputList;
}

binary_list find_nepi(binary_list list1, binary_list list2) {
	node* p, *q;
	binary_list outputList = binary_list();
	p = list1.head;
	q = list2.head;
	bool checker;	// EPI가 list1에 있다면 true, 아니면 false
	while (p) {
		checker = false;
		while (q) {
			if (p->binary_number.compare(q->binary_number) == 0) {
				checker = true;
				break;
			}
			q = q->next;
		}
		if (checker == false) {
			outputList.insert_node(p->binary_number, p->decimal_number);
		}
		p = p->next;
	}

	return outputList;
}

bool cmp(std::string a, std::string b) {
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == '-') {
			a[i] = '2';
		}
		if (b[i] == '-') {
			b[i] = '2';
		}
	}
	return a < b;
}

std::vector<std::string> inputAnswer(std::vector<std::string> ans, binary_list epiORnepi, std::string cmd) {
	ans.push_back(cmd);
	std::vector<std::string> temp;
	node *p;
	p = epiORnepi.head;
	while (p) {
		temp.push_back(p->binary_number);
		p = p->next;
	}
	std::sort(temp.begin(), temp.end(), cmp);
	ans.insert(ans.end(), temp.begin(), temp.end());
	return ans;
}

int main() {
	std::vector<int> input = { 3, 6, 0, 1, 2, 5, 6, 7 };
	std::vector<std::string> answer;
	std::vector<int> decVEC;
	binary_list binary = binary_list();
	binary_list EPI_Candidate, EPI, NEPI;
	for (int i = 0; i < input[1]; ++i) {
		binary.insert_node(decimal_Convert(input[i + 2], input[0]), input[i + 2]);
		decVEC.push_back(input[i + 2]);
	}

	EPI_Candidate = find_PI(binary);
	while (compare_list(EPI_Candidate, find_PI(EPI_Candidate)) != true) {
		EPI_Candidate = find_PI(EPI_Candidate);
	}

	EPI = guess_EPI(EPI_Candidate, decVEC);
	NEPI = find_nepi(EPI_Candidate, EPI);
	/*EPI_Candidate.print_list();
	std::cout << "-----------------------------" << std::endl;
	EPI.print_list();
	std::cout << "-----------------------------" << std::endl;
	NEPI.print_list();*/
	answer = inputAnswer(answer, EPI, "EPI");
	answer = inputAnswer(answer, NEPI, "NEPI");

	for (int i = 0; i < answer.size(); ++i) {
		std::cout << answer[i] << ", ";
	}
	

	system("pause");
}