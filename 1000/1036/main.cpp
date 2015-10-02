#include <iostream>
#include <cstring>

using namespace std;

char Mes[101][101];

void getOrder(string keyword, int* keyorder) {
	char unorderedKey[101];
	char orderedKey[101];
	strcpy(unorderedKey, keyword.c_str());
	strcpy(orderedKey, keyword.c_str());

	for (int i = 0; i < keyword.length()-1; ++i) {
		for (int j = i+1; j < keyword.length(); ++j) {
			if (orderedKey[i] > orderedKey[j]) {
				char tmp = orderedKey[i];
				orderedKey[i] = orderedKey[j];
				orderedKey[j] = tmp;
			}
		}
	}


	for (int i = 0; i < keyword.length(); ++i){
		for (int j = 0; j < keyword.length(); ++j) {
			if (unorderedKey[j] == orderedKey[i]) {
				unorderedKey[j] = '*';
				keyorder[i] = j;
				break;
			}
		}
	}
}

int main() {
	string keyword;
	while (cin >> keyword && keyword != "THEEND") {
		string encryptedMes;
		cin >> encryptedMes;
		int keyorder[101];
		getOrder(keyword, keyorder);

		int colLength = encryptedMes.length()/keyword.length();
		for (int i = 0; i < keyword.length(); ++i) {
			for (int j = 0; j < colLength; ++j) {
				Mes[keyorder[i]][j] = encryptedMes[i*colLength + j];
			}
		}
		string result = "";

		for (int i = 0; i < colLength; ++i) {
			for (int j = 0; j < keyword.length(); ++j) {
				result += Mes[j][i];
			}
		}
		cout << result <<endl;
	}
}