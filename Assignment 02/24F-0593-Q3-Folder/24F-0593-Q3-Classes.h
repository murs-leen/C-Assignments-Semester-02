#pragma once
#include <iostream>
#include <string>

using namespace std;

class ResourceManager;
class CrewManager;
class VehicleManager;
class MissionManager;

class ResourceManager
{
public:
	enum class ResourceType { FUEL = 1, FOOD, WATER, MEDICAL_SUPPLIES, TECHNOLOGY, MATERIALS };

	struct Resource
	{
		ResourceType type;
		double quantity;
		double value;
		string expirationDate;
	}r1;

	Resource* resources[10];
	int numResources;

	ResourceManager();
	void addResource(Resource* resource);
	void consumeResource(ResourceType type, double amount);
	void displayResources();
};

class MissionManager
{
public:
	enum class MissionType { EXPLORATION = 1, TRANSPORT, DEFENSE, REPAIR, COLONIZATION };

	struct Mission
	{
		MissionType type;
		string name;
		string startDate;
		string endDate;
		string status;
		void* assignedCrew[10];
		int numAssignedCrew;
		void* assignedVehicle;

		Mission(MissionType type, string name, string startDate, string endDate, string status);
		Mission();
		void updateMissionStatus(string status);
		void displayMissionDetails();
	}m1;
};

class CrewManager
{
public:
	struct CrewMember
	{
		string name;
		string role;
		string rank;
		int experienceYears;
		MissionManager::Mission* assignedMissions[10];
		int numAssignedMissions;
		CrewMember(string name, string role, string rank, int experienceYears);
		CrewMember();
		void assignMission(MissionManager::Mission* mission);
	}c1;

	CrewMember* crew[10];
	int numCrew;

	CrewManager();
	void addCrewMember(CrewMember* member);
};

class VehicleManager
{
public:
	enum class VehicleType { SHUTTLE = 1, ROVER, SPACE_STATION, FREIGHTER, PROBE };

	struct Vehicle
	{
		VehicleType type;
		string name;
		double fuelLevel;
		int crewCapacity;
		CrewManager::CrewMember* currentCrew[10];
		int numCurrentCrew;

		Vehicle(VehicleType type, string name, double fuelLevel);
		Vehicle();
		void refuel(double amount);
	}v1;

	Vehicle* vehicles[10];
	int numVehicles;
	VehicleManager();
	void addVehicle(Vehicle* vehicle);
};
