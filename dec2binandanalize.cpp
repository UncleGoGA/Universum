/*E = 0; P = 10; A = 11*/

#include <iostream>

unsigned long long dec_2_bin(int number, unsigned long long& not_reverse_bin) {
	unsigned long long answ = 0;
	unsigned long long semi = 0;
	while (number > 0) {
		semi += number % 2;
		number /= 2;
		semi *= 10;
	}
	semi /= 10;

	not_reverse_bin = semi;

	while (semi > 0) {
		answ += semi % 10;
		semi /= 10;
		answ *= 10;
	}
	answ += 1;
	return answ;
}

char* process_unit(unsigned long long bin, unsigned long long not_reverse_bin, int& dec_res, int& size) {
	int count_of_char = 0;
	unsigned long long copy = not_reverse_bin;

	while (copy > 0) {
		if (copy % 100 == 11) {
			count_of_char++;
			copy /= 100;
		}
		else if (copy% 100 == 01) {
			count_of_char++;
			copy /= 100;
		}
		else {
			count_of_char++;
			copy /= 10;
		}
	}

	size = count_of_char;
	char* res = new char[count_of_char];
	int i = 0;

	while (not_reverse_bin > 0) {
		if (not_reverse_bin % 100 == 11) {
			res[i] = 'A';
			dec_res++;
			not_reverse_bin /= 100;
		}
		else if (not_reverse_bin % 100 == 01) {
			res[i] = 'P';
			not_reverse_bin /= 100;
		}
		else {
			res[i] = 'E';
			dec_res++;
			not_reverse_bin /= 10;
		}
	}

	return res;
}

int main() {
	unsigned long long not_reverse_bin;
	int number;
	int dec_res;
	int size;

	printf("Enter the number to proceed");
	scanf_s("%d", &number);

	unsigned long long reverse;

	reverse = dec_2_bin(number, not_reverse_bin);

	char* res = process_unit(reverse, not_reverse_bin, dec_res, size);

	for (int i = 0; i < size; i++) {
		printf("%c", res[i]);
	}

	printf("%d", dec_res);

	system("pause");
	return 0;
}