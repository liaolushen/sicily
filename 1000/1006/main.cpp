#include <iostream>
#include <cstring>

using namespace std;
int medianRanking[5];
int num[101][5];

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
};

int indexOf(int* array, int entity) {
	for (int i = 0; i < 5; ++i) {
		if (array[i] == entity) return i;
	}
};

int getRankValue(int* array1, int* array2) {
	int value = 0;
	for (int i = 1; i < 5; ++i) {
		for (int j = i+1; j < 6; ++j) {
			if ((indexOf(array1, i)-indexOf(array1, j))*
				(indexOf(array2, i)-indexOf(array2, j)) < 0) {
				value++;
			}
		}
	}
	return value;
}

int getMedianRankingValue(int size) {
	int array[5] = {1, 2, 3, 4, 5};
	int medianRankingValue = 1000000;
	do {
		int rankValue = 0;
		for (int i = 0; i < size; ++i) {
			rankValue += getRankValue(num[i], array);
		}
		if (rankValue < medianRankingValue) {
			medianRankingValue = rankValue;
			for (int i = 0; i < 5; ++i) {
				medianRanking[i] = array[i];
			}
		}
	} while (nextPermutation(array, 5));
	return medianRankingValue;
}

int main() {
	int N;
	while (cin >> N && N != 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 5; j++) {
				char x;
				while (cin >> x && x <= 'E' && x >= 'A') {
					num[i][j] = x-'A'+1;
					break;
				}
			}
		}

		int value = getMedianRankingValue(N);
		for (int i = 0; i < 5; ++i) {
			char tmp;
			tmp = medianRanking[i] + 'A' - 1;
			cout << tmp;
		}
		cout << " is the median ranking with value "
		<< value
		<< "."
		<< endl;
	}
}