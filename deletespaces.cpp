/*ƒан текстовый файл. ѕереписать содержимое исходного файла в другой текстовый файл, 
предварительно преобразовав строки согласно заданному правилу. –аспечатать исходный и новый файлы.

¬ каждой строке помен€ть местами слова наибольшей и наименьшей длины. 
≈сли в строке несколько слов наибольшей или наименьшей длины, то вз€ть первые.*/
#include <iostream>

int main() {
	FILE* f;
	f = fopen("Base_text.txt", "r");
	if (f == 0) {
		return 1;
	}
	//len of the input string
	int count = 0;
	while (!feof(f)) {
		count++;
	}
	char* str_in = new char[count];
	fgets(str_in, count, f);

	//Find max lenght word in str
	int word_size = 0;
	int* semi = new int;
	for (int i = 0; i < count; i++) {
		semi = 0;
		if ((str_in[i] >= 97 && str_in[i] <= 122) || (str_in[i] >= 65 && str_in[i] <= 90)) {
			semi++;
		}
		else {
			if (semi != 0) {
				if (*semi > word_size) {
					word_size = *semi;
					semi = 0;
				}
			}
		}
	}

	char* word_left = new char[word_size];
	char* word_right = new char[word_size];
	char* str_out = new char[count];

	int n = 0;
		for (int z = 0, j = 0; j < count; j++) {
			str_out[n] = str_in[j];
			if ((str_in[j] >= 97 && str_in[j] <= 122) || (str_in[j] >= 65 && str_in[j] <= 90)) {
				word_right[z] = str_in[j];
				z++;
			}
			else if((str_in[j+1] >= 97 && str_in[j+1] <= 122) || (str_in[j+1] >= 65 && str_in[j+1] <= 90)) {
				word_right[strlen(word_right)] = '\0';
				if (strlen(word_right) > 1) {
					if (word_left[0] == ' ') {
						for (int k = 0; k < word_size; k++) {
							word_left[k] = word_right[k];
						}
					}
					else {
						if (strlen(word_left) > strlen(word_right)) {
							for (int i = 0; word_left[i] != '\0'; i++, ++n) {
								str_out[n] = word_left[i];
							}
						}
						else {
							for (int i = 0; word_right[i] != '\0'; i++, ++n) {
								str_out[n] = word_right[i];
							}
						}
					}
					for (int i = 0; word_left[i] != '\0'; i++) {
						word_left[i] = ' ';
					}
				}
			}
			z = 0;
		}
		FILE* g;
		g = fopen("Processed_text.txt", "w");
		fputs(str_out, g);
		
		delete[] word_left;
		word_left = NULL;
		delete[] word_right;
		word_right = NULL;
		delete[] str_in;
		str_in = NULL;
		delete[] str_out;
		str_out = NULL;
		delete semi;
		semi = NULL;


	system("pause");
	return 0;
}