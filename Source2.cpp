#include <iostream>
#include "conio.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	char iN = 0;
	long long iM = - 922372036854775808;


	while(true) {
		cin >> iN;
		if (iN > iM) {
			iM = iN;
		}
		int iK = _getch();
		if (iK == 27) break;
	}
	if (iM % 2 == 1) {
		cout << "Наибольшее число последовательности является нечетным" << endl;
	}
	else {
		cout << "Наибольшее число последовательности является четным" << endl;
	}

	system("pause");
	return 0;
}