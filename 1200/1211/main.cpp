#include <iostream>
#include <vector>

using namespace std;

int dp[101][101][101] = {0}; // dp[from][to][days]
vector<int> v[101];

int main() {
    int n, m, L;
    cin >> n >> m >> L;
    int from, to, days;
    while (m--) {
        cin >> from >> to;
        dp[from][to][1] = 1;
        v[from].push_back(to);
    }

    for (days = 2; days <= L; days++) {
        for (from = 1; from <= n; from++) {
            for (to = 1; to <= n; to++) {
                for (int i = 0; i < v[to].size(); i++) {
                    dp[from][v[to][i]][days] += dp[from][to][days - 1];
                }
            }
        }
    }
    
    int q, A, B;
    cin >> q;
    while (q--) {
        cin >> A >> B;
        cout << dp[A][B][L] << endl;
    }
}