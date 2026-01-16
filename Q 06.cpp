#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

void initiTrack(char*);
void display(char*);
void moveTortoise(char*, int*);
void moveHare(char*, int*);
bool condChecking(int*pos1,int* pos2, char* ch);
int main()
{
	int tortoisePos = 1;
	int harePos = 1;
	int* posPtr = &tortoisePos;
	int* posPtr1 = &harePos;
	char track[80];
	initiTrack(track);
	bool flag = true;
	while (flag)
	{
		moveTortoise(track, posPtr);
		moveHare(track, posPtr1);
		display(track);
		bool val = condChecking(posPtr, posPtr1, track);
		if (!val)
		{
			flag = false;
			continue;
		}
		system("cls");
	}
	return 0;
}

//Initializing Track
void initiTrack(char* track)
{
	track[0] = 'T';
	track[0] = 'H';
	for (int i = 0; i < 80; ++i)
	{
		track[i] = ' ';
	}
}

//Displaying Track
void display(char* track)
{
	for (int i = 1; i < 80; ++i)
	{
		cout << track[i];
	}
	Sleep(50);
}

// Tortoise position
void moveTortoise(char* track, int* pos)
{
	track[*pos] = ' ';
	*pos = rand() % 50 + 1;
	if (*pos >= 1 && *pos <= 25)
	{
		*pos += 4; //fast plod
		if (*pos > 80)
			*pos = 80;
	}
	else if (*pos >= 26 && *pos <= 35)
	{
		*pos -= 5; // slip
		if (*pos < 1)
		{
			*pos = 1;
		}
	}
	else if (*pos >= 36 && *pos <= 50)
	{
		*pos += 1; //slow plod
		if (*pos > 80)
			*pos = 80;
	}
	track[*pos] = 'T';

}

//Hare position
void moveHare(char* track, int* pos)
{
	track[*pos] = ' ';
	*pos = rand() % 50 + 1;
	if (*pos <= 19)
	{
		*pos = *pos; //Sleep
		if (*pos > 80)
			*pos = 80;
	}
	else if (*pos <= 29)
	{
		*pos += 11; // Big hop
		if (*pos > 80)
			*pos = 80;
	}
	else if (*pos <= 39)
	{
		*pos -= 9; //slow plod
		if (*pos < 1)
			*pos = 1;
	}
	else
		*pos += 1;

	track[*pos] = 'H';
}
bool condChecking(int* pos1, int* pos2, char* track)
{
	if (*pos1 >= 50 || *pos2 >= 50)
	{
		if (*pos1 >= 50 && *pos2 >= 50)
		{
			cout << "\n\nIt's a tie.\n";
		}
		else if (*pos1 >= 50)
		{
			cout << "\n\nTORTOISE WINS!!! YAY!!!\n";
		}
		else
		{
			cout << "\n\nHare wins. Yuck.\n";
		}
		return false;
	}
	if (*pos1 == *pos2 && *pos1 <= 80 && *pos2 <= 80) {
		int start;
		if (*pos1 > *pos2)
			start = *pos1 - 7;
		else
			start = *pos2 - 9;
		const char* ouch = "OUCH!!!"; 
		for (int i = 0; i < 7; i++){   
				track[start + i] = ouch[i]; 
		} 
	}
	return true;
}