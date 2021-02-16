//
// Created by student on 4/30/20.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "model/Vehicle.h"
#include "model/Bicycle.h"
#include "model/Moped.h"
#include "model/Car.h"
#include "repositories/Repository.h"

class VehicleRepository : public Repository<Vehicle>
{
private:
    friend class VehicleManager;

public:
    VehicleRepository();
    virtual ~VehicleRepository();

};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
