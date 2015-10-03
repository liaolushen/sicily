#include <iostream>

using namespace std;

int main() {
	int N;
	while (cin >> N && N > 0) {
		if (N <= 2) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
}