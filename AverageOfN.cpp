// masAverageOfN.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*int FuncAvg(int a, int b) {
	return (a + b) / 2;
}*/

/*void fMaxEq(int *a[], int size, int maxsize) {
	for (int i = 0; i < size; i++) {
		if (*a[i] >= maxsize) {
			maxsize = *a[i];
		}
	}
}
*/

/*void fMinEq(int *a[], int size, int minsize) {
	for (int i = 0; i < size; i++) {
		if (*a[i] <= minsize) {
			minsize = *a[i];
		}
	}
}
*/
int main()
{
	int iSize;

	cin >> iSize;

	int *masAverage = new int [iSize];

	int iAvg;

	for (int i = 0; i < iSize; i++) {
		cin >> masAverage[i];
	}

	int temp;

	for (int i = 0; i < iSize - 1; i++) {
		for (int j = 0; j < iSize - 1 - i; j++) {
			if (masAverage[j] > masAverage[j + 1]) {
				temp = masAverage[j];
				masAverage[j] = masAverage[j + 1];
				masAverage[j + 1] = temp;
			}
		}
	}

	int iMinEq = masAverage[0];

	int x = iSize;

	while (x != 3) {

	}

	for (int i = 0; i < iSize; i++) {
		/*iMinEq = (iMinEq < masAverage[i] ? iMinEq == masAverage[i] : );*/
		//Поиск минимального элемента
		if (masAverage[i] <= iMinEq) {
			iMinEq = masAverage[i];
		}
	}




	int iMaxEq = masAverage[0];

	//fMaxEq(masAverage[iSize], iSize, iMaxEq);


	/*for (int i = 0; i < iSize; i++) {
		//Поиск максимального элемента
		if (masAverage[i] >= iMaxEq) {
			iMaxEq = masAverage[i];
		}
	}
	*/

	/*iAvg = FuncAvg(iMaxEq, iMinEq);

	//for (int i = 0; i < iSize; i++) {
	//	//Сравнение значения функции со значениями масссива
	//	if (iAvg > i && iAvg < i + 1 ) {
	//		cout << iAvg;
	//	}
	//}

	for (int i = 0; i < iSize; i++) {
		if (iAvg == masAverage[i]) {
			cout << iAvg;
		}
		else if (iAvg - 1 == masAverage[i]) {
			cout << iAvg - 1;
		}
		else if (iAvg + 1 == masAverage[i]) {
			cout << iAvg + 1;
		}
	}
	*/
	system("pause");
    return 0;
}

