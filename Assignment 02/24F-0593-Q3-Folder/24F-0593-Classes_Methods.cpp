#include "24F-0593-Q3-Classes.h"
#include<iostream>
#include <string>
using namespace std;

CrewManager::CrewManager()
{
	numCrew = 0;
	for (int i = 0; i < 10; i++)
		crew[i] = nullptr;
}

void CrewManager::addCrewMember(CrewMember* member)
{
	if (numCrew < 10)
	{
		crew[numCrew] = member;
		numCrew++;
	}
	else
		cout << "Max number of Crew Members reached!\n";
}

CrewManager::CrewMember::CrewMember(string name, string role, string rank, int experienceYears)
{
	this->name = name;
	this->role = role;
	this->rank = rank;
	this->experienceYears = experienceYears;
	numAssignedMissions = 0;

	for (int i = 0; i < 10; i++)
		assignedMissions[i] = nullptr;
}

CrewManager::CrewMember::CrewMember()
{
	name = "\0";
	role = "\0";
	rank = "\0";
	experienceYears = 0;
	numAssignedMissions = 0;

	for (int i = 0; i < 10; i++)
		assignedMissions[i] = nullptr;
}

void CrewManager::CrewMember::assignMission(MissionManager::Mission* mission)
{
	if (numAssignedMissions < 10)
		assignedMissions[numAssignedMissions++] = mission;

	else
		cout << "Max num of Mission Reached\n";
}

// -----------------------------------------------------------------

MissionManager::Mission::Mission(MissionType type, string name, string startDate, string endDate, string status)
{
	this->type = type;
	this->name = name;
	this->startDate = startDate;
	this->endDate = endDate;
	this->status = status;
	this->numAssignedCrew = 0;
	this->assignedVehicle = nullptr;

	for (int i = 0; i < 10; i++)
		this->assignedCrew[i] = nullptr;
}
MissionManager::Mission::Mission()
{
	type = MissionManager::MissionType::COLONIZATION;
	name = "\0";
	startDate = "\0";
	endDate = "\0";
	status = "\0";
	numAssignedCrew = 0;
	assignedVehicle = nullptr;

	for (int i = 0; i < 10; i++)
		this->assignedCrew[i] = nullptr;
}

void MissionManager::Mission::updateMissionStatus(string status)
{
	this->status = status;
}

// ------------------------------------------------------------------------------------

ResourceManager::ResourceManager()
{
	numResources = 0;
	for (int i = 0; i < 10; i++)
		resources[i] = nullptr;
}

void ResourceManager::addResource(Resource* resource)
{
	if (numResources < 10)
	{
		resources[numResources] = resource;
		numResources++;
	}
	else
		cout << "Max number of resources added\n";
}

void ResourceManager::consumeResource(ResourceType type, double amount)
{
	for (int i = 0; i < numResources; i++)
	{
		if (resources[i]->type == type)
		{
			resources[i]->quantity -= amount;
			break;
		}
	}
}

// -------------------------------------------------------------------------------------

VehicleManager::VehicleManager()
{
	numVehicles = 0;
	for (int i = 0; i < 10; i++)
		vehicles[i] = nullptr;
}

void VehicleManager::addVehicle(Vehicle* vehicle)
{
	if (numVehicles < 10)
		vehicles[numVehicles++] = vehicle;

	else
		cout << "Max num of Vehicles added!\n";
}

VehicleManager::Vehicle::Vehicle(VehicleType type, string name, double fuelLevel)
{
	this->type = type;
	this->name = name;
	this->fuelLevel = fuelLevel;
	crewCapacity = 10;
	numCurrentCrew = 0;

	for (int i = 0; i < 10; i++)
		currentCrew[i] = nullptr;
}

VehicleManager::Vehicle::Vehicle()
{
	this->type = VehicleManager::VehicleType::SHUTTLE;
	this->name = "\0";
	this->fuelLevel = 0;
	this->crewCapacity = 10;
	this->numCurrentCrew = 0;

	for (int i = 0; i < 10; i++)
		currentCrew[i] = nullptr;
}

void VehicleManager::Vehicle::refuel(double amount)
{
	fuelLevel += amount;
}