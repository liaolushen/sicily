#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int m, n;
    int i, j;
    int depth, width;
    bool valid;
    bool edge[101][101];
    bool visited[101];

    while (cin >> n >> m && n != 0) {
        queue<int> toSearch;
        memset(edge, false, sizeof(edge));
        memset(visited, false, sizeof(visited)); 
        while (m--) {
            cin >> i >> j;
            edge[i][j] = true;
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (edge[j][i]) break;
            }
            if (j > n) {
                toSearch.push(i);
                visited[i] = true;
            }
        }

        depth = 0;
        width = 0;
        valid = !toSearch.empty();

        int levelSize;
        int levelCount = 0;

        while (valid && !toSearch.empty()) {
            levelSize = toSearch.size();
            if (width < levelSize) width = levelSize;
            if (depth < levelCount) depth = levelCount;
            while (valid && levelSize--) {
                i = toSearch.front();
                for (j = 1; valid && j <= n; j++) {
                    if (edge[i][j]) {
                        if (visited[j]) {
                            valid = false;
                        } else {
                            toSearch.push(j);
                            visited[j] = true;
                        }
                    }
                }
                toSearch.pop();
            }
            levelCount++;
        }

        if (valid) {  
            for (i = 1; i <= n; i++) {  
                if (!visited[i]) {  
                    valid = false;  
                    break;  
                }  
            }  
        }  

  
        if (valid)  
            cout << depth << " " << width << endl;  
        else  
            cout << "INVALID" << endl;  
    }
}