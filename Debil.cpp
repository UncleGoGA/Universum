// Debil.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;

	int *mas = new int[size];

	int choice;
	cout << "Please choose how to fill massive" << endl;
	cout << "1. Random" << endl;
	cout << "2. From Keyboard" << endl;
	switch (choice) {
	case 1:
		for (int a = 0; a < size; a++) {
			mas[a] = rand() % 100 + 1;
		}
		break;
	case 2:
		for (int a = 0; a < size; a++) {
			cin >> mas[a];
		}
		break;
	}

	for (int a = 0; a < size - 1; a++) {
		for (int b = 0; b < size - 1 - a; b++) {
			if (mas[b] > mas[b + 1]) {
				int temp = mas[b];
				mas[b] = mas[b + 1];
				mas[b + 1] = temp;
			}
		}
	}

	cout << "Max element - " << mas[size] << endl;
	cout << "2nd Max element - " << mas[size - 1] << endl;

	system("pause");
    return 0;
}

