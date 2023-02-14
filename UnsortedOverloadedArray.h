#include <iostream>

using namespace std;

#define MAX 10

template <class T>
class Array {
    public:
     Array();
     // Searchs for a value
     int operator ^(T); 
     // Inserts data
     int operator +(T);
     // Removes data
     int operator -(T);
     
     // Read and write the array
     template <class U>
     friend istream& operator >>(istream& read, Array<U>& arr);
     template <class U>
     friend ostream& operator <<(ostream& write, Array<U>& arr);
     
    private:
     int size;
     T array[MAX];
};

template <class T>
Array<T>::Array() {
    size = 0;
    for(int index = 0; index <=  MAX - 1; index ++) 
     array[index] = '0';
}

template <class T>
int Array<T>::operator ^(T value) {
    int result = -1, index = 0;
    
    while(index <= size - 1 && array[index] != value) 
     index ++;
    if(index <= size - 1)
     result = index;
    
    return result;
}

template <class T>
int Array<T>::operator -(T value) {
    int result = 1, position, index;
    position = *this ^ value;
    
    if(position >= 0) {
        size --;
        for(index = position; index <= size - 1; index ++)
         array[index] = array[index + 1];
    }
    else
     result = 0;
     
    return result;
}

template <class T>
int Array<T>::operator +(T value) {
    int result = 1;
    
    if(size <=  MAX - 1)
     array[size ++] = value;
    else
     result = 0;
     
    return result;
}

template <class T>
istream &operator >>(istream &read, Array<T> &arr) {
    do {
        cout << "Enter the array size: ";
        read >> arr.size;
        if(arr.size < 0 || arr.size > MAX)
         cout << "\n!The size of you array it can't be less than 0 or greater than " << MAX << endl; 
    } while(arr.size < 0 || arr.size > MAX);
    
    for(int index = 0; index <= arr.size - 1; index ++) {
        cout << index + 1 << "th value: ";
        read >> arr.array[index];
    }
    
    return read;
}

template <class T>
ostream &operator <<(ostream &write, Array<T> &arr) {
    for(int index = 0; index <= arr.size - 1; index ++)
     write << arr.array[index] << " ";
    
    return write;
}


