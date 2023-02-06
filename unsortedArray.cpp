#include <iostream>
using namespace std;

#define MAX 10
template <class T>
class UnsortedArray {
 public:
  UnsortedArray();
  void read();
  void write();
  int search(T);
  int operator ^(T);
  int insert(T);
  int operator +(T); 
  int remove(T);
  int operator -(T);
 
  template <class U>
  friend istream& operator >>(istream& read, UnsortedArray<U>& array);
  template <class U>
  friend ostream& operator <<(ostream& write, UnsortedArray<U>& array);
 private:
  int array_size;
  T array[MAX];
};

template <class T>
UnsortedArray<T>::UnsortedArray() {
 int index = 0;
 array_size = 0;
 
 while(index <= MAX - 1) 
  array[index ++] = 0; // Initialization to predictible value (0 in this case)
}

template <class T>
void UnsortedArray<T>::read() {
 do {
  cout << "How many values do you want to enter?: ";
  cin >> array_size;
  if(array_size < 0 || array_size > MAX)
    cout << "\tNumber (size) " << array_size 
         << " invalid ​​(It must be greater than or equal to 0 and less than 10)\n";
 } while(array_size < 0 || array_size > MAX);

 for(int index = 0; index <= array_size - 1; index ++) {
  cout << "\tInsert your " << index + 1 << "th value: ";
  cin >> array[index]; 
 }
}

template <class T>
istream& operator >>(istream& read, UnsortedArray<T>& array) {
 do {
   cout << "How many values do you want to enter?: ";
   read >> array.array_size;

   if(array.array_size < 0 || array.array_size > MAX)
    cout << "\tNumber (size) " << array.array_size 
         << " invalid ​​(It must be greater than or equal to 0 and less than 10)\n";

 } while(array.array_size < 0 || array.array_size > MAX);

 for(int index = 0; index <= array.array_size - 1; index ++) {
  cout << "\tInsert your " << index + 1 << "th value: ";
  read >> array.array[index]; 
 }
 return read;
}

template <class T>
void UnsortedArray<T>::write() {
 if(array_size > 0)
  for(int index = 0; index <= array_size - 1; index ++)
   cout << array[index] << " ";
 else
  cout << "Empty Array!";
} 

template <class T>
ostream& operator <<(ostream& write, UnsortedArray<T>& array) {
 if(array.array_size > 0)
  for(int index = 0; index <= array.array_size - 1; index ++)
   write << array.array[index] << " ";
 else
  write << "Empty Array!";

 return write;
}

template <class T>
int UnsortedArray<T>::search(T value) {
 int result = -1, index = 0;

 while(index <= array_size - 1 && array[index] != value)
  index ++;
 if(index <= array_size - 1) 
  result = index;

 return result;
}

template <class T>
int UnsortedArray<T>::operator ^(T value) {
 int result = -1, index = 0;
 
 while(index <= array_size - 1 && array[index] != value)
  index ++;
 if(index <= array_size - 1)
  result = index;  

 return result;
}

template <class T>
int UnsortedArray<T>::insert(T value) {
 int result = 1, position;

 if(array_size < MAX) {
  position = search(value);
  if(position < 0) 
   array[array_size ++] = value;
  else
   result = -1; 
 }
 else
  result = 0;
 
 return result;
}

template <class T>
int UnsortedArray<T>::operator +(T value) {
 int position, result = 1;

 if(array_size < MAX) {
  position = search(value);
  if(position < 0) 
   array[array_size ++] = value;
  else
   result = -1;
 }
 else
  result = 0;

 return result;
}

template <class T>
int UnsortedArray<T>::remove(T value) {
 int result = 1, position, index;
 position = search(value);

 if(position >= 0) {
  index = position;
  array_size --;
  while(index <= array_size - 1) {
   array[index] = array[index + 1];
   index ++; 
  }
 }
 else
 result = 0;

 return result;
}

template <class T>
int UnsortedArray<T>::operator -(T value) {
 int result = 1, position, index;
 position = search(value);

 if(position >= 0) {
  index = position;
  array_size --;
  while(index <= array_size - 1) {
   array[index] = array[index + 1];
   index ++;
  }
 }
 else
 result = 0;

 return result;
}

int menu() {
 int option;
 
 cout << "1. Read array"
      << "\n2. Write array"
      << "\n3. Search for a value"
      << "\n4. Insert a new value (Warning: read the array (first option) will erase all!)"
      << "\n5. Remove a value"
      << "\n6. Exit"
      << "\n\tInsert your option: ";
 cin >> option;

 return option;
}

void useArray() {
 UnsortedArray<int> array;
 int value, result, option;
 
 do {
  option = menu();

  system("cls"); // To clear the screen

  switch(option) {
   case 1: 
    cin >> array;
   break;
   case 2: 
    cout << "\t-------- Values --------\n";
    cout << array << "\n\n";
   break;
   case 3:
    cout << "\nInsert the value to search for: ";
    cin >> value;
    result = array ^value;
    if(result < 0)
     cout << "\nThe value " << value << " is not in the array!\n\n";
    else
     cout << "\nThe value " << value << " was found in " << result + 1 << "th position\n\n";
   break;
   case 4:
    cout << "\nValue to insert: "; 
    cin >> value;
    result = array + value;
    if(result > 0)
     cout << "\n\nValue: " << value << " inserted successfully\n";
    else
     if(result == -1)
      cout << "\n\nThe value " << value << " is already in the array!\n";
     else
      cout << "\n\nThe array is full! It not admits no more value in it!\n";
   break;
   case 5:
    cout << "\nInsert value to remove from the array: ";
    cin >> value;
    result = array - value;
    if(result == 0)
     cout << "\nValue " << value << " was not found.\n\n";
    else
     cout << "\nValue " << value << " removed successfully\n\n";
   break;
   case 6:
    cout << "\nFinished process.\n\n";
   break;
   default:
    cout << "\nInvalid option!\n\n";
  }

  system("pause");
  system("cls");

 } while(option != 6); 
}

int
main() {
 useArray(); 

 return 0;
}
