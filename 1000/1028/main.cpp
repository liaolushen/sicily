#include <iostream>
#include <string>

using namespace std;

string divByTwo(string p) {
    string toReturn = "";
    int carry = 0;
    for (int i = 0; i < p.size(); i++) {
        int num = (p[i] - '0') + carry * 10;
        int result = num / 2;
        carry = num % 2;
        if (result != 0 || toReturn.length() != 0) {
            char tmp = result + '0';
            toReturn += tmp;
        }
    }
    if (carry) toReturn += '1';
    return toReturn;
}

bool isEven(string p) {
    int lastInt = p[p.size()-1]-'0';
    return lastInt % 2 == 0;
}

int main() {
    int N;
    cin >> N;
    for (int index = 1; index <= N; ++index) {
        string p;
        cin >> p;
        int n = 1;
        while (isEven(p)) {
            p = divByTwo(p);
            n++;
        }
        cout << "Case " << index << ": " << n << endl;
        if (index != N) cout << endl;
    }
}