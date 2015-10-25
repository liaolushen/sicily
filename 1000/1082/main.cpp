#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> removalList;
vector<int> processes;
int managerPolicy;
int index;

void processAdd() {
    int newProcess;
    cin >> newProcess;
    for (vector<int>::iterator it = processes.begin();
        it != processes.end(); ++it) {
        if (*it >= newProcess) {
            processes.insert(it, newProcess);
            return;
        }
    }
    processes.push_back(newProcess);
}

void processRemove() {
    int removedProcess;
    if (processes.empty()) {
        removedProcess = -1;
    } else {
        if (managerPolicy == 1) {
            removedProcess = processes.front();
            processes.erase(processes.begin());
        } else {
            removedProcess = processes.back();
            processes.pop_back();
        }
    }
    if (removalList.front() == ++index) {
        cout << removedProcess << endl;
        removalList.erase(removalList.begin());
    }
}

int main() {
    int maxCost, n;
    bool isFirst = true;
    while (cin >> maxCost) {
        if (isFirst) isFirst = false;
        else cout << endl;

        cin >> n;
        removalList.clear();
        processes.clear();

        int pNumber;
        while (n--) {
            cin >> pNumber;
            removalList.push_back(pNumber);
        }
        sort(removalList.begin(), removalList.end());

        managerPolicy = 1;
        index = 0;
        char operation;
        while (cin >> operation && operation != 'e') {
            if (operation == 'a') processAdd();
            else if (operation == 'r') processRemove();
            else if (operation == 'p') cin >> managerPolicy;
        }
    }
}