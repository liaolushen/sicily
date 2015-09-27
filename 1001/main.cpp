#include <iostream>
#include <cstring>

using namespace std;

int convertToInt(string str) {
	return (str[0]-'0')*10 + (str[1]-'0');
}

int main() {
	string str;
	while (cin >> str && str != "0") {
		int sum = 0;
		if (str.length() == 1) {
			sum = 1;
		} else if (str.length() == 2) {
			if (convertToInt(str) > 26 || convertToInt(str) % 10 == 0) {
				sum = 1;
			} else {
				sum = 2;
			}
		} else {
			int index = 2;
			int first = 1;
			int second;
			string tmpStr = str.substr(0, 2);
			if (convertToInt(tmpStr) > 26 || convertToInt(tmpStr) % 10 == 0) {
				second = 1;
			} else {
				second = 2;
			}
			while (index < str.length()) {
				if (str[index] == '0' &&
					(str[index-1] > '2' || str[index-1] == '0')) {
					cout << 0 << endl;
					return 0;
				}
				tmpStr = str.substr(index-1, 2);
				if (convertToInt(tmpStr) > 26 || convertToInt(tmpStr) < 10) {
					first = second;
				} else if (convertToInt(tmpStr) % 10 == 0) {
					second = first;
				} else {
					int tmp = first + second;
					first = second;
					second = tmp;
				}
				index++;
			}
			sum = second;
		}
		cout << sum << endl;
	}
}