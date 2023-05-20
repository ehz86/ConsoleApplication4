#include <iostream>
#include "SList.cpp"
#include <string>

class Stack {
public:
	LinkedList llist;
	void push(int data) {
		llist.addElement(data);
	}
	int pop() {
		if (llist.isEmpty()) {
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		return llist.showlastanddelete();
	}

	bool isEmpty() const {
		return llist.isEmpty();
	}
	
};

class pcalc {
private:
	Stack stack;

private:
	bool isOperator(char op) {
		return op == '+' || op == '-' || op == '*' || op == '/';
	}

	int operation(char op, int op1, int op2) {
		switch (op) {
		case('+'):
			return op1 + op2;
		case('-'):
			return op1 - op2;
		case('*'):
			return op1 * op2;
		case('/'):
			if (op2 == 0) {
				std::cout<<"Error";
				exit(1);
			}
			return op1 / op2;
		default:
			return 0;
		}
	}
public:
	int calc(std::string s) {
		int size = s.length();

		for (int i = 0; i < size; i++) {
			if (isdigit(s[i])) {
				int num = 0;
				while (i < size && isdigit(s[i])) {
					num = num * 10 + (s[i] - '0');
					i++;
				}
				stack.push(num);
				
			}
			else if (s[i] == ' ') {
				continue;
			}
			else {
				int op1 = stack.pop();
				int op2 = stack.pop();
				int res = operation(s[i], op1, op2);
				stack.push(res);
				
			}
		}
		return stack.pop();
	}
	
		
};

int main()
{
	pcalc calcc;
	std::string s;
	std::cout << "Write:";
	std::getline(std::cin, s);
	int res = calcc.calc(s);
	std::cout << "Result: " << res;
	
	

}