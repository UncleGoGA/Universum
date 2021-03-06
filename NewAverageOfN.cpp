// NewAverageOfN.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

void pop_back(int *&mas, int &size) {
	size--;
	int *NewMas = new int[size];
	for (int i = 0; i < size; i++) {
		NewMas[i] = mas[i];
	}
	delete[]mas;
	mas = NewMas;
}

void pop_back_ag(int *&mas, int &size) {
	size--;
	int *NewMas = new int[size];
	for (int i = 0; i < size; i++) {
		NewMas[i + 1] = mas[i];
	}
	delete[]mas;
	mas = NewMas;
}

int main() {

	using namespace std;

	int Size;
	cin >> Size;
	int *masAverage = new int[Size];

	for (int i = 0; i < Size; i++) {
		cin >> masAverage[i];
	}

	for (int i = 0; i < Size - 1; i++) {
		for (int j = 0; j < Size - 1 - i; j++) {
			if (masAverage[j] > masAverage[j + 1]) {
				int temp = masAverage[j];
				masAverage[j] = masAverage[j + 1];
				masAverage[j + 1] = temp;
			}
		}
	}

	int x = Size;
	while (x != 1) {
		pop_back(masAverage, Size);
		pop_back_ag(masAverage, Size);
		Size = -2;
	}
	cout << masAverage;
	system("pause");
	return 0;
}

