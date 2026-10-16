
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    static int totalVehicles;

    int vehicleID, year;
    string manufacturer, model;

    Vehicle()
    {
        vehicleID = 0;
        year = 0;
    }

    void input()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;

        cout << "Enter Manufacturer: ";
        cin >> manufacturer;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
public:
    string fuelType;

    void inputCar()
    {
        input();
        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }
};

class ElectricCar : public Car
{
public:
    int batteryCapacity;

    void inputElectricCar()
    {
        inputCar();
        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
    }
};

class SportsCar : public ElectricCar
{
public:
    int topSpeed;

    void inputSportsCar()
    {
        inputElectricCar();
        cout << "Enter Top Speed: ";
        cin >> topSpeed;
    }
};

class Aircraft
{
public:
    int flightRange;

    void inputAircraft()
    {
        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }
};

class FlyingCar : public Car, public Aircraft
{
};

class Sedan : public Car
{
};

class SUV : public Car
{
};

int main()
{
    Vehicle::totalVehicles = 0;

    Car car;
    ElectricCar electric;
    SportsCar sports;
    Aircraft aircraft;
    FlyingCar flying;
    Sedan sedan;
    SUV suv;

    int choice = 0;

    while (choice != 9)
    {
        cout << "\n\nVEHICLE REGISTRY SYSTEM";
        cout << "\n1. Add Car";
        cout << "\n2. Add Electric Car";
        cout << "\n3. Add Sports Car";
        cout << "\n4. Add Aircraft";
        cout << "\n5. Add Flying Car";
        cout << "\n6. Add Sedan";
        cout << "\n7. Add SUV";
        cout << "\n8. Show Total Vehicles";
        cout << "\n9. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            car.inputCar();
            Vehicle::totalVehicles++;
            break;

        case 2:
            electric.inputElectricCar();
            Vehicle::totalVehicles++;
            break;

        case 3:
            sports.inputSportsCar();
            Vehicle::totalVehicles++;
            break;

        case 4:
            aircraft.inputAircraft();
            Vehicle::totalVehicles++;
            break;

        case 5:
            flying.inputCar();
            flying.inputAircraft();
            Vehicle::totalVehicles++;
            break;

        case 6:
            sedan.inputCar();
            Vehicle::totalVehicles++;
            break;

        case 7:
            suv.inputCar();
            Vehicle::totalVehicles++;
            break;

        case 8:
            cout << "\nTotal Vehicles Created: "
                 << Vehicle::totalVehicles;
            break;

        case 9:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }
    }

    return 0;
}
