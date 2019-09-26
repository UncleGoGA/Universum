#include <iostream>
#include "pch.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	int m;

	while (N > 0) {
		m = N % 10;
		N = N / 10;
		m = m * 10;
	}

	cout << N << "   " << m << endl;
	return 0;
}