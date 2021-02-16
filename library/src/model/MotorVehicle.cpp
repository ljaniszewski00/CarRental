//
// Created by student on 4/29/20.
//

#include "model/MotorVehicle.h"

using namespace std;


MotorVehicle::MotorVehicle(const string &plateNumber, const unsigned int &basePrice, const int engineDisplacement) : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement)
{
}

MotorVehicle::~MotorVehicle()
{
}

int MotorVehicle::get_engineDisplacement() const
{
    return this->engineDisplacement;
}

void MotorVehicle::set_engineDisplacement(int eD)
{
    MotorVehicle::engineDisplacement = eD;
}

unsigned int MotorVehicle::getActualRentalPrice()
{
    if (engineDisplacement<1000)
    {
        return get_basePrice();
    }

    else if (engineDisplacement>=1000 and engineDisplacement<=2000)
    {
        return (0.0005*engineDisplacement+0.5)*get_basePrice();
    }

    else
    {
        return 1.5*get_basePrice();
    }
}


std::string MotorVehicle::getVehicleInfo()
{
    ostringstream sout;
    sout << Vehicle::getVehicleInfo();
    sout << "Pojemnosc silnika: " << MotorVehicle::engineDisplacement << "cm3" << endl;
    return sout.str();
}

