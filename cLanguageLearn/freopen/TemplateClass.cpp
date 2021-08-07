#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <typename U>
class Stack {
private:
	vector<U> elems;    // elements 

public:
	void push(U const&);  // push element 
	void pop();               // pop element 
	U top() const;            // return top element 

	bool empty() const {      // return true if empty.
		return elems.empty();
	}
};

template <typename U>
void Stack<U>::push(U const& elem) {
	// append copy of passed element 
	elems.push_back(elem);
}

template <typename U>
void Stack<U>::pop() {
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}

	// remove last element 
	elems.pop_back();
}

template <typename U>
U Stack<U>::top() const {
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}

	// return copy of last element 
	return elems.back();
}

int main() {
	try {
		Stack<int>         intStack;  // stack of ints 
		Stack<string> stringStack;    // stack of strings 

		// manipulate int stack 
		intStack.push(7);
		cout << intStack.top() << endl;

		// manipulate string stack 
		stringStack.push("hello");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		return -1;
	}
}