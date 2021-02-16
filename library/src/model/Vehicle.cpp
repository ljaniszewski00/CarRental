//
// Created by student on 4/10/20.
//

#include <iostream>
#include "model/Vehicle.h"
#include <sstream>

using namespace std;

Vehicle::Vehicle(const string &pN, const unsigned int &bP) : plateNumber(pN), basePrice(bP)
{
    if (plateNumber.empty())
    {
        throw VehicleException(VehicleException::exceptionPlateNumber);
    }
}

Vehicle::~Vehicle()
{
}


std::string Vehicle::getVehicleInfo()
{
    ostringstream sout;
    sout << "Numer rejestracyjny pojazdu: " << Vehicle::plateNumber << endl;
    sout << "Cena za 1 dobe wypozyczenia: " << Vehicle::basePrice << endl;
    return sout.str();
}

const std::string &Vehicle::get_plateNumber() const {
    return plateNumber;
}

const unsigned int &Vehicle::get_basePrice() const {
    return basePrice;
}


void Vehicle::set_plateNumber(const string &pN)
{
    if (pN.empty())
    {
        throw VehicleException(VehicleException::exceptionPlateNumber);
    }
    else
    {
        Vehicle::plateNumber = pN;
    }

}

void Vehicle::set_basePrice(const unsigned int &bP)
{

        Vehicle::basePrice = bP;

}


void Vehicle::set_isArchive(const bool &archived)
{
    Vehicle::isArchive=archived;
}


const bool &Vehicle::get_isArchive() const
{
    return Vehicle::isArchive;
}

