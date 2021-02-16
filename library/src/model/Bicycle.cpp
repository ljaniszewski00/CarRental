//
// Created by student on 4/29/20.
//

#include "model/Bicycle.h"

using namespace std;

Bicycle::Bicycle(const string &plateNumber, const unsigned int &basePrice) : Vehicle(plateNumber, basePrice)
{
}

Bicycle::~Bicycle()
{
}

std::string Bicycle::getVehicleInfo()
{
    ostringstream sout;
    sout << "Typ pojazdu: rower" << endl;
    sout << Vehicle::getVehicleInfo() << endl;
    return sout.str();
}

unsigned int Bicycle::getActualRentalPrice() {
    return get_basePrice();
}


