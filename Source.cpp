#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int N;
	cin >> N;
	int m = 0;

	while(N) {
		m += N % 10;
		N = N / 10;
		if (N == 0) break;
		m = m * 10;
		
	}

	cout << m << endl;
	system("pause");
	return 0;
}