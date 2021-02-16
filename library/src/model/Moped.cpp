//
// Created by student on 4/29/20.
//

#include "model/Moped.h"

using namespace std;

Moped::Moped(const std::string &plateNumber, const unsigned int &basePrice, const int engineDisplacement) : MotorVehicle(plateNumber, basePrice, engineDisplacement)
{
}

Moped::~Moped()
{
}

unsigned int Moped::getActualRentalPrice()
{
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getVehicleInfo()
{
    ostringstream sout;
    sout << "Typ pojazdu: motorower" << endl;
    sout << MotorVehicle::getVehicleInfo() << endl;
    return sout.str();
}
