#include <iostream>

using namespace std;

int getSum(int num, int base) {
	int result = 0;
	for (int i = 3; i >= 0; i--) {
		int currentBase = base;
		for (int j = 0; j < i; j++) {
			currentBase *= base;
		}
		result += num/currentBase;
		num %= currentBase;
	}
	result += num;
	return result;
}

int main() {
	for (int num = 1000; num < 10000; num++) {
		if ((getSum(num, 10) == getSum(num, 12)) && (getSum(num, 12) == getSum(num, 16))) {
			cout << num << endl;
		}
	}
}