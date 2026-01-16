//#include <iostream>
//using namespace std;
//
//template <class A>
//A* merge(A arr1[], A arr2[], int s1, int s2) {
//    A* temp = new A[s1 + s2];
//    for (int i = 0; i < s1; ++i) {
//        temp[i] = arr1[i];
//    }
//    for (int i = s1, j = 0; j < s2; ++i, ++j) {
//        temp[i] = arr2[j];
//    }
//    return temp;
//}
//
//template <class A>
//void display(A arr[], int s) {
//    for (int i = 0; i < s; ++i) {
//        cout << arr[i] << ' ';
//    }
//    cout << endl;
//}
//
//int main() {
//    int s1, s2;
//    cout << "Enter size of array 1: ";
//    cin >> s1;
//    cout << "Enter the size of array 2: ";
//    cin >> s2;
//    int* ptr1 = new int[s1];
//    int* ptr2 = new int[s2];
//    cout << "Enter values of first array:";
//    for (int i = 0; i < s1; ++i) {
//        cin >> *(ptr1 + i);
//    }
//    cout << "Enter values of second array:";
//    for (int i = 0; i < s2; ++i) {
//        cin >> *(ptr2 + i);
//    }
//    cout << "Merged array : ";
//    int* result = merge(ptr1, ptr2, s1, s2);
//    display(result, s1+s2);
//    delete[] result; 
//    return 0;
//}