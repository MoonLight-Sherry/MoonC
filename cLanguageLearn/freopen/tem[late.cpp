#include <iostream>
#include <string>

template <typename U>
U max(U a, U b) {
	return b < a ? a : b;
}

int mainp() {
	std::cout << ::max(1, 3);       // 3
	std::cout << ::max(1.0, 3.14);  // 3.14
	std::string s1 = "mathematics";
	std::string s2 = "math";
	std::cout << ::max(s1, s2);  // mathematics
	return 0;
}