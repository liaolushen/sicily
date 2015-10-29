#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_NUM 10000

bool primes[10001];
vector<int> result;
bool isUsed[1001];
int beginNum, endNum, degree;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void getPrimes() {
    for (int i = 2; i <= MAX_NUM; i++) {
        if (isPrime(i)) primes[i] = true;
        else primes[i] = false;
    }
}

bool canInsert(int num) {
    if (isUsed[num]) return false;
    int currentDegree = 2;
    while (currentDegree <= result.size() + 1 && currentDegree <= degree) {
        num += result[result.size() - currentDegree + 1];
        if (primes[num]) return false;
        currentDegree++;
    }
    return true;
}

bool dfs() {
    for (int i = beginNum; i <= endNum; i++) {
        if (canInsert(i)) {
            result.push_back(i);
            isUsed[i] = true;
            if (result.size() == endNum - beginNum + 1) return true;
            if(dfs()) {
                return true;
            } else {
                result.pop_back();
                isUsed[i] = false;
            }
        }
    }
    return false;
}

int main() {
    getPrimes();
    while (cin >> beginNum >> endNum >> degree && beginNum && endNum && degree) {
        result.clear();
        memset(isUsed, false, sizeof(isUsed));
        int size = endNum - beginNum + 1;
        bool isOk = dfs();
        if (isOk) {
            for (int i = 0; i < size; ++i) {
                cout << result[i];
                if (i != size - 1) cout << ',';
                else cout << endl;
            }
        } else {
            cout << "No anti-prime sequence exists." << endl;
        }
    }
}