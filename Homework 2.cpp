// Homework 2.cpp: определяет точку входа для консольного приложения.
//
/*  1.Получаем числа в переменную + используем счетчик для подсчета символов и определения 2^n
	1.1 При нахождении 1 в двоичном коде, умножаем на показатель 2^n, при 0 пропускаем
    2. Используем деление с остатком, записываем остаток и продолжаем деление целой части при помощи double => int
*/

#include "stdafx.h"
#include <iostream>

void dec_to_bin(int x)
{
	if (x)
	{
		dec_to_bin(x >> 1);
		std::cout << (x & 1);
	}
}

int main()
{
	int c;
	std::cout << "1. Bin to Dec" << std::endl;
	std::cout << "2. Dec to Bin" << std::endl;
	switch (c) {
	case 1:
		const int n = 1024;
		int	sum = 0;
		char ch[n];
		std::cout << "Enter N" << std::endl;
		std::cin >> ch[n];
		for (int i = n - 1; i > -1; i--) {
			if (ch[i] == '1') {
				sum += pow(2, i);
			}
		}
		std::cout << "Dec = " << sum << std::endl;
		system("pause");
		break;
	case 2:
		int x;
		std::cout << "Enter X" << std::endl;
		std::cin >> x;
		std::cout << "Bin = ";
		dec_to_bin(x);
		std::cout << " Dec = " << x << std::endl;
		system("pause");
		break;
	}
	return 0;
}

