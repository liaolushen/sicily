#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int T;
	while (cin >> T && T > 0) {
		string encryptedMes;
		string originMes = "";
		cin >> encryptedMes;
		for (int i = 0; i < T; ++i) {
			bool isNeighbor = false;
			for (int j = i; j < encryptedMes.length();) {
				originMes += encryptedMes[j];
				if (isNeighbor) {
					j += i*2+1;
					isNeighbor = false;
				} else {
					j += (T-i-1)*2 + 1;
					isNeighbor = true;
				}
			}
		}
		cout << originMes << endl;
	}
	return 0;
}