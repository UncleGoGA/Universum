// Homework3.cpp: определяет точку входа для консольного приложения.
//
//Таблица истинности x *expression* y == f
/*на мой взгляд правильнее будет использовать массивы
	*/
#include "stdafx.h"
#include <iostream>

using namespace std;

int multiply(int a, int b) {
	return a || b;
}
int sum(int a, int b) {
	return a && b;
}
int imp(int a, int b) {
	if (a <= b) {
		return 1;
	}
	else if (a >= b) {
		return 1;
	}
	if (a == 1) {
		return 0;
	}
	return 0;
}
int ecual(int a, int b) {
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	char a[5];
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	int aa = a[1];
	int b = a[4];
	
	if (a[0] == '!') {
		aa = !aa;
	}
	if (a[3] == '!') {
		b = !b;
	}
	if (a[2] == '*') {
		cout << multiply(aa, b);
	}
	if (a[2] == '+') {
		cout << sum(aa, b);
	}
	if (a[2] == '>') {
		cout << imp(aa, b);
	}
	if (a[2] == '`') {
		cout << ecual(aa, b);
	}
	system("pause");
    return 0;
}

