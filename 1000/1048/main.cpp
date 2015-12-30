#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int field[9] = {
    27, 63, 54,
    219, 511, 438,
    216, 504, 432
};

void push_next(string current_op, queue<string>& q) {
    char a;
    if (current_op == "") {
        a = '0';
    } else {
        a = current_op[current_op.size() - 1];
    }
    while (a < '9') {
        string to_add = current_op;
        a++;
        to_add += a;
        q.push(to_add);
    }
}

bool operate(string op, int status) {
    for (int i = 0; i < op.size(); i++) {
        int a = op[i] - '0';
        status = field[a - 1] ^ status;
    }
    if (status == 511) return true;
    else return false;
}

int input_to_int(string input) {
    int result = 0;
    int fact = 1;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'w') result += fact;
        fact *= 2;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    string input;
    while (N--) {
        cin >> input;
        int status = input_to_int(input);
        queue<string> q;
        q.push("");
        string op;
        while (!q.empty()) {
            op = q.front();
            q.pop();
            if (operate(op, status)) break;
            else push_next(op, q);
        }
        if (op == "") cout << "11" << endl;
        else cout << op << endl;
    }
}