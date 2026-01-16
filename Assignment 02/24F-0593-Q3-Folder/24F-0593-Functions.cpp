#include <iostream>
#include <string>
#include "24F-0593-Q3-Classes.h"
using namespace std;

string getResourceName(ResourceManager::ResourceType type)
{
    switch (type)
    {
    case ResourceManager::ResourceType::FUEL:
        return "FUEL";
    case ResourceManager::ResourceType::FOOD:
        return "FOOD";
    case ResourceManager::ResourceType::WATER:
        return "WATER";
    case ResourceManager::ResourceType::MEDICAL_SUPPLIES:
        return "MEDICAL_SUPPLIES";
    case ResourceManager::ResourceType::TECHNOLOGY:
        return "TECHNOLOGY";
    case ResourceManager::ResourceType::MATERIALS:
        return "MATERIALS";
    default:
        return "Invalid Input";
    }
}

string getMissionTypeName(MissionManager::MissionType type)
{
    switch (type)
    {
    case MissionManager::MissionType::EXPLORATION:
        return "EXPLORATION";
    case MissionManager::MissionType::TRANSPORT:
        return "TRANSPORT";
    case MissionManager::MissionType::DEFENSE:
        return "DEFENSE";
    case MissionManager::MissionType::REPAIR:
        return "REPAIR";
    case MissionManager::MissionType::COLONIZATION:
        return "COLONIZATION";
    default:
        return "Invalid Input";
    }
}

string getVehicleTypeName(VehicleManager::VehicleType type)
{
    switch (type)
    {
    case VehicleManager::VehicleType::SHUTTLE:
        return "SHUTTLE";
    case VehicleManager::VehicleType::ROVER:
        return "ROVER";
    case VehicleManager::VehicleType::SPACE_STATION:
        return "SPACE_STATION";
    case VehicleManager::VehicleType::FREIGHTER:
        return "FREIGHTER";
    case VehicleManager::VehicleType::PROBE:
        return "PROBE";
    default:
        return "Invalid Input";
    }
}

void MissionManager::Mission::displayMissionDetails()
{
    cout << "Mission: " << name << " (" << getMissionTypeName(type) << ")\nDates: " << startDate << " to " << endDate << "\nStatus: " << status << endl;
}

void ResourceManager::displayResources()
{
    for (int i = 0; i < numResources; i++)
        cout << "Resource: " << getResourceName(resources[i]->type) << "\nQuantity: " << resources[i]->quantity << "\nValue: " << resources[i]->value << "\nExpiration: " << resources[i]->expirationDate << endl;
}

void resourceConsumption(int type, ResourceManager &rManager)
{
    int amount;
    cout << "Enter amount to consume: ";
    cin >> amount;
    ResourceManager::ResourceType resType = static_cast<ResourceManager::ResourceType>(type);
    rManager.consumeResource(resType, amount);
    cout << amount << " amount of " << getResourceName(resType) << " is consumed!" << endl;
}

void resourceMenu(ResourceManager &rManager)
{
    int choice;
    bool ifAdded = false;
    bool ifAdded_Fuel = false;
    bool ifAdded_Food = false;
    bool ifAdded_Water = false;
    bool ifAdded_MedicalSupplies = false;
    bool ifAdded_Technology = false;
    bool ifAdded_Materials = false;
    do
    {
        cout << "\n------------------------------- Resource Management -------------------------------\n";
        cout << "1. Add Resource\n";
        cout << "2. Consume Resource\n";
        cout << "3. View Resources\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ifAdded = true;
            int type;
            double qty, val;
            string exp;

            cout << "\nResource Types:\n";
            cout << "1. FUEL\n2. FOOD\n3. WATER\n4. MEDICAL_SUPPLIES\n5. TECHNOLOGY\n6. MATERIALS\n";
            cout << "Enter resource type (1-6): ";
            cin >> type;

            if (type < 1 || type > 6)
                cout << "Invalid Input!\n";
            else
            {
                switch (type)
                {
                case 1:
                    ifAdded_Fuel = true;
                    break;
                case 2:
                    ifAdded_Food = true;
                    break;
                case 3:
                    ifAdded_Water = true;
                    break;
                case 4:
                    ifAdded_MedicalSupplies = true;
                    break;
                case 5:
                    ifAdded_Technology = true;
                    break;
                case 6:
                    ifAdded_Materials = true;
                    break;
                }
                cout << "Enter quantity: ";
                cin >> qty;
                cout << "Enter value: ";
                cin >> val;
                cout << "Enter expiration date (DD/MM/YYYY): ";
                cin >> exp;

                ResourceManager::Resource *resource = new ResourceManager::Resource{static_cast<ResourceManager::ResourceType>(type), qty, val, exp};
                rManager.addResource(resource);
                cout << getResourceName(resource->type) << " resource added successfully!\n";
            }
            break;
        }
        case 2:
        {

            int type;
            double amount;

            if (ifAdded)
            {

                cout << endl
                     << "Resource Types:" << endl;
                cout << "1. Fuel" << endl
                     << "2. Food" << endl
                     << "3. Water" << endl
                     << "4. Medical Supplies" << endl
                     << "5. Technology" << endl
                     << "6. Materials" << endl;

                cout << "Enter resource type to consume (1-6): ";
                cin >> type;

                if (type < 1 || type > 6)
                    cout << "Invalid Input!" << endl;
                else
                {
                    if (ifAdded_Fuel && type == 1)
                    {
                        resourceConsumption(type, rManager);
                    }
                    else if (ifAdded_Food && type == 2)
                    {
                        resourceConsumption(type, rManager);
                    }
                    else if (ifAdded_Water && type == 3)
                    {
                        resourceConsumption(type, rManager);
                    }
                    else if (ifAdded_MedicalSupplies && type == 4)
                    {
                        resourceConsumption(type, rManager);
                    }
                    else if (ifAdded_Technology && type == 5)
                    {
                        resourceConsumption(type, rManager);
                    }
                    else if (ifAdded_Materials && type == 6)
                    {
                        resourceConsumption(type, rManager);
                    }
                    else
                    {
                        cout << "You don't have this resource." << endl;
                    }
                }
            }
            else
            {
                cout << "You have not added anything yet" << endl;
            }

            break;
        }
        case 3:
        {
            cout << endl
                 << "Current Resources:\n";
            for (int i = 0; i < rManager.numResources; i++)
            {
                if (rManager.resources[i] != nullptr)
                    cout << getResourceName(rManager.resources[i]->type) << endl
                         << "Quantity: " << rManager.resources[i]->quantity << endl
                         << "Value: " << rManager.resources[i]->value << endl
                         << "Expires: " << rManager.resources[i]->expirationDate << endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid Input!" << endl;
        }
    } while (choice != 0);
}

void crewMenu(CrewManager &cManager)
{
    int choice;
    do
    {
        cout << "\n------------------------------- Crew Management -------------------------------\n";
        cout << "1. Add Crew Member\n";
        cout << "2. View Crew Members\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, role, rank;
            int exp;

            cout << "\nEnter crew member details:\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Role: ";
            getline(cin, role);
            cout << "Rank: ";
            getline(cin, rank);
            cout << "Experience (years): ";
            cin >> exp;
            CrewManager::CrewMember *member = new CrewManager::CrewMember(name, role, rank, exp);
            cManager.addCrewMember(member);
            cout << "Crew member " << name << " successfully added!\n";
            break;
        }
        case 2:
        {
            cout << "\nCurrent Crew Members:\n";
            for (int i = 0; i < cManager.numCrew; i++)
            {
                if (cManager.crew[i] != nullptr)
                {
                    cout << i + 1 << ". " << cManager.crew[i]->name
                         << " (" << cManager.crew[i]->role << ", " << cManager.crew[i]->rank
                         << ")\n"
                         << cManager.crew[i]->experienceYears << " years experience\n";
                }
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid Input!\n";
        }
    } while (choice != 0);
}

void vehicleMenu(VehicleManager &vManager)
{
    int choice;
    do
    {
        cout << "\n------------------------------- Vehicle Management -------------------------------\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Refuel Vehicle\n";
        cout << "3. View Vehicles\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int type;
            string name;
            double fuel;

            cout << "\nVehicle Types:\n";
            cout << "1. SHUTTLE\n2. ROVER\n3. SPACE_STATION\n4. FREIGHTER\n5. PROBE\n";
            cout << "Enter vehicle type (1-5): ";
            cin >> type;

            if (type < 1 || type > 5)
                cout << "Invalid Input!\n";
            else
            {
                cout << "Enter vehicle name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter fuel level: ";
                cin >> fuel;
                VehicleManager::Vehicle *vehicle = new VehicleManager::Vehicle{static_cast<VehicleManager::VehicleType>(type - 1), name, fuel};
                vManager.addVehicle(vehicle);
                cout << getVehicleTypeName(vehicle->type) << " " << name << " added successfully!\n";
            }
            break;
        }
        case 2:
        {
            string name;
            double amount;
            cout << "Enter vehicle name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter fuel amount: ";
            cin >> amount;
            bool found = false;
            for (int i = 0; i < vManager.numVehicles && !found; i++)
            {
                if (vManager.vehicles[i] != nullptr && vManager.vehicles[i]->name == name)
                {
                    vManager.vehicles[i]->refuel(amount);
                    cout << name << "'s new fuel level " << vManager.vehicles[i]->fuelLevel << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "Vehicle not found!\n";
            break;
        }
        case 3:
        {
            cout << "\nCurrent Vehicles:\n";
            for (int i = 0; i < vManager.numVehicles; i++)
            {
                if (vManager.vehicles[i] != nullptr)
                    cout << i + 1 << ". " << vManager.vehicles[i]->name << " (" << getVehicleTypeName(vManager.vehicles[i]->type) << ")\nFuel: " << vManager.vehicles[i]->fuelLevel << endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid Input!\n";
        }
    } while (choice != 0);
}

void missionMenu(MissionManager &mManager, CrewManager &cManager, VehicleManager &vManager)
{
    int choice;
    do
    {
        cout << "\n------------------------------- Mission Management -------------------------------\n";
        cout << "1. Create Mission\n";
        cout << "2. Assign Crew to Mission\n";
        cout << "3. Assign Vehicle to Mission\n";
        cout << "4. Update Mission Status\n";
        cout << "5. View Mission Details\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int type;
            string name, start, end;
            cout << "\nMission Types:\n";
            cout << "1. EXPLORATION\n2. TRANSPORT\n3. DEFENSE\n4. REPAIR\n5. COLONIZATION\n";
            cout << "Enter mission type (1-5): ";
            cin >> type;
            if (type < 1 || type > 5)
                cout << "Invalid Input!\n";
            else
            {
                cout << "Enter mission name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter start date (DD/MM/YYYY): ";
                getline(cin, start);
                cout << "Enter end date (DD/MM/YYYY): ";
                getline(cin, end);
                mManager.m1 = MissionManager::Mission(static_cast<MissionManager::MissionType>(type - 1), name, start, end, "PLANNED");
                cout << "Mission " << name << " successfully created!\n";
            }
            break;
        }
        case 2:
        {
            string crewName;
            cout << "Enter crew member name: ";
            cin.ignore();
            getline(cin, crewName);
            bool found = false;
            for (int i = 0; i < cManager.numCrew && !found; i++)
            {
                if (cManager.crew[i] != nullptr && cManager.crew[i]->name == crewName)
                {
                    if (mManager.m1.numAssignedCrew < 10)
                    {
                        mManager.m1.assignedCrew[mManager.m1.numAssignedCrew] = cManager.crew[i];
                        mManager.m1.numAssignedCrew++;
                        cout << crewName << " assigned to mission " << mManager.m1.name << ".\n";
                        found = true;
                    }
                    else
                    {
                        cout << "Crew capacity is full!\n";
                        found = true;
                    }
                }
            }

            if (!found)
                cout << "Crew member not found!\n";
            break;
        }
        case 3:
        {
            if (mManager.m1.name == "\0")
                cout << "Please create a mission first!\n";
            else
            {
                string vehicleName;
                cout << "Enter vehicle name: ";
                cin.ignore();
                getline(cin, vehicleName);
                bool found = false;
                for (int i = 0; i < vManager.numVehicles && !found; i++)
                {
                    if (vManager.vehicles[i] != nullptr && vManager.vehicles[i]->name == vehicleName)
                    {
                        mManager.m1.assignedVehicle = vManager.vehicles[i];
                        cout << vehicleName << " is assigned to mission " << mManager.m1.name << ".\n";
                        found = true;
                    }
                }
                if (!found)
                    cout << "Vehicle not found!\n";
            }
            break;
        }
        case 4:
        {
            if (mManager.m1.name == "\0")
                cout << "Please create a mission first!\n";
            else
            {
                string newStatus;
                cout << "Enter new status: ";
                cin.ignore();
                getline(cin, newStatus);
                mManager.m1.updateMissionStatus(newStatus);
                cout << "Mission Status Updated Successfully\n";
            }
            break;
        }
        case 5:
        {
            if (mManager.m1.name == "\0")
                cout << "No mission created yet!\n";
            else
            {
                mManager.m1.displayMissionDetails();
                cout << "Assigned Crew: ";
                if (mManager.m1.numAssignedCrew == 0)
                    cout << "No Assigned crew!\n";

                else
                {
                    for (int i = 0; i < mManager.m1.numAssignedCrew; i++)
                    {
                        if (i != 0)
                            cout << ", ";
                        cout << ((CrewManager::CrewMember *)mManager.m1.assignedCrew[i])->name;
                    }
                }
                cout << "\nAssigned Vehicle: ";
                if (mManager.m1.assignedVehicle)
                    cout << ((VehicleManager::Vehicle *)mManager.m1.assignedVehicle)->name;
                else
                    cout << "No Vehicle is Assigned\n";
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid Input!\n";
        }
    } while (choice != 0);
}

void displayStatus(ResourceManager &rManager, CrewManager &cManager, VehicleManager &vManager, MissionManager &mManager)
{
    cout << "\n------------------------------- SYSTEM STATUS -------------------------------\n";

    cout << "\nRESOURCES:\n";
    for (int i = 0; i < rManager.numResources; i++)
    {
        if (rManager.resources[i] != nullptr)
            cout << getResourceName(rManager.resources[i]->type) << ":\n"
                 << rManager.resources[i]->quantity << " units\n"
                 << "Value: " << rManager.resources[i]->value << "\nExpiry Date: " << rManager.resources[i]->expirationDate << endl;
    }

    cout << "\nCREW MEMBERS:\n";
    for (int i = 0; i < cManager.numCrew; i++)
    {
        if (cManager.crew[i] != nullptr)
            cout << cManager.crew[i]->name << "\nRole: " << cManager.crew[i]->role << "\nRank: " << cManager.crew[i]->rank << endl
                 << cManager.crew[i]->experienceYears << " years experience\n";
    }

    cout << "\nVEHICLES:\n";
    for (int i = 0; i < vManager.numVehicles; i++)
    {
        if (vManager.vehicles[i] != nullptr)
            cout << "Name: " << vManager.vehicles[i]->name << " (" << getVehicleTypeName(vManager.vehicles[i]->type) << ")\nFuel: " << vManager.vehicles[i]->fuelLevel << "\n";
    }

    cout << "\nCURRENT MISSION:\n";
    mManager.m1.displayMissionDetails();
    cout << "Assigned Crew: ";
    if (mManager.m1.numAssignedCrew == 0)
        cout << "No crew Assigned!\n";
    else
    {
        for (int i = 0; i < mManager.m1.numAssignedCrew; i++)
        {
            if (i != 0)
                cout << ", ";
            cout << ((CrewManager *)mManager.m1.assignedCrew[i])->c1.name;
        }
    }
    cout << "\nAssigned Vehicle: ";
    if (mManager.m1.assignedVehicle)
        cout << ((VehicleManager::Vehicle *)mManager.m1.assignedVehicle)->name;
    else
        cout << "No Vehicle Assigned!\n";
}