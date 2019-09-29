#include <iostream>
#include <ctime>
using namespace std;
int a, b, c, d, e;
int Random(int x) {
	srand(time(NULL));
	x = rand() % 9 + 1;
	return x;
}
int Random1(int x) {
	srand(time(NULL));
	x = rand() % 9;
	return x;
}
int Random2(int x) {
	srand(time(NULL));
	x = rand() % 9;
	return x;
}
int Random3(int x) {
	srand(time(NULL));
	x = rand() % 9;
	return x;
}
/*int RandRecurse(int x) {
	srand(time(NULL));
	x = rand() % 9;
	if (RandRecurse(x) != Random(x)) {
		return RandRecurse(x);
	}
	else {
		return x;
	}
}*/
int main() {
	setlocale(LC_ALL, "rus");
	start:
	cout << "1. Рандомные 4 числа\n2. Не повторяющиеся рандомные числа\n3. Совпадающие первое и последние числа\n " << endl;
	cin >> e;
	switch (e) {
	case 1:
		cout << Random(a);
		cout << Random1(b);
		cout << Random2(c);
		cout << Random3(d) << endl;
		break;

	case 2:
		cout << Random(a);
		nextstep1:
		Random1(b);
		if (b = a) {
			goto nextstep1;
		}
		else {
			cout << Random1(b);
		}
		ndstep1:
		Random2(c);
		if (c = a || b) {
			goto ndstep1;
		}
		else {
			cout << Random2(c);
		}
		rdstep1:
		Random3(d);
		if (d = a || b || c) {
			goto rdstep1;
		}
		else {
			cout << Random3(d) << endl;
		}
		break;

		case 3:
		cout << Random(a);
		nextstep2:
		Random1(b);
		if (b = a) {
			goto nextstep2;
		}
		else {
			cout << Random1(b);
		}
		ndstep2:
		Random2(c);
		if (c = a || b) {
			goto ndstep2;
		}
		else {
			cout << Random2(c);
		}
		d = Random(a);
		cout << d << endl;
		break;

	default:
		cout << "You have entered permission data, please go back and try later" << endl;
			goto start;
	}
	cout << "End of program" << endl;
	system("pause");
	return 0;
}