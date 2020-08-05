#include <iostream>
#include <vector>
#include <string.h>
#include <chrono>

#pragma warning(disable:4996)

/*func that create tests*/

//const size_t CHAR_SIZE = 16; //String len
const size_t COUNT_INTER = 1001;
size_t VECTOR_LEN = 1;

FILE* outfile;

#ifdef DEBUG
void test() {
    FILE* test_int;
    test_int = fopen("Test_int.txt", "a");
    FILE* test_double;
    test_double = fopen("Test_double.txt", "a");
    FILE* test_char;
    test_char = fopen("Test_char", "a");

    fputs();
}

#endif // DEBUG

void is_opened_file(char* argv[]) {//checking that file is exist
    FILE* f;
    f = fopen(argv[1], "rt");
    if (!f) {
        printf("There are no such file");
        exit(0);
    }
    fclose(f);
}

std::vector<std::string> file_to_string(char* argv[])
{
    //includes argv[], transmitted file to string

    std::vector<std::string> true_string;

    char* word = new char[17];
    FILE* dile;
    dile = fopen(argv[1], "r");
    for (size_t i = 0; !feof(dile); i++) {
        fread(word, 1, 8, dile);
        true_string.push_back(word);
    }

    fclose(dile);
    return true_string;

}

std::vector<int> file_to_vector_int(char* argv[]) {
    std::vector<int> vec;
    FILE* dile;
    int value = 0;
    dile = fopen(argv[1], "r");

    while (fscanf(dile, "%d", &value) != EOF) {
        vec.push_back(value);
    }


    fclose(dile);
    return vec;
}

std::vector<double> file_to_vector_double(char* argv[]) {
    std::vector<double> vector;

    double value = 0;
    FILE* dile;
    dile = fopen(argv[1], "r");
    while (fscanf(dile, "%f", &value) != EOF) {
        vector.push_back(value);
    }

    fclose(dile);
    return vector;
}

template<typename T>
std::vector<T> comb(std::vector<T> sort) { // sort � �������� �������  (������� �� ������, ����� ����� comb(vect) ����� ������ vect)
    int n = 0; // ���������� ������������
    double fakt = 1 / 1.3; // ������ ����������
    double step = sort.size() - 1;

    if (step == 1) {
        for (int i = 0; i < sort.size() - 1; ++i)
        {
            bool swapped = false;
            for (int j = 0; j < sort.size() - i - 1; ++j)
            {
                if (sort[j] > sort[j + 1])
                {
                    std::swap(sort[j], sort[j + 1]);
                    swapped = true;
                    ++n;
                }
            }
            if (!swapped)
                break;
        }
        return sort;
    }

    while (step > 1) {
        for (int i = 0; i + step < sort.size(); ++i) {
            if (sort[i] > sort[i + step]) {
                std::swap(sort[i], sort[i + step]);
                ++n;
            }
        }
        step *= fakt;
    }
    return sort;
}

template<typename T>
bool linear_find(std::vector<T>vector,std::vector<T> vector_value) {//--currently worked
    T value = vector_value[VECTOR_LEN - 1];
    size_t size = vector.size();
    for (size_t i = 0; i < size; i++) {
        if (vector[i] == value) {
            return true;
        }
    }
    return false;
}

std::uint64_t fibonacci(std::uint64_t number)//--currently worked
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return fibonacci(number - 1) + fibonacci(number - 2);
}

template<typename T>
size_t mid_fib(std::vector<T> vector, size_t& counter/*always start by zero*/) {
    size_t semi = (vector.size() / 2);
    size_t res = 0;
    while (res < semi) {
        res = fibonacci(counter);
        ++counter;
    }
    return res;
}

int min(int x, int y) { return (x <= y) ? x : y; }

template<typename T>
bool fibonacci_find(std::vector<T> vector, std::vector<T> vector_value) {
    T value = vector_value[VECTOR_LEN - 1];
    size_t counter = 0;
    /*size_t middle = mid_fib(vector, counter);
    size_t left_counter = counter - 1;
    size_t right_counter = counter - 2;*/
    int left_counter = 0;
    int right_counter = 1;
    int middle = left_counter + right_counter;
    int offset = -1;
    while (middle < vector.size()) {
        left_counter = right_counter;
        right_counter = middle;
        middle = left_counter + right_counter;
    }
    while (middle > 1) {
        int i = min(offset + left_counter, vector.size() - 1);
        if (vector[i] < value) {
            middle = right_counter;
            right_counter = left_counter;
            left_counter = middle - right_counter;
            offset = i;
        }
        else if (vector[i] > value) {
            middle = left_counter;
            right_counter -= left_counter;
            left_counter = middle - right_counter;
        }
        else return i;
    }
    if (right_counter && vector[offset + 1] == value) {
        return offset + 1;
    }
    return -1;
}

std::uint64_t find_n(std::vector<double>avg) {
    for (size_t i = 0; i < static_cast<size_t>(avg.size()) - 1; i++) {
        if (avg[i + 1] * 0.5 > avg[i]) {
            return i;
        }
    }
}

void create_avg(std::vector<double> elapsed_time, std::vector<double>& avg) {
    long double average = 0;
    for (size_t i = 0; i < static_cast<size_t>(elapsed_time.size()); i++) {
        average += elapsed_time[i];
    }
    average /= elapsed_time.size();
    avg.push_back(average);
}

void info(bool flag, std::vector<double> elapsed_times) {
    //linear - true
    //fibonacci - false
    double average = 0;
    for (size_t i = 0; i < static_cast<size_t>(elapsed_times.size()); i++) {
        average += elapsed_times[i];
    }
    average /= elapsed_times.size();
    if (flag == true) {
        fprintf(outfile, "linear time - %lf\n", average);
    }
    else {
        fprintf(outfile, "fibo time - %lf\n", average);
    }
}

void aprox(double t1/*linear*/, double t2/*fibonacci*/) {
    if ((t1 - t2) < 0) {
        fprintf(outfile, "linear faster than fibonacci - %lf\n", (t1 - t2));
    }
    else if ((t1 - t2) > 0) {
        fprintf(outfile, "fibonacci faster than linear - %lf\n", (t1 - t2));
    }
    else {
        fprintf(outfile, "linear and fibonacci are equals for time");
    }
}

void alg(char* argv[]) {
    is_opened_file(argv);
    double t1, t2;
    std::vector<double> elapsed_times;
    std::vector<double> avg;
    if (strcmp(argv[2], "char") == 0) {
        /*std::string value = argv[2];*/
        std::vector<std::string> string = file_to_string(argv);
        std::vector<std::string> copy_string;
        std::vector<std::string> value = file_to_string(argv);
        copy_string = comb(string);
        auto start = std::chrono::steady_clock::now();
        for (VECTOR_LEN; VECTOR_LEN < COUNT_INTER; VECTOR_LEN++) {
            linear_find<std::string>(copy_string, value);
        }
        auto end = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t1 = avg[0];
        info(true, avg);
        elapsed_times.clear();
        avg.clear();
        copy_string.clear();
        VECTOR_LEN = 1;
        copy_string = comb(string);
        start = std::chrono::steady_clock::now();
        for (VECTOR_LEN; VECTOR_LEN < COUNT_INTER; VECTOR_LEN++) {
            fibonacci_find<std::string>(copy_string, value);
        }
        end = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t2 = avg[0];
        info(false, avg);
        aprox(t1, t2);
    }
    else if (strcmp(argv[2], "double") == 0) {
        std::vector<double> vector_double = file_to_vector_double(argv);
        std::vector<double> copy_vector_double;
        std::vector<double> value = file_to_vector_double(argv);
        copy_vector_double = comb(vector_double);
        auto start = std::chrono::steady_clock::now();
        for (VECTOR_LEN; VECTOR_LEN < COUNT_INTER; VECTOR_LEN++) {
            linear_find<double>(copy_vector_double, value);
        }
        auto end = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t1 = avg[0];
        info(true, avg);
        elapsed_times.clear();
        avg.clear();
        VECTOR_LEN = 1;
        copy_vector_double = comb(vector_double);
        start = std::chrono::steady_clock::now();
        for (VECTOR_LEN; VECTOR_LEN < COUNT_INTER; VECTOR_LEN++) {
            fibonacci_find<double>(copy_vector_double, value);
        }
        end = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t2 = avg[0];
        info(false, avg);
        aprox(t1, t2);
    }
    else if (strcmp(argv[2], "int") == 0) {
        std::vector<int> vector_int = file_to_vector_int(argv);;
        std::vector<int> copy_vector_int;
        std::vector<int> value = file_to_vector_int(argv);
        auto start = std::chrono::steady_clock::now();
        copy_vector_int = comb(vector_int);
        for (VECTOR_LEN; VECTOR_LEN < COUNT_INTER; VECTOR_LEN++) {
             linear_find<int>(copy_vector_int, value);
        }
        auto end = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t1 = avg[0];
        info(true, avg);
        elapsed_times.clear();
        avg.clear();
        VECTOR_LEN = 1;
        copy_vector_int = comb(vector_int);
        start = std::chrono::steady_clock::now();
        for (VECTOR_LEN; VECTOR_LEN < COUNT_INTER; VECTOR_LEN++) {
            fibonacci_find<int>(copy_vector_int, value);
        }
        end = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t2 = avg[0];
        info(false, avg);
        aprox(t1, t2);
    }
}

int main(int argc, char* argv[]) {
// 0 - program name
// 1 - file name --ifdef DEBUG use test.txt
// 2 - value --ifdef DEBUG i dont know what value can be find --not working
// 3 - info type 
// up above is context to understand which arguments need to be used

    if (argc != 3 || argc > 3) {
        std::cout << "Cant recognize response, use help" << std::endl;
        exit(0);
    }
    if (strcmp(argv[1], "help") == 0) {
        std::cout << "input values: progname filename value datatype(int || double || char)\nprogram also create file with elapsed time of sort\nuse --DEBUG in filename, if you dont have any tests: a.out --DEBUG (int || double || char) --in progress" << std::endl;
        exit(0);
    }
    outfile = fopen("Elapsed_times.txt", "w");
    alg(argv);
    fclose(outfile);
    return 0;
}
