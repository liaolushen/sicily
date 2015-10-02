#include <iostream>

using namespace std;

#define INFINITE -10000000

int target;
int result;

int initArray(int* m1, int*m, int i, int j, int size) {
	int index = 0;
	for (int x = 0; x < size; ++x) {
		if (x != i && x != j) {
			m1[index] = m[x];
			index++;
		}
	}
	return index;
}

void getValue(int* m, int size) {
	for (int i = 0; i < size; ++i) {
		if (m[i] <= target && m[i] > result) {
			result = m[i];
		}
	}
	if (size == 1) return;
	if (result == target) return;

	for (int i = 0; i < size; ++i) {
		for (int j = i+1; j < size; ++j) {
			int m1[5];
			int index;
			index = initArray(m1, m, i, j, size);
			m1[index] = m[i] + m[j];
			getValue(m1, index+1);

			index = initArray(m1, m, i, j, size);
			m1[index] = m[i] - m[j];
			getValue(m1, index+1);

			index = initArray(m1, m, i, j, size);
			m1[index] = m[j] - m[i];
			getValue(m1, index+1);

			index = initArray(m1, m, i, j, size);
			m1[index] = m[j] * m[i];
			getValue(m1, index+1);

			if (m[j] != 0 && m[i]%m[j] == 0) {
				index = initArray(m1, m, i, j, size);
				m1[index] = m[i] / m[j];
				getValue(m1, index+1);
			}

			if (m[i] != 0 && m[j]%m[i] == 0) {
				index = initArray(m1, m, i, j, size);
				m1[index] = m[j] / m[i];
				getValue(m1, index+1);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		int Mi[5];
		result = INFINITE;
		for (int i = 0; i < 5; ++i) {
			cin >> Mi[i];
		}
		cin >> target;
		getValue(Mi, 5);
		cout << result << endl;
	}
	return 0;
}