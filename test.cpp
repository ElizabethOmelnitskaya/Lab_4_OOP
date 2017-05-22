#include "Fibonacci.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

	cout << "Input x: " << endl;
	int x = 0;
	cin >> x;

	Fibonacci<string> fib = Fibonacci<string>(5);
	vector<string> vect = vector<string>();

	for (Fibonacci<string>::const_iterator iter = fib.cend() - x; iter != fib.cbegin() + x; iter -= 1)
		vect.push_back(*iter);
	sort(vect.begin(), vect.end());
	system("pause");
	return 0;
}
