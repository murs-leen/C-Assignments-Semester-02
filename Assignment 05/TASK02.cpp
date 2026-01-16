//#include<iostream>
//using namespace std;
//
//template <class A>
//int removeRedundency(A arr[], int size) {
//    int newSize = 0;
//    for (int i = 0; i < size; ++i) {
//        bool isDuplicate = false;
//        for (int j = 0; j < newSize; ++j) {
//            if (arr[i] == arr[j]) {
//                isDuplicate = true;
//                break;
//            }
//        }
//        // If it's not a duplicate, copy it to the new position
//        if (!isDuplicate) {
//            arr[newSize++] = arr[i];
//        }
//    }
//    return newSize;
//}
//template <class A>
//void display(A arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << ' ';
//    }
//    cout << endl;
//}
//
//int main() {
//    int size;
//    cout << "Enter Size:";
//    cin >> size;
//    char* arr = new char[size];
//    cout << "Enter an array with redundant elms of size(" << size << "):" << endl;
//    for (int i = 0; i < size; ++i) {
//        cin >> arr[i];
//    }
//    cout << "Original Array: ";
//    display(arr, size);
//    int newSize = removeRedundency(arr, size);
//    cout << "Reduced Array: ";
//    display(arr, newSize);
//    cout << endl;
//    return 0;
//}