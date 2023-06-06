#include "Array.h"


Array::Array() : data(nullptr), size(0) {}

Array::Array(int size) : size(size) {
    data = new double[size];
}

Array::Array(const Array& other) : size(other.size) {
    data = new double[size];
    std::copy(other.data, other.data + size, data);
}

Array::~Array() {
    delete[] data;
}

void Array::setArraySize(int newSize){
    if (newSize < 0) {
        throw std::invalid_argument("Array size cannot be negative");
    }
    size = newSize;
    data = new double[size];
}

void Array::fillArray() {
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i <<"] "<<"= ";
        std::cin >> data[i];
    }
}

void Array::displayArray() const {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void Array::resizeArray(int newSize) {
    if (newSize < 0) {
        throw std::invalid_argument("Array size cannot be negative");
    }
    double* newArray = new double[newSize];
    int elementsToCopy = std::min(size, newSize);
    std::copy(data, data + elementsToCopy, newArray);
    delete[] data;
    data = newArray;
    size = newSize;
}

void Array::sortArray() {
    std::sort(data, data + size);
}

double Array::getMinValue() const {
    double minValue = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
    }
    return minValue;
}

double Array::getMaxValue() const {
    double maxValue = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }
    return maxValue;
}

void Array::randomFill() {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;  
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new double[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

Array Array::mergeArrays(const Array& other) const {
    Array mergedArray(size + other.size);
    std::copy(data, data + size, mergedArray.data);
    std::copy(other.data, other.data + other.size, mergedArray.data + size);
    return mergedArray;
}

Array Array::operator+(const Array& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Array sizes are not equal");
    }

    Array result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

Array Array::operator-(const Array& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Array sizes are not equal");
    }

    Array result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

Array Array::operator/(const Array& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Array sizes are not equal");
    }

    Array result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] / other.data[i];
    }
    return result;
}

Array Array::operator*(const Array& other) const
{
    if (size != other.size) {
        throw std::invalid_argument("Array sizes are not equal");
    }

    Array result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}


void Array::increaseBy(int constant) {
    for (int i = 0; i < size; i++) {
        data[i] += constant;
    }
}
