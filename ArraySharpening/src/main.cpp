#include <iostream>

static void skip(int size) {
	int temp;
	for (; size > 0; --size)
		std::cin >> temp;
}

static bool checkPeak() {
	int item = 0;
	std::cin >> item;

	const int size = item;

	if (size == 1) {
		skip(size);
		return true;
	}

	if (size == 2) {
		int item0;
		int item1;
		std::cin >> item0 >> item1;
		return item0 != item1 || (item0 == item1 && item0 > 0);
	}

	for (int i = 0; i < (size / 2); ++i) {
		std::cin >> item;
		if (item < i) {
			skip(size - i - 1);
			return false;
		}
	}

	if (size % 2 == 0) {
		int extraItem;
		std::cin >> extraItem;
		if (extraItem < (size / 2 - 1) || (extraItem == (size / 2 - 1) && extraItem == item)) {
			skip(size / 2 - 1);
			return false;
		}
	}

	for (int i = size / 2 - static_cast<int>(size % 2 == 0) * 2; i >= 0; --i) {
		std::cin >> item;
		if (item < i) {
			skip(i);
			return false;
		}
	}

	return true;
}

int main() {
	int nTests = 0;
	std::cin >> nTests;

	for (int i = 0; i < nTests; ++i) {
		const bool status = checkPeak();
		std::cout << (status ? "Yes" : "No") << std::endl;
	}
}
