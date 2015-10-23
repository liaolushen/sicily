#include <iostream>
#include <cstring>

using namespace std;

int main() {
    bool tree[10001];
    memset(tree, false, sizeof(tree));
    int L, M;
    cin >> L >> M;
    int begin, end;
    while (M--) {
        cin >> begin >> end;
        for (int i = begin; i <= end; i++) {
            tree[i] = true;
        }
    }
    int index = 0;
    for (int i = 0; i <= L; i++) {
        if (tree[i] == false) index++;
    }
    cout << index << endl;
}