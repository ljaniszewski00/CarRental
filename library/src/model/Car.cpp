//
// Created by student on 4/29/20.
//

#include "model/Car.h"

using namespace std;

Car::Car(const string &plateNumber, const unsigned int &basePrice, const int engineDisplacement, segmentType segment) : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment)
{
}

Car::~Car()
{
}

std::string Car::getVehicleInfo()
{
    ostringstream sout;
    sout << endl;
    sout << "Typ pojazdu: samochod " << endl;
    sout << MotorVehicle::getVehicleInfo();
    sout << "Auto klasy: ";
    switch (segment)
    {
        case A:
            sout<<"A";
            break;
        case B:
            sout<<"B";
            break;
        case C:
            sout<<"C";
            break;
        case D:
            sout<<"D";
            break;
        case E:
            sout<<"E";
            break;
    }
    sout << endl;
    return sout.str();
}

unsigned int Car::getActualRentalPrice()
{
    switch (segment)
    {
        case A:
            return MotorVehicle::getActualRentalPrice();
            break;
        case B:
            return 1.1*MotorVehicle::getActualRentalPrice();
            break;
        case C:
            return 1.2*MotorVehicle::getActualRentalPrice();
            break;
        case D:
            return 1.3*MotorVehicle::getActualRentalPrice();
            break;
        case E:
            return 1.5*MotorVehicle::getActualRentalPrice();
            break;
    }

    return 0;
}

Car::segmentType Car::getSegment() const
{
    return segment;
}

void Car::setSegment(Car::segmentType sgment)
{
    Car::segment = sgment;
}

