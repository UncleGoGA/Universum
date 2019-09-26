#include <iostream>

using namespace std;

int fact(int a) {
	if (a < 0) {
		return 0;
	}
	if (a == 0) {
		return 1;
	}
	else
	{
		return a * fact(a - 1);
	}
}

int main(){
	setlocale(LC_ALL, "Russian");

	int iN;
	cin >> iN;
	int iM, iK = 0;
	
	if (iN < 10) {
		iM = fact(iN);
		cout << iM;
	}
	else {
		cin >> iK;
		iM = pow(iN, iK);
		cout << iM;
	}
	system("pause");
	return 0;
}