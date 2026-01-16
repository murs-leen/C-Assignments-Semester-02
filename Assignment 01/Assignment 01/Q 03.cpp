#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;

void menu();
int _strlen(const char* ch)
{
	int leng = 0;
	for (int i = 0; ch[i] != '\0'; ++i)
	{
		leng++;
	}
	return leng;
}
int _strcmp(const char* str1, const char* str2)
{
	for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; ++i)
	{
		if (str1[i] > str2[i])
			return 1;
		else if(str1[i] < str2[i])
			return -1;
	}
	return 0;
}
int _strncmp(const char* str1, const char* str2, int n)
{
	int str1Leng = _strlen(str1);
	int str2Leng = _strlen(str2);
	while(n > str1Leng || n > str2Leng)
	{
		cout << "n-can't be greater than string 1 or string 2"<< endl;
		cout << "Enter number of characters to compare: ";
		cin >> n;
	}
	for (int i = 0; i < n; ++i)
	{
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;
	}
	return 0;
}
char* _strcpy(char* des, const char* src)
{
	int leng = _strlen(src);
	for (int i = 0; i < leng; ++i)
	{
		*(des + i) = *(src + i);
	}
	*(des + leng) = '\0';
	return des;
}
char* _strncpy(char* des, const char* src, int n)
{
	int leng = _strlen(src);
	while (n > leng || n < 0)
	{
		cout << "n-can't be greater than string 1 or string 2" << endl;
		cout << "Enter number of characters to compare: ";
		cin >> n;
	}
	for (int i = 0; i < n; ++i)
	{
		*(des + i) = *(src + i); 
	}
	*(des + n) = '\0';
	return des;
}
char* _strcat(char* str1, const char* str2)
{
	int leng1 = _strlen(str1);
	int leng = _strlen(str2);
	for (int i = 0; i < leng; ++i)
	{
		*(str1 + leng1 + i) = *(str2 + i);
	}
	*(str1 + leng + leng1) = '\0';
	return str1;
}
char* _strncat(char* str1, const char* str2, int n)
{
	int leng1 = _strlen(str1);
	int leng = _strlen(str2);
	while (n > leng || n < 0)
	{
		cout << "n-can't be greater than string 1 or string 2" << endl;
		cout << "Enter number of characters to compare: ";
		cin >> n;
	}
	for (int i = 0; i < n; ++i)
	{
		*(str1 + leng1 + i) = *(str2 + i);
	}
	*(str1 + n + leng1) = '\0';
	return str1;
}

int main()
{
	menu();
	return 0;
}
void menu()
{
	char str1[100];
	char str2[100];
	cout << "Select the desired choice " << endl;
	cout << endl;
	cout << "1. Find lenght of string:" << endl;
	cout << "2. Compare two strings: "<< endl;
	cout << "3. Compare parts of two strings"<< endl;
	cout << "4. Copy one string to other"<< endl;
	cout << "5. Copy part of a string" << endl;
	cout << "6. Concatinate two string" << endl;
	cout << "7. Concatinate one with part of other" << endl;
	char ch1;
	cout << "Enter your choice:";
	cin >> ch1;
	cin.ignore();
	if (ch1 == '1')
	{
		cout << "Enter string:";
		cin.getline(str1, 100); 
		int leng = _strlen(str1);
		cout << "Lenght of string: " << leng;
		_getch();
		system("cls");
		main();
	}
	else if (ch1 == '2')
	{
		cout << "Enter string-01: ";
		cin.getline(str1, 100);
		cout << "Enter string-02: ";
		cin.getline(str2, 100);
		int val = _strcmp(str1, str2);
		if (val > 0)
			cout << "String 1 is greater than string 2" << endl;
		else if (val < 0)
			cout << "String 1 is less than string 2" << endl;
		else
			cout << "Strings are equal :)" << endl;
		_getch();
		system("cls");
		main();
	}
	else if (ch1 == '3')
	{
		int n;
		cout << "Enter string-01: ";
		cin.getline(str1, 100);
		cout << "Enter string-02: ";
		cin.getline(str2, 100);
		cout << "Enter number of characters to compare: ";
		cin >> n;
		int val = _strncmp(str1, str2,n);
		if (val > 0)
			cout << "String 1 is greater than string 2" << endl;
		else if (val < 0)
			cout << "String 1 is less than string 2" << endl;
		else
			cout << "Strings are equal :)" << endl;
		_getch();
		system("cls");
		main();
	}
	else if (ch1 == '4')
	{
		cout << "Enter strin: ";
		cin.getline(str1, 100);
		int leng = _strlen(str1);
		char* cpyString = new char[leng + 1];
		char* returnStr = _strcpy(cpyString, str1);
		cout << "Copied string: " << returnStr << endl;
		_getch();
		system("cls"); 
		main();
	}
	else if (ch1 == '5')
	{
		int n;
		cout << "Enter string: ";
		cin.getline(str1, 100);
		cout << "Enter number of characters to copy:";
		cin >> n;
		int leng = _strlen(str1);
		char* cpyString = new char[n + 1];
		char* returnStr = _strncpy(cpyString, str1, n);
		cout << "Copied string to n number of characters: " << returnStr << endl;
		_getch();
		system("cls");
		main();
	}
	else if (ch1 == '6')
	{
		cout << "Enter string-01: ";
		cin.getline(str1, 200);
		int leng = _strlen(str1);
		cout << "Enter string-02: ";
		cin.getline(str2, 100);
		char* str = _strcat(str1, str2);
		cout << "Concated string :" << str;
		_getch();
		system("cls");
		main();
	}
	else if (ch1 == '7')
	{
		int n;
		cout << "Enter string-01: ";
		cin.getline(str1, 200);
		int leng = _strlen(str1);
		cout << "Enter string-02: ";
		cin.getline(str2, 100);
		cout << "Enter number of characters you want to concat: ";
		cin >> n;
		char* str = _strncat(str1, str2, n);
		cout << "Concated string :" << str;
		_getch();
		system("cls");
		main();
	}
}