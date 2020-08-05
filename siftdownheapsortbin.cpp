#include <iostream>
#include <vector>

template<typename T>
void siftDown(T* numbers, int root, int bottom)
{
    int maxChild; // ������ ������������� �������
    int done = 0; // ���� ����, ��� ���� ������������
    // ���� �� ����� �� ���������� ����
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // ���� �� � ��������� ����,
            maxChild = root * 2;    // ���������� ����� �������
          // ����� ���������� ������� ������� �� ����
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // ���� ������� ������� ������ ������������� �������
        if (numbers[root] < numbers[maxChild])
        {
            T temp = numbers[root]; // ������ �� �������
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // �����
            done = 1; // �������� ������������
    }
}

template<typename T>
void heapSort(T* numbers, int array_size)
{

    for (int i = (array_size / 2) - 1; i >= 0; i--)
        siftDown(numbers, i, array_size - 1);

    for (int i = array_size - 1; i >= 1; i--)
    {
        T temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

template<typename T>
bool binsearch(T* arr, int m, T value) {
    int low = 0;
    int mid;
    int high = m;
    while (low <= high) {
        mid = (low + high) / 2;
        if (value < arr[mid]) {
            high = mid - 1;
        }
        else if (value > arr[mid]) {
            low = mid + 1;
        }
        else {
            return true;
        }
    }
    return false;
}

template <class T>
bool fi(T* a, int m, T* b, int n) {

    heapSort(b, n);

    int count = 0;

    for (size_t i = 0; i < m; i++) {
        if (binsearch(b, n, a[i]) == true) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> av = { 4, 3, 1 }; //false, if you need true - delete '1'
    std::vector<int> bv = { 7, 1, 2, 5 };
    int* a = new int[av.size()];
    int* b = new int[bv.size()];

    for (size_t i = 0; i < av.size(); i++) {
        a[i] = av[i];
    }

    for (size_t i = 0; i < bv.size(); i++) {
        b[i] = bv[i];
    }
    std::cout << "The resuilt is - ";
    std::cout << fi(a, av.size(), b, bv.size());
}