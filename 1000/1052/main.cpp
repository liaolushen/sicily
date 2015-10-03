#include <vector>
#include <iostream>

using namespace std;

int main() {
	int N;
	while (cin >> N && N > 0) {
		vector<int> candy;
		int candyNum;
		for (int i = 0; i < N; ++i) {
			cin >> candyNum;
			candy.push_back(candyNum);
		}

		int rounds = 0;
		int endCandy;
		while(++rounds) {
			int toTurn = candy[candy.size()-1]/2;
			int maxCandy = 0;
			int minCandy = 100000;
			for (int i = 0; i < candy.size(); i++) {
				int tmp = candy[i]/2;
				candy[i] = candy[i]/2 + toTurn;
				if (candy[i] % 2 != 0) candy[i]++;
				if (candy[i] >= maxCandy) maxCandy = candy[i];
				if (candy[i] <= minCandy) minCandy = candy[i];
				toTurn = tmp;
 			}
 			if (minCandy == maxCandy) {
 				endCandy = maxCandy;
 				break;
 			}
		}
		cout << rounds << ' ' << endCandy << endl;
	}
}