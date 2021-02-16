//
// Created by student on 4/10/20.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "Client.h"
#include "Vehicle.h"
#include <string>
#include "model/typedefs.h"
#include <iostream>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time.hpp>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "exceptions/RentException.h"


namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


class Rent
{
private:
    boost::uuids::uuid ID;
    VehiclePtr vehicle;
    ClientPtr client;
    pt::ptime beginTime;
    pt::ptime endTime;
    double rentCost=0;

public:

    //konstruktor z listą inicjalizacyjna
    Rent(VehiclePtr vehicle, ClientPtr client, pt::ptime &beginTime);

    // destruktor
    virtual ~Rent();

    // metody/operacje
    std::string getRentInfo();
    int getRentDays();
    void endRent(pt::ptime&);

    // gettery/settery
    const boost::uuids::uuid get_ID() const;
    const pt::ptime &get_beginTime() const;
    const pt::ptime &get_endTime() const;
    VehiclePtr get_vehicle() const;
    ClientPtr get_client() const;
    double get_rentCost() const;
    void set_ID(boost::uuids::uuid uuidID);

};


#endif //CARRENTAL_RENT_H
