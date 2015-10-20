#include <iostream>
#include <cstring>

using namespace std;

struct Card {
    int number;
    char suit;
} cards[5];

string cardNumber[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int getNumber(string num) {
    for (int i = 0; i < 13; ++i) {
        if (num == cardNumber[i]) return i;
    }
}

void exch(int *array, int index1, int index2) {
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

bool nextPermutation(int *array, int size) {
    // 从后往前，找到第一个 array[i-1] < array[i]的
    int index = -1;
    for (int i = size-1; i > 0; --i) {
        if (array[i] > array[i-1]) {
            index = i;
            break;
        }
    }
    if (index == -1) return false;

    // 从 array[n-1]到array[i]中找到一个比array[i-1]大的值
    int minIndex = index;
    for (int i = size-1; i > index; --i) {
        if (array[i] < array[minIndex] && array[i] > array[index-1]) {
            minIndex = i;
        }
    }

    // 交换 这两个值，并且把array[n-1]到array[i]排序，从小到大
    exch(array, index-1, minIndex);

    for (int i = index; i < size; ++i) {
        for (int j = index; j < size-1; ++j) {
            if (array[j] > array[j+1]) {
                exch(array, j, j+1);
            } 
        }
    }
    return true;
}

bool isLess(Card c1, Card c2) {
    if (c1.number != c2.number) return c1.number < c2.number;
    else return c1.suit < c2.suit;
}

int getValue(Card c1, Card c2, Card c3) {
    Card c[3] = {c1, c2, c3};
    int value = 0;
    int min = 1;
    for (int i = 2; i <=3; i++) {
        if (isLess(c[i-1], c[min-1])) min = i;
    }
    value += min;
    Card larger[2];
    int lSize = 0;
    for (int i = 1; i <= 3; ++i) {
        if (i == min) continue;
        larger[lSize++] = c[i-1];
    }
    if (isLess(larger[1], larger[0])) value += 3;
    return value;
}

int main() {
    int N;
    cin >> N;
    for (int index = 1; index <= N; index++) {
        string value;
        for (int i = 0; i < 5; i++) {
            cin >> value;
            cards[i].number = getNumber(string(value, 0, value.size()-1));
            cards[i].suit = value[value.size()-1];
        }
        int seq[5]  = {0, 1, 2, 3, 4};
        do {
            if (cards[seq[0]].suit != cards[seq[1]].suit) continue;
            int tmpNumber = cards[seq[1]].number;
            tmpNumber += getValue(cards[seq[2]], cards[seq[3]], cards[seq[4]]);
            tmpNumber %= 13;
            if (tmpNumber == cards[seq[0]].number) break;
        } while (nextPermutation(seq, 5));

        cout << "Problem " << index << ": ";
        for (int i = 0; i < 5; ++i) {
            cout << cardNumber[cards[seq[i]].number] << cards[seq[i]].suit;
            if (i != 4) cout << ' ';
            else cout << endl;
        }
    }
}