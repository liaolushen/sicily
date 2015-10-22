#include <iostream>
#include <map>
#include <cstring>

using namespace std;

string toLower(string str) {
    for (int i = 0; i < str.size(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
    int n, m;
    while (cin >> n && n > 0) {
        cin >> m;
        map<string, bool> friends;
        string friendName;

        for (int i = 0; i < n; i++) {
            cin >> friendName;
            friends[toLower(friendName)] = false;
        }

        for (int i = 0; i < m; i++) {
            cin >> friendName;
            friends[toLower(friendName)] = true;
        }

        int index = 0;
        for (map<string, bool>::iterator it = friends.begin(); it != friends.end(); ++it) {
            if (it->second == false) index++;
        }
        cout << index << endl;
    }
}