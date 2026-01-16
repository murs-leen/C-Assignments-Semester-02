//#include<iostream>
//#include<string>
//
//using namespace std;
//template <class T>
//T decimal(T* arr, std::string base, int size) {
//    int multiplier = 10;
//
//    if (base == "binary") multiplier = 2;
//    else if (base == "octal") multiplier = 8;
//    else if (base == "hexadecimal") multiplier = 16;
//
//    T result = 0;
//    T power = 1;
//
//    for (int i = size - 1; i >= 0; --i) {
//        result += arr[i] * power;
//        power *= multiplier;
//    }
//
//    return result;
//}
//
//int main() {
//    int size;
//    cout << "Conversion system " << endl;
//    cout << "Enter the size of number:";
//    cin >> size;
//    int* arr = new int[size];
//    cout << "Enter the digits :";
//    for (int i = 0; i < size; ++i) {
//        cin >> arr[i];
//    }
//    string base;
//    cout << "Enter base in lower case:";
//    cin >> base;
//    int dec = decimal(arr, base, size);
//    cout << dec;
//    return 0;
//}