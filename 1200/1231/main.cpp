#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> primes;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void getPrimes(int biggestNum) {
    for (int i = 2; i <= biggestNum; i++) {
        if (isPrime(i)) primes.push_back(i);
    }
}

bool isFactor(string key, int num) {
    int result = 0;
    for (int i = 0; i < key.size(); ++i) {
        result =  result * 10 + (key[i] - '0');
        result %= num;
    }
    return result == 0;
}

int main() {
    string K;
    int L;
    getPrimes(1000100);
    while (cin >> K >> L && K != "0" && L != 0) {
        bool isGood = true;
        vector<int>::iterator it;
        for (it = primes.begin(); *it < L && it != primes.end(); ++it) {
            if (isFactor(K, *it)) {
                isGood = false;
                break;
            }
        }
        if (isGood) {
            cout << "GOOD" << endl;
        } else {
            cout << "BAD " << *it << endl;
        }
    }
}