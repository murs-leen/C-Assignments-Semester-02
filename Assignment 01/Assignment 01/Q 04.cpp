//#include<iostream>
//using namespace std;
//
//float* addArrays(float* arr1, float* arr2,float* arr3, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		*(arr3 + i) = *(arr1 + i) + *(arr2 + i);
//	}
//	return arr3;
//}
//int main()
//{
//	float arr1[50] = { 0 }, arr2[50] = { 0 }, arr3[50] = { 0 };
//	cout << "Enter the size of array: ";
//	int size;
//	cin >> size;
//	for (int i = 0; i < size; ++i)
//	{
//		*(arr1 + i) = (rand() % 10 + 20) * 0.27;
//		*(arr2 + i) = (rand() % 10 + 30) * 0.37;
//	}
//	cout << "Array 1: ";
//	for (int i = 0; i < size; ++i)
//	{
//		cout << *(arr1 + i) << "  ";
//	}
//	cout << endl;
//	cout << "Array 2: ";
//	for (int i = 0; i < size; ++i)
//	{
//		cout << *(arr2 + i) << "  ";
//	}
//	cout << endl;
//	float* result = addArrays(arr1, arr2, arr3, size);
//	cout << "Resultant array: ";
//	for (int i = 0; i < size; ++i)
//	{
//		cout << *(result + i) << "  ";
//	}
//}