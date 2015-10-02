#include <string>
#include <iostream>

using namespace std;

int sort(string* skey, string* svalue, int size) {
	for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (skey[j] < skey[j+1]) {
                string tmp = skey[j];
                skey[j] = skey[j+1];
                skey[j+1] = tmp;

                tmp = svalue[j];
                svalue[j] = svalue[j+1];
                svalue[j+1] = tmp;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        string names[21];
        string ips[21];
        for (int i = 0; i < T; i++) {
            cin >> names[i];
            cin >> ips[i];
        }

        sort(ips, names, T);

        string MJ_ID[11];
        string main_ID[11];

        for (int i = 0; i < T; i++) {
        	main_ID[i/2] = names[i];
        	MJ_ID[i/2] = names[++i];
        }

        sort(main_ID, MJ_ID, T/2);

        for (int i = T/2-1; i >= 0; --i) {
        	cout << MJ_ID[i] << " is the MaJia of " << main_ID[i] << endl;
        }
        cout << endl;
        cin >> T;
    }
    return 0;
}
