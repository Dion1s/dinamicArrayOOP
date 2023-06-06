#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdlib>
#include <algorithm>
class Array {
private:
    double* data;
    int size;

public:
    Array();
    explicit Array(int size);
    Array(const Array& other);
    ~Array();
    
    void setArraySize(int newSize);

    void fillArray();
    void displayArray() const;
    void resizeArray(int newSize);
    void sortArray();
    double getMinValue() const;
    double getMaxValue() const;

    void randomFill();
    Array& operator=(const Array& other);
    Array mergeArrays(const Array& other) const;
    Array operator+(const Array& other) const;
    Array operator-(const Array& other) const;
    Array operator/(const Array& other) const;
    Array operator*(const Array& other) const;
    void increaseBy(int constant);
};

#endif
