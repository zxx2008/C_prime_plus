#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& a, int begin, int end) {
	if (begin < end) {
		int i = begin;
		int j = end;
		int x = a[begin];
		while (i < j) {
			while (i < j && a[j] >= x) j--;
			if (i < j) a[i++] = a[j];
			while (i < j && a[i] <= x) i++;
			if (i < j) a[j--] = a[i];
		}
		a[i] = x;
		QuickSort(a, begin, i - 1);
		QuickSort(a, i + 1, end);

	}
}

int main() {
	std::vector<int> a = { 1,4,3,8,2,10 };
	QuickSort(a, 0, 5);
	for (auto it = a.begin(); it != a.end(); ++it) {
		std::cout << *it << std::endl;
	}
}