// Def.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int Sum(int a, int b) {
	return a + b;
}
int DeSum(int a, int b) {
	return a - b;
}
int Multiply(int a, int b) {
	return a * b;
}
int DeMultiply(int a, int b) {
	return a / b;
}
int main()
{
	int c;
	int a, b;
	cout << "Sum - 1; DeSum - 2; Multiply - 3; DeMultiply - 4" << endl;
	switch (c) {
	case 1:
		cout << "Enter 1st number" << endl;
		cin >> a;
		cout << "Enter 2nd number" << endl;
		cin >> b;
		cout << Sum(a, b);
		break;
	case 2:
		cout << "Enter 1st number" << endl;
		cin >> a;
		cout << "Enter 2nd number" << endl;
		cin >> b;
		cout << DeSum(a, b);
	case 3:
		cout << "Enter 1st number" << endl;
		cin >> a;
		cout << "Enter 2nd number" << endl;
		cin >> b;
		cout << Multiply(a, b);
	case 4:
		cout << "Enter 1st number" << endl;
		cin >> a;
		cout << "Enter 2nd number" << endl;
		cin >> b;
		cout << DeMultiply(a, b);
	default:
		cout << "Restricted area, get out of here" << endl;
	}
	system("pause");
    return 0;
}

