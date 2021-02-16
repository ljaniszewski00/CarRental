//
// Created by student on 5/1/20.
//

#include "managers/VehicleManager.h"
#include <iostream>

using namespace std;


VehiclePtr VehicleManager::registerBicycle(string plateNumber, int basePrice)
{
    plateNumberPredicate predicate(plateNumber);
    VehiclePtr wsk=find<plateNumberPredicate>(predicate);

    if (wsk != nullptr)
    {
        return wsk;
    }

    else{
        VehiclePtr newBicycle(new Bicycle(plateNumber, basePrice));
        add(newBicycle);
        return newBicycle;
    }
}


VehiclePtr VehicleManager::registerMoped(string plateNumber, int basePrice, int engineDisplacement)
{
    plateNumberPredicate predicate(plateNumber);
    VehiclePtr wsk=find<plateNumberPredicate>(predicate);

    if (wsk != nullptr)
    {
        return wsk;
    }

    else {
        VehiclePtr newMoped(new Moped(plateNumber, basePrice,engineDisplacement));
        add(newMoped);
        return newMoped;
    }
}


VehiclePtr VehicleManager::registerCar(string plateNumber, int basePrice, int engineDisplacement, Car::segmentType segmentType)
{
    plateNumberPredicate predicate(plateNumber);
    VehiclePtr wsk=find<plateNumberPredicate>(predicate);

    if (wsk != nullptr)
    {
        return wsk;
    }

    else {
        VehiclePtr newCar(new Car(plateNumber, basePrice,engineDisplacement,segmentType));
        add(newCar);
        return newCar;
    }

}


void VehicleManager::unregisterVehicle(VehiclePtr vehicle)
{
    if (vehicle->get_isArchive())
        cout << "Pojazd jest juz odrejestrowany"<<endl;
    else
        vehicle->set_isArchive(1);
}


VehiclePtr VehicleManager::getVehicle(string plateNumber)
{
    plateNumberPredicate predicate(plateNumber);
    VehiclePtr wsk=find<plateNumberPredicate>(predicate);
    return wsk;
}


void VehicleManager::add(VehiclePtr vehicle)
{
    vehicleManagerRepositoryList->repositoryAdd(vehicle);
}

std::string VehicleManager::report()
{
    ostringstream sout;
    sout << endl;
    for (list<VehiclePtr>::const_iterator iter = vehicleManagerRepositoryList->begin(); iter != vehicleManagerRepositoryList->end(); iter++)
    {
        sout << (*iter)->getVehicleInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


unsigned int VehicleManager::size()
{
    return vehicleManagerRepositoryList->repositorySize();
}
