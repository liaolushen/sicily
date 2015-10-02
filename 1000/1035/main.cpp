#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s1, string s2) {
	if (s1 == "" || s2 == "" || s1.length() != s2.length()) {
		return false;
	}
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] == 'A' && s2[i] != 'T') return false;
		if (s1[i] == 'T' && s2[i] != 'A') return false;
		if (s1[i] == 'C' && s2[i] != 'G') return false;
		if (s1[i] == 'G' && s2[i] != 'C') return false;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int output = 0;
		string DNA[101];
		for (int i = 0; i < N; ++i) {
			cin >> DNA[i];
		}
		for (int i = 0; i < N-1; ++i) {
			for (int j = i+1; j < N; ++j) {
				if (isMatch(DNA[i], DNA[j])) {
					DNA[i] = "";
					DNA[j] = "";
					output++;
				}
			}
		}
		cout << output << endl;
	}
	return 0;
}