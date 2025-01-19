#include <iostream>

struct Range {
	int lo;
	int hi;
};

struct Person {
	int time;
	Range tempRange;
};

static bool intersectionRanges(const Range& a, const Range& b, Range& out) {
	out.lo = std::max(a.lo, b.lo);
	out.hi = std::min(a.hi, b.hi);

	return out.lo <= out.hi;
}

static bool check() {
	int nVisitors = 0;
	int temp = 0;
	std::cin >> nVisitors >> temp;

	bool possible = true;
	Person availablePerson = {0, temp, temp};
	for (int i = 0; i < nVisitors; ++i) {
		Person person;
		std::cin >> person.time >> person.tempRange.lo >> person.tempRange.hi;

		if (possible) {
			const int diffTime = person.time - availablePerson.time;
			availablePerson.time = person.time;
			availablePerson.tempRange.lo -= diffTime;
			availablePerson.tempRange.hi += diffTime;

			possible = intersectionRanges(availablePerson.tempRange, person.tempRange, availablePerson.tempRange);
		}
	}

	return possible;
}

int main() {
	int nTests = 0;
	std::cin >> nTests;

	for (int i = 0; i < nTests; ++i) {
		const bool status = check();
		std::cout << (status ? "YES" : "NO") << std::endl;
	}
}
