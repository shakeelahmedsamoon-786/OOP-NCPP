#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray {
private:
    int* iptr{};
    int size{};
    int capacity{};

public:
    DArray();
    DArray& operator=(const DArray& other);
    void push_back(int value);

    friend ostream& operator<<(ostream& out, const DArray&);

    ~DArray();
};

// friend ostream& operator<<(ostream& out, const DArray&);

#endif

#include "dynamic.h"

DArray::DArray() {
    iptr = nullptr;
    size = 0;
    capacity = 0;
}

DArray& DArray::operator=(const DArray& other) {

    if (this != &other) {

        delete[] iptr;

        size = other.size;
        capacity = other.capacity;

        if (capacity > 0) {

            iptr = new int[capacity];

            for (int i = 0; i < size; i++) {
                iptr[i] = other.iptr[i];
            }
        }
        else {
            iptr = nullptr;
        }
    }

    return *this;
}

void DArray::push_back(int value) {

    if (size == capacity) {

        int newCapacity;

        if (capacity == 0)
            newCapacity = 1;
        else
            newCapacity = capacity * 2;

        int* temp = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            temp[i] = iptr[i];
        }

        delete[] iptr;

        iptr = temp;
        capacity = newCapacity;
    }

    iptr[size] = value;
    size++;
}

ostream& operator<<(ostream& out, const DArray& obj) {

    for (int i = 0; i < obj.size; i++) {
        out << obj.iptr[i] << " ";
    }

    return out;
}

DArray::~DArray() {
    delete[] iptr;
}


#include"dynamic.h"
using namespace std;

int main(){
    DArray darr1, darr2;			//darr1 & darr2 have size 0
    for (int j{}; j < 15; ++j){
    	darr1.push_back(j*2);
    }
    cout << darr1 << endl;
    darr2 = darr1;
    for (int j{15}; j >= 0; --j){
    	darr2.push_back(j*3);
    }
    cout << darr2 << endl;

    return 0;
} 
