#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> get_partial_match_table(string to_match) {
    vector<int> pmt(to_match.size());
    pmt[0] = 0;
    for (int i = 1; i < to_match.size(); i++) {
        if (to_match[i] == to_match[pmt[i - 1]]) {
            pmt[i] = pmt[i - 1] + 1;
        } else {
            pmt[i] = 0;
        }
    }
    return pmt;
}

int string_match(string content, string to_match) {
    vector<int> pmt = get_partial_match_table(to_match);
    int c_ptr = 0;
    int t_ptr = 0;
    while (c_ptr < content.size()) {
        if (content[c_ptr] == to_match[t_ptr]) {
            c_ptr++;
            t_ptr++;
        } else if (t_ptr > 0) {
            t_ptr = pmt[t_ptr];
        } else {
            c_ptr++;
        }
        if (t_ptr == to_match.size()) break;
    }
    if (t_ptr == to_match.size()) return c_ptr - to_match.size();
    else return -1;
}

int main(int argc, char const *argv[]) {
    cout << string_match("BBC ABCDAB ABCDABDABDE", "ABCDABD") << endl;
    return 0;
}
