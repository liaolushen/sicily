#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Child {
    int hasBlock;
    int needBlock;
};

int main() {
    int n, s;
    while (cin >> n >> s && n != 0) {
        vector<Child> children;
        for (int i = 0; i < n; ++i) {
            Child child;
            cin >> child.hasBlock >> child.needBlock;
            children.push_back(child);
        }

        int currentBlock = s;
        bool isGoOn = true;
        while (isGoOn && !children.empty()) {
            isGoOn = false;
            for (vector<Child>::iterator it = children.begin(); it != children.end();) {
                if (it->needBlock <= currentBlock) {
                    currentBlock += it->hasBlock;
                    it = children.erase(it);
                    isGoOn = true;
                } else {
                    it++;
                }
            }
        }

        if (children.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}