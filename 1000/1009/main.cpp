#include <iostream>

using namespace std;

int primes[9] = {11,23,29,37,41,43,47,53,59};
long long factors[100];

int getFactors(long long num) {
	int index = 0;
	for (long long i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			factors[index] = i;
			index++;
			num /= i;
		}
	}
	factors[index] = num;
	return index;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; primes[i] <= n && i < 9; ++i) {
		long long composite = 1;
		for (int j = 0; j < primes[i]; ++j) {
			composite *= 2;
		}
		composite--;
		int index = getFactors(composite);
		for (int j = 0; j < index; ++j) {
			cout << factors[j] << " * ";
		}
		cout << factors[index] << " = ";
		cout << composite << " = ( 2 ^ "
			<< primes[i] << " ) - 1" << endl;
	}
}