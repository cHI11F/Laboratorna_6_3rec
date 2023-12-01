#include <iostream>

template <typename T>
T findMaxRecursive(T* arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;
    T maxLeft = findMaxRecursive(arr, low, mid);
    T maxRight = findMaxRecursive(arr, mid + 1, high);

    return std::max(maxLeft, maxRight);
}

template <typename T>
void fillArray(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

template <typename T>
void printArray(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Invalid array size\n";
        return 1;
    }

    int* intArr = new int[size];
    fillArray(intArr, size);
    std::cout << "Array int: ";
    printArray(intArr, size);
    int maxIntElement = findMaxRecursive(intArr, 0, size - 1);
    std::cout << "Max element in array (recursive): " << maxIntElement << std::endl;
    delete[] intArr;

    double* doubleArr = new double[size];
    fillArray(doubleArr, size);
    std::cout << "Array double: ";
    printArray(doubleArr, size);
    double maxDoubleElement = findMaxRecursive(doubleArr, 0, size - 1);
    std::cout << "Max element in array (recursive): " << maxDoubleElement << std::endl;
    delete[] doubleArr;

    return 0;
}
