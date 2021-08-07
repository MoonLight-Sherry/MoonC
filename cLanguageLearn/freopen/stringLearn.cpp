#include <string>
#include <iostream>
#include "freopenTest.h"

void stringTest() {
	const char * pName = "guaiguai88888";
	char nameArr[10] = "huahua";

	std::string name = "min hongjun";

	for (int i = 0; i < sizeof(pName) / sizeof(char); ++i) {
		std::cout << pName[i];
	}
	std::cout << std::endl;

	
		for (int i = 0; i < strlen(pName); ++i) {
			std::cout << pName[i];
		}
	std::cout << std::endl;

	for (int i = 0; i < sizeof(nameArr) / sizeof(nameArr[0]); ++i) {
		std::cout << nameArr[i];
	}
	std::cout << std::endl;

	for (int i = 0; i < name.size(); ++i) {
		std::cout << name[i] << name.at(i);
	}
	std::cout << std::endl;

	const char * pn = name.c_str();
	for (int i = 0; i < sizeof(pn) / sizeof(pn[0]); ++i) {
		std::cout << pn[i] << std::endl;
	}
}