#include <iostream>
#include <cstring>

using namespace std;

bool binaryCmp(string s1, string s2) {
    if (s1.size() != s2.length()) return s1.size() < s2.size();
    return s1 <= s2;
}

string getBinaryStr(long long num) {
    string result = "";
    char tmp;
    while (num) {
        tmp = num % 2 + '0';
        result = tmp + result;
        num /= 2;
    }
    return result;
}

int evenCount(long long num) {
    int index = 0;
    string s;
    string target = getBinaryStr(num);
    for (long long i = 1; i <= 65536; i++) {
        s = getBinaryStr(i);
        for (int j = s.size() - 1; j >= 0; j--) {
            s += s[j];
        }
        if (binaryCmp(s, target)) index++;
        else break;
    }
    return index;
}

int oddCount(long long num) {
    int index = 0;
    string s;
    string target = getBinaryStr(num);
    for (long long i = 1; i <= 65536; i++) {
        s = getBinaryStr(i);
        for (int j = s.size() - 2; j >= 0; j--) {
            s += s[j];
        }
        if (binaryCmp(s, target)) index++;
        else break;
    }
    return index;
}

int main() {
    long long n;
    cin >> n;
    cout << evenCount(n) + oddCount(n) << endl;
}