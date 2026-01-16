#include<iostream>
#include<string>
#include "24F-0593-Q3-Classes.h"
#include "24F-0593-Classes_Methods.cpp"
#include "24F-0593-Functions.cpp"

using namespace std;


int main()
{
	ResourceManager resourceManager;
	CrewManager crewManager;
	VehicleManager vehicleManager;
	MissionManager missionManager;
	int choice = 1;
	while(choice!=0){
		cout << "\n------------------------------- Space Mission Control System -------------------------------\n";
	cout << "1. Manage Resources\n";
	cout << "2. Manage Crew Members\n";
	cout << "3. Manage Vehicles\n";
	cout << "4. Manage Missions\n";
	cout << "5. Display Current Status\n";
	cout << "0. Exit\n";
	cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			resourceMenu(resourceManager);
			break;
		case 2:
			crewMenu(crewManager);
			break;
		case 3:
			vehicleMenu(vehicleManager);
			break;
		case 4:
			missionMenu(missionManager, crewManager, vehicleManager);
			break;
		case 5:
			displayStatus(resourceManager, crewManager, vehicleManager, missionManager);
			break;
		case 0:
			cout << "ThankYou\n";
			break;
		default:
			cout << "Invalid Input!\n";
		}
	} 
}