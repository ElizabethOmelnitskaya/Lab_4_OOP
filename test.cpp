// lab4.cpp: определяет точку входа для консольного приложения.
//

#include "Fibonacci.h"
#include<algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	Fibonacci<int> f(7);
	cout << "Sequence Fibonacci of 7 numbers: " << endl;
	for (auto it = f.cbegin(); it != f.cend(); ++it) {
		cout << *it << endl;
	}
	
	Fibonacci<string> f1(7);
	vector<string> str;
	cout << "\nSequence Fibonacci of 7 numbers of type string: " << endl;
	for (auto it = f1.cbegin(); it != f1.cend(); ++it) {
		str.push_back(*it);
		cout << (*it) << endl;
	}

	sort(str.begin(), str.end());
	cout << "\nSort vector: " << endl;
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << endl;
	}
	
	system("pause");
	return 0;
}

