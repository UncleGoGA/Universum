/*�������� ��������, ������� ���� �������� � ������� ��������� ������� : ���� ��� ����� ������ n, ��
������������ �������� �����, ����� � ���������� ������������ �������, � ����� � ���������������� �����.
����������������� ����� ���������� ����������� �������� n ��� ������ 1000 ��������� ����� double, int �
����� ����� 8.
*/

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <string.h>
#include <cmath>

#pragma warning(disable:4996)

size_t VECTOR_LEN = 1;

FILE* outfile;

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

    char* word = new char[9];
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
    int size = 0;

    while (fscanf(dile, "%d", &value) != EOF) {
        vec.push_back(value);
        std::cout << value << std::endl;
    }


    fclose(dile);
    return vec;
}

std::vector<double> file_to_vector_double(char* argv[]) {
    std::vector<double> vector;

    char* word = new char[9];
    FILE* dile;
    dile = fopen(argv[1], "r");
    for (size_t i = 0; !feof(dile); i++) {
        fread(word, 1, 8, dile);
        vector.push_back(atoi(word));
    }

    fclose(dile);
    return vector;
}

template<typename T>
T** create_pointed_array(std::vector<T>& vector) {
    T** p_array = new T* [vector.size()];
    for (size_t i = 0; i < vector.size(); i++) {
        p_array[i] = &(vector[i]);
    }
    return p_array;
}

template<typename T>
T p_min(T** array, size_t left, size_t right) {
    T value;
    size_t index = 0;
    for (size_t i = left; i < right; ++i) {
        if (array[i] != nullptr) {
            value = *(array[i]);
            index = i;
            break;
        }
    }
    for (left; left < right; ++left) {
        if (array[left] != nullptr) {
            if (*(array[left]) < value) {
                value = *(array[left]);
                index = left;
            }
        }
    }
    array[index] = nullptr;
    return value;
}

template<typename T>
T min(std::vector<T> min_vector) {
    T min_value = min_vector[0];
    for (size_t i = 0; i < min_vector.size(); i++) {
        if (min_vector[i] < min_value) {
            min_value = min_vector[i];
        }
    }

    return min_value;
}

template<typename T>
bool search_nullptr(T** array, size_t left, size_t right) {
    for (left; left < right; ++left) {
        if (array[left] != nullptr) {
            return 0;
        }
    }
    return 1;
}

template<typename T>
void create_min(T** array, std::vector<size_t>diapos, std::vector<T>& minimal_in_diapos, bool& flag/*false by default*/){
    minimal_in_diapos.clear();
    T value;
    for (size_t i = 0, j = 1; j < diapos.size(); i += 2, j += 2) {
        if (search_nullptr(array, diapos[i], diapos[j]) == 1) {
            if (search_nullptr(array, diapos[(diapos.size() - 2)], diapos[(diapos.size() - 1)]) == 1) {
            flag = true;
            break;
            }
            else {
                value = p_min(array, diapos[(diapos.size() - 2)], diapos[(diapos.size() - 1)]);
                minimal_in_diapos.push_back(value);
            }
        }
        else {
            value = p_min(array, diapos[i], diapos[j]);
            minimal_in_diapos.push_back(value);
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

template<typename T>
std::vector<T> sort_by_degree(std::vector<T>& vector) { //--in progress
    double p = sqrt(vector.size());
    size_t check;
    double q = vector.size() / p;
    check = q;
    size_t last_len = 0;
    size_t vector_len = 0;
    std::vector<size_t> diapos;
    if (check != q) {
        last_len = vector.size() - pow(check, 2);
        vector_len = vector.size() - last_len;
        //last_len = vector.size() - (q - 1) * p; not working
    }
    if (last_len != 0) {
        p = sqrt(vector.size() - last_len);
        q = (vector.size() - last_len) / p;
        diapos.push_back(0);
        for (size_t i = 1, counter = 0; i <= vector_len; i++) {
            counter++;
            if (counter % check == 0) {
                diapos.push_back(i);
                diapos.push_back(i + 1);
                counter = 0;
            }
        }
        diapos.push_back(vector.size());
    }
    else
    {
        diapos.push_back(0);
        for (size_t i = 1, counter = 0; i <= vector_len; i++) {
            counter++;
            if (counter % check == 0) {
                diapos.push_back(i);
                diapos.push_back(i + 1);
                counter = 0;
            }
        }
    }
    
    std::vector<T> copy;
    std::vector<T> min_vector;
    T value;
    bool flag = false;
    T** array = create_pointed_array(vector);
    for (size_t i = 0, j = 1; j < diapos.size(); i += 2, j += 2) {
        create_min(array, diapos, min_vector, flag);
        if (flag == true) {
            break;
        }
        value = min(min_vector);
        copy.push_back(value);

        //pointed vector
    }
    delete[] array;

    return copy;
}

template<typename T>
int find(std::vector<T> vector, std::vector<T> value) { //la costil
    int answ = 0;
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector[i] == value[VECTOR_LEN - 1]) {
            answ = i;
        }
    }
    return answ;
}

template<typename T>
bool interpool(std::vector<T> vector, std::vector<T> value) {
    int value_int = find(vector, value);
    std::vector<int> vector_int;
    for (size_t i = 0; i < vector.size(); i++) {
        vector_int.push_back(i);
    }
    size_t left = 0;
    size_t right = vector.size() - 1;
    if (vector.size() == 0) {
        return 0;
    }
    size_t pos = 0;
    bool found;
    /*for (found = false; (vector_int[left] < value_int) && (vector_int[right] > value_int) && !found;)*/ 
    while((vector_int[left] < value_int)&&(vector_int[right] > value_int)){
        pos = left + ((value_int - vector_int[left]) * (right - left)) / (vector_int[right] - vector_int[left]); //maybe used linked_list
        if (vector_int[pos] < value_int) {
            left = pos + 1;
        }
        else if(vector_int[pos] > value_int)
        {
            right = pos - 1;
        }
        else {
            return pos;
        }
    }
    return false;
}

template<typename T>
bool linear_find(std::vector<T>vector, std::vector<T> value) {//--currently worked
    size_t size = vector.size();
    for (size_t i = 0; i < size; i++) {
        if (vector[i] == value[VECTOR_LEN - 1]) {
            return true;
        }
    }
    return false;
}

void info(bool flag ,std::vector<double> elapsed_times) {
    //linear - false
    //fibonacci - true
    double average = 0;
    for (size_t i = 0; i < static_cast<size_t>(elapsed_times.size()); i++) {
        average += elapsed_times[i];
    }
    average /= elapsed_times.size();
    if (flag == true) {
       fprintf(outfile, "linear time - %lf\n", average);
    }
    else {
       fprintf(outfile, "inter time - %lf\n", average);
    }
}

void aprox(double t1/*linear*/, double t2/*interpool*/) {
    if ((t1 - t2) < 0) {
        fprintf(outfile, "linear faster than inter - %lf\n", (t1 - t2));
    }
    else if ((t1 - t2) > 0) {
        fprintf(outfile, "inter faster than linear - %lf\n", (t1 - t2));
    }
    else {
        fprintf(outfile, "linear and inter are equals for time");
    }
}

void alg(char* argv[]) {
    std::vector<double> avg;
    if (strcmp(argv[2], "char") == 0) {
        double t1, t2;
        std::vector<double> elapsed_times;
        std::vector<std::string> string = file_to_string(argv);
        std::vector<std::string> copy;
        std::vector<std::string> value = file_to_string(argv);
        double elapsed_seconds;
        bool flag = false;
        copy = string;
        auto start = std::chrono::steady_clock::now();
        while (VECTOR_LEN < 1001) {
           
            linear_find<std::string>(copy,value);
            VECTOR_LEN++;
        }
        auto end = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t1 = avg[0];
        info(true, avg);
        avg.clear();
        elapsed_times.clear();
        VECTOR_LEN = 1;
        copy = string;
        start = std::chrono::steady_clock::now();
        copy = sort_by_degree<std::string>(copy);
        while (VECTOR_LEN < 1001) {
       
         
            interpool<std::string>(copy, value);
            VECTOR_LEN++;
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
        std::vector<double> elapsed_times;
        double t1, t2;
        std::vector<double> vector = file_to_vector_double(argv);
        std::vector<double> copy;
        std::vector<double> value = file_to_vector_double(argv);
        double elapsed_seconds;
        copy = vector;
        auto start = std::chrono::steady_clock::now();
        while (VECTOR_LEN < 1001) {
           
            linear_find<double>(copy, value);
        }
        auto end = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration<double>(end - start).count();
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t1 = avg[0];
        info(true, avg);
        avg.clear();
        elapsed_times.clear();
        VECTOR_LEN = 1;
        copy = vector;
        start = std::chrono::steady_clock::now();
        
        copy = sort_by_degree<double>(copy);
        while (VECTOR_LEN < 1001){

           interpool<double>(copy, value);
           VECTOR_LEN++;
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
        double t1, t2;
        std::vector<double> elapsed_times;
        std::vector<int> vector = file_to_vector_int(argv);
        std::vector<int> copy;
        std::vector<int> value = file_to_vector_int(argv);;
        double elapsed_seconds;
        copy = vector;
        auto start = std::chrono::steady_clock::now();
       
        while (VECTOR_LEN < 1001) {
    
            linear_find<int>(copy, value);
            VECTOR_LEN++;
        }
        auto end = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration<double>(end - start).count();
        std::cout << VECTOR_LEN << ' ' << elapsed_seconds << std::endl;
        elapsed_times.push_back(elapsed_seconds);
        create_avg(elapsed_times, avg);
        t1 = avg[0];
        info(true, avg);
        avg.clear();
        elapsed_times.clear();
        VECTOR_LEN = 1;
        copy = vector;
        start = std::chrono::steady_clock::now();
  
        copy = sort_by_degree<int>(copy);
        while(VECTOR_LEN < 1001){

            interpool<int>(copy, value);  
            VECTOR_LEN++;
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
    //0 - prog name
    //1 - file name
    //2 - type value
    // try to start with - test_int.txt int
    if (argc != 3) {
        std::cout << "Cant recognize command" << std::endl;
        exit(0);
    }
    is_opened_file(argv);

    outfile = fopen("Elapsed_times.txt", "w");

    alg(argv);

    fclose(outfile);
    return 0;
}