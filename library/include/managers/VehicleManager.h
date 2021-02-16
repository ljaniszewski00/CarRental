//
// Created by student on 5/1/20.
//

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include <model/Vehicle.h>
#include <repositories/VehicleRepository.h>
#include <model/Car.h>
#include <model/typedefs.h>
#include <model/Bicycle.h>
#include <model/Moped.h>
#include <model/Predicates.h>

class VehicleManager{
private:
    VehicleRepositoryPtr vehicleManagerRepositoryList=std::make_shared<VehicleRepository>();

public:
    VehiclePtr registerBicycle(std::string plateNumber, int basePrice);
    VehiclePtr registerMoped(std::string plateNumber, int basePrice, int engineDisplacement);
    VehiclePtr registerCar(std::string plateNumber, int basePrice, int engineDisplacement, Car::segmentType segmentType);
    void unregisterVehicle(VehiclePtr vehicle);
    VehiclePtr getVehicle(std::string plateNumber);

    void add(VehiclePtr);
    template <class P> std::list<VehiclePtr> findAll(const P &predicate);
    template <class P> VehiclePtr find(const P &predicate);
    std::string report();
    unsigned int size();

};

template <class P> std::list<VehiclePtr> VehicleManager::findAll(const P &predicate)
{
    std::list<VehiclePtr> Searched;

    for (std::list<VehiclePtr>::const_iterator iter = vehicleManagerRepositoryList->begin(); iter != vehicleManagerRepositoryList->end(); iter++)
    {
        if(predicate(*iter)==1)
        {
            Searched.push_back(*iter);
        }

    }

    return Searched;
}


template <class P> VehiclePtr VehicleManager::find(const P &predicate)
{
    for (std::list<VehiclePtr>::const_iterator iter = vehicleManagerRepositoryList->begin(); iter != vehicleManagerRepositoryList->end(); iter++)
    {
        if(predicate(*iter)==1)
        {
            return *iter;
        }

    }

    return nullptr;
}

#endif //CARRENTAL_VEHICLEMANAGER_H
