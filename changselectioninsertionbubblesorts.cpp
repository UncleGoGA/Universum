#include <iostream>

struct matrix {
	size_t rows;
	size_t cols;
	size_t** array;
	size_t** current_array;

	matrix() noexcept{
		rows = 0;
		cols = 0;
		array = nullptr;
		current_array = nullptr;
	}

	~matrix(){
		delete[] array;
		delete[] current_array;
	}

	//i know that i need to use getters and setters but later
	//and perhaps i need to use two structures: 1. for data(with getters and setters); 2. for methods(now its our friend functions)
	//now i have idea: I need to use "protected", because friend functions can do smthng with data, but outside class/struct noone can do anything with it
	friend void print(matrix& matrix);
	friend void change_sort(matrix& matrix);
	friend void selection_sort(matrix& matrix);
	friend void bubble_sort(matrix& matrix);
	friend void insertion_sort(matrix& matrix);
	friend void arrcpy(matrix& matrix);
	friend void resetarr(matrix& matrix);
	friend void swap(matrix& matrix, size_t start, size_t en, size_t ed);
};

void change_sort(matrix &matrix) {
	/*not realised yet
	*/
}

void selection_sort(matrix &matrix) {
	size_t max1, max2, buff;
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			max1 = i;
			max2 = j;
			for (size_t k = i; k < matrix.rows; k++) {
				if (k == i) {
					for (size_t l = j; l < matrix.cols; l++) {
						if (matrix.array[k][l] > matrix.array[max1][max2]) {
							max1 = k;
							max2 = l;
						}
					}
				}
				else {
					for (size_t l = 0; l < matrix.cols; l++) {
						if (matrix.array[k][l] > matrix.array[max1][max2]) {
							max1 = k;
							max2 = l;
						}
					}
				}
			}
			buff = matrix.array[max1][max2];//because swap didnt work with different 'i'
			matrix.array[max1][max2] = matrix.array[i][j];
			matrix.array[i][j] = buff;
		}
	}
	/*for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            max1 = i;
            max2 = j;
            for (int k = i; k < row; k++) {
                if (k == i) {   // need to improve this part
                    for (int l = j; l < column; l++) {
                        if (x[k][l] > x[max1][max2]) {
                            max1 = k;
                            max2 = l;
                        }
                    }
                } else {
                    for (int l = 0; l < column; l++) {
                        if (x[k][l] > x[max1][max2]) {
                            max1 = k;
                            max2 = l;
                        }
                    }
                }
            }
            s = x[max1][max2];
            x[max1][max2] = x[i][j];
            x[i][j] = s;
        }
    }
  */
}

void swap(matrix &matrix, size_t start, size_t en, size_t ed) {//bad swap, need to recreate it or overload
	size_t buff = matrix.array[start][en];
	matrix.array[start][en] = matrix.array[start][ed];
	matrix.array[start][ed] = buff;
}

void insertion_sort(matrix &matrix) {
	size_t buff = 0;
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			for (size_t inside_i = i; inside_i < matrix.rows; inside_i++) {
				for (size_t inside_j = j; inside_j < matrix.cols; inside_j++) {
					if (matrix.array[i][j] > matrix.array[inside_i][inside_j]) {
						buff = matrix.array[i][j];
						matrix.array[i][j] = matrix.array[inside_i][inside_j];
						matrix.array[inside_i][inside_j] = buff;
					}
				}
			}
		}
	}
	/*	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int inside_i = i; inside_i < rows; inside_i++)
			{
				for (int inside_j = j; inside_j < cols; inside_j++)
				{
					if (A[i][j] > A[inside_i][inside_j])
					{
						swap(A[i][j], A[inside_i][inside_j]);
					}
				}
			}
		}
	}*/
}

void bubble_sort(matrix &matrix) {//not safe
	/*for(i=0;i<4;i++)
    for(j=0;j<3;j++)
        for(k=j+1;k<4;k++)
            if(x[i][j]>x[i][k])
            {
                int temp = x[i][j];
                x[i][j] = x[i][k];
                x[i][k] = temp;
            }     some instructions from ethernet, ye i know, that i need to know it by myself*/
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.rows - 1; j++) {
			for (size_t k = j + 1; k < matrix.cols; k++) {
				if (matrix.array[i][j] > matrix.array[i][k]) {
					swap(matrix, i, j, k);
				}
			}
		}
	}
}

void print(matrix &matrix) {
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			printf("%i ", matrix.array[i][j]);
		}
		printf("\n");
	}
}

void create_mas(matrix &matrix) {

	matrix.array = new size_t*[matrix.rows];
	for (size_t i = 0; i < matrix.rows; i++) {
		matrix.array[i] = new size_t[matrix.cols];
	}
	
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			matrix.array[i][j] = '\0';
		}
	}

	matrix.current_array = new size_t * [matrix.rows];
	for (size_t i = 0; i < matrix.rows; i++) {
		matrix.current_array[i] = new size_t[matrix.cols];
	}

	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			matrix.current_array[i][j] = '\0';
		}
	}
}

void arrcpy(matrix &matrix) {
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			matrix.current_array[i][j] = matrix.array[i][j];
		}
	}
}

void resetarr(matrix& matrix) {
	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			matrix.array[i][j] = matrix.current_array[i][j];
		}
	}
}

void enter_arr(matrix &matrix) {
	printf("Now enter the array\n");

	for (size_t i = 0; i < matrix.rows; i++) {
		for (size_t j = 0; j < matrix.cols; j++) {
			scanf_s("%u", &matrix.array[i][j]);
		}
	}
}

void main() {
	unsigned short changer = 0;
	matrix matrix;

	printf("Enter rows\n");
	scanf_s("%i", &matrix.rows);
	printf("Enter cols\n");
	scanf_s("%i", &matrix.cols);

	create_mas(matrix);
	enter_arr(matrix);
	arrcpy(matrix);

	while(true){
		printf("Select the following one:\n1. Change sort\n2. Selection sort\n3. Insertion sort\n4. Bubble sort\n5. Reset array\n6. Show array\n7. Exit\n");
		scanf_s("%hu", &changer);

		switch (changer){
		case 1:
			change_sort(matrix);
			break;
		case 2:
			selection_sort(matrix);
			break;
		case 3:
			insertion_sort(matrix);
			break;
		case 4:
			bubble_sort(matrix);
		case 5:
			resetarr(matrix);
			break;
		case 6:
			print(matrix);
			break;
		case 7:
			exit(0);
		default:
			printf("\nInvalid params, try again\n");
			break;
		}
	}
}