#include <iostream>
#include <cstring>

using namespace std;

bool isConnect[200][200];

int main() {
    int N, M;
    while (cin >> N && N != 0) {
        memset(isConnect, false, sizeof(isConnect));
        cin >> M;

        for (int i = 0; i < N; i++) isConnect[i][i] = true;

        int city1, city2;
        for (int i = 0; i < M; i++) {
            cin >> city1 >> city2;
            isConnect[city1][city2] = true;
            isConnect[city2][city1] = true;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (isConnect[i][k] && isConnect[k][j]) isConnect[i][j] = true;
                }
            }
        }
        if (isConnect[0][N-1]) cout << "I can post the letter" << endl;
        else cout << "I can't post the letter" << endl;
    }
}