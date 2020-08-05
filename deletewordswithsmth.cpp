#include <iostream>
#include <string>

/*Написать функцию (8 баллов) void fi(char *str), которая в строке str уда-
ляет со сдвигом все слова, начинающиеся на букву а, б или в. Например, из строки

Группа␣автоморфизмов␣поля должно получиться Группа␣поля. Вычислить мак-
симальное время работы функции в зависимости от длины входных данных (2

балла). Для работы со строками запрещено использовать библиотечные функ-
ции.*/

void printm(char* str) {
	for (; *str; ++str) {
		std::cout << *str;
	}
}

void delete_a(char* str, size_t size) {
	//size_t size = 0;
	//for (; *str; ++str) { ++size; }
	char* new_str = new char[size];

	for (size_t i = 0, j = 0; i < size; ++i) {
		if (str[i] == 'а') {
			continue;
		}
		if (i > 0 && str[i] == ' ' && str[i - 1] == 'а') {
			++i;
		}
		if (j == 0 && str[i] == ' ') {
			continue;
		}
		new_str[j] = str[i];
		j++;
	}

	for (size_t i = 0; i < size; ++i) {
		str[i] = new_str[i];
	}
}

void delete_b(char* str, size_t size) {
	//size_t size = 0;
	//for (; *str; ++str) { ++size; }
	char* new_str = new char[size];

	for (size_t i = 0, j = 0; i < size; ++i) {
		if (str[i] == 'б') {
			continue;
		}
		if (i > 0 && str[i] == ' ' && str[i - 1] == 'б') {
			++i;
		}
		if (j == 0 && str[i] == ' ') {
			continue;
		}
		new_str[j] = str[i];
		j++;
	}

	for (size_t i = 0; i < size; ++i) {
		str[i] = new_str[i];
	}
}

void delete_v(char* str, size_t size) {
	//size_t size = 0;
	//for (; *str; ++str) { ++size; }
	char* new_str = new char[size];

	for (size_t i = 0, j = 0; i < size; ++i) {
		if (str[i] == 'в') {
			continue;
		}
		if (i > 0 && str[i] == ' ' && str[i - 1] == 'в') {
			++i;
		}
		if (j == 0 && str[i] == ' ') {
			continue;
		}
		new_str[j] = str[i];
		j++;
	}

	for (size_t i = 0; i < size; ++i) {
		str[i] = new_str[i];
	}
}

void fi(char* str) {
	size_t size = 0;
	char* copy = str;
	for (; *copy; ++copy) {
		size++;
	}
	/*size_t new_size = 0;
	char* new_str = new char[size];
	new_str[0] = '0';
	for (size_t i = 0, j = 0; i < size; ++i, ++j) {
		if (i == 0) {
			if (str[i] == 'а') {
				for (; str[i] != ' ' && str[i] != '\0'; ++i) {}
				++i;
			}
			if (str[i] == 'б') {
				for (; str[i] != ' ' && str[i] != '\0'; ++i) {}
				++i;
			}
			if (str[i] == 'в') {
				for (; str[i] != ' ' && str[i] != '\0'; ++i) {}
				++i;
			}
		}
		if (str[i - 1] == ' ') {
			if (str[i] == 'а') {
				for (; str[i] != ' ' && str[i] != '\0'; i++) {}
				i++;
			}
			if (str[i] == 'б') {
				for (; str[i] != ' ' && str[i] != '\0'; i++) {}
				i++;
			}
			if (str[i] == 'в') {
				for (; str[i] != ' ' && str[i] != '\0'; i++) {}
				i++;
			}
		}
		for (;str[i] != ' ';i++, ++j) {
			new_str[j] = str[i];
			new_size = j;
		}
		
	}

	for (size_t i = 0; i < size; i++) {
		str[i] = new_str[i];
	}*/

	delete_a(str, size);
	delete_b(str, size);
	delete_v(str, size);

}

int main() {
	std::string string = "ааа ббб ввв аааа бббббб ввввв ббббб ааааа м";
	char* str = new char[string.size()];
	for (size_t i = 0; i < string.size(); ++i) {
		str[i] = string[i];
	}

	printm(str);

	fi(str);

	printm(str);


	return 0;
}