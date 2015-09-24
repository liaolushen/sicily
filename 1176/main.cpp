#include <iostream>
#include <string>

using namespace std;

int a[1001];
int adj[1001][1001];
const int INFINITE = 1000000;

int getCard(int forePtr, int afterPtr) {
	if ((afterPtr - forePtr) <= 1) {
		return (a[forePtr] >= a[afterPtr]) ?
		(a[forePtr]- a[afterPtr]) : (a[afterPtr] - a[forePtr]);
	} else if (adj[forePtr][afterPtr] != INFINITE) {
		return adj[forePtr][afterPtr];
	} else {
		int r1; // user one get fore card
		int r2; // user one get after card
		if (a[forePtr+1] >= a[afterPtr]) {
			r1 = a[forePtr] - a[forePtr+1] + getCard(forePtr+2, afterPtr);
		} else {
			r1 = a[forePtr] - a[afterPtr] + getCard(forePtr+1, afterPtr-1);
		}

		if (a[forePtr] >= a[afterPtr-1]) {
			r2 = a[afterPtr] - a[forePtr] + getCard(forePtr+1, afterPtr-1);
		} else {
			r2 = a[afterPtr] - a[afterPtr-1] + getCard(forePtr, afterPtr-2);
		}
		adj[forePtr][afterPtr] = (r1 >= r2) ? r1 : r2;
		return adj[forePtr][afterPtr];
	}
}

int main() {
	int T;
	int index = 0;
	while (cin >> T && T != 0) {
		for (int i = 0; i < 1001; ++i) {
			for (int j = 0; j < 1001; ++j) {
				adj[i][j] = INFINITE;
			}
		}
		int result = 0;
		for (int i = 0; i < T; ++i) {
			cin >> a[i];
		}
		cout << "In game " << ++index <<", the greedy strategy might lose by as many as "
         << getCard(0, T - 1) << " points.\n";
	}
	return 0;
}
