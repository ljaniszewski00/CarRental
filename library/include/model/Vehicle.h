//
// Created by student on 4/10/20.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include "model/typedefs.h"
#include "exceptions/VehicleException.h"



class Vehicle
{
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool isArchive;


public:

    //konstruktor z listą inicjalizacyjna
    Vehicle(const std::string &plateNumber, const unsigned int &basePrice);

    // destruktor
    virtual ~Vehicle();

    // metody/operacje
    virtual std::string getVehicleInfo();
    virtual unsigned int getActualRentalPrice()=0;

    // gettery/settery
    const std::string &get_plateNumber() const;
    const unsigned int &get_basePrice() const;
    const bool &get_isArchive() const;

    void set_plateNumber(const std::string &pN);
    void set_basePrice(const unsigned int &bP);
    void set_isArchive(const bool &archived);



};


#endif //CARRENTAL_VEHICLE_H
