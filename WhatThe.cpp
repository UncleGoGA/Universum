// WhatThe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int srav(int a, int b, int c) {
	if (b > a && b < c) {
		return b;
	}
	else if (b > c && b < a) {
		return b;
	}
	if (a > b && a < c) {
		return a;
	}
	else if (a > c && a < b) {
		return a;
	}
	if (c > b && c < a) {
		return c;
	}
	else if (c > a && c < b) {
		return c;
	}
	return 0;
}

int main()
{
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	cout << srav(a, b, c) << endl;
	system("pause");
    return 0;
}

