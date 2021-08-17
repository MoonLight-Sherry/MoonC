#include <iostream>     // std::cout
#include <fstream>

int getName();
int readFileTest();
int twoDArrayTest();
int twoDCharPointerArrayTest();

struct MyClass {
	MyClass() { std::cout << "MyClass constructed" <<std::endl; }
	~MyClass() { std::cout << "MyClass destroyed" << std::endl; }
};

int main() {

	twoDCharPointerArrayTest();
	//twoDArrayTest();
	//readFileTest();
	//getName();
}


#include <string>

int getName()
{
	std::string name;

	std::cout << "Please, enter your full name: ";
	std::getline(std::cin, name);
	std::cout << "Hello, " << name << "!\n";

	return 0;
}

int testClassArrayCreate()
{
	MyClass * pt;
	int n;
	std::cout << "Please input n: " << std::endl;
	std::cin >> n;

	pt = new MyClass[n];
	delete[] pt;

	return 0;
}

using namespace std;

int readFileTest()
{
	ifstream sourceCode("myclass.cpp");
	for (string line; getline(sourceCode, line);)
		cout << line << endl;
	return 0;
}

int twoDArrayTest()
{
	int array[3][10] = { { 1,2,3,4 },
	{ 5,6,7,8 }
	};
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		for (int j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++) {
			cout << array[i][j] << ", ";
		}
		cout << endl;
	}
			return 0;
}

int twoDCharPointerArrayTest()
{
	char name[3][10] = { "huahua","guaiguai","junjun"};
	for (int i = 0; i < sizeof(name) / sizeof(name[0]); i++) {
		cout << "name is: " << name[i] << endl;
		for (int j = 0; j < sizeof(name[0]) / sizeof(name[0][0]); j++) {
			if (name[i][j] == 0) {
				name[i][j] = 'z';
			}
			cout << name[i][j] << ", ";
		}
		cout << endl;
		cout << "name is: " << name[i] << endl;
	}
	return 0;
}