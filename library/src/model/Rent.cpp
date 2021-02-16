//
// Created by student on 4/10/20.
//

#include "model/Rent.h"



using namespace std;

Rent::Rent(VehiclePtr vehicle, ClientPtr client, pt::ptime &beginTime) : vehicle(vehicle), client(client), beginTime(beginTime)
{
    if (Rent::beginTime==pt::not_a_date_time)
    {
        this->beginTime=pt::second_clock::local_time();
    }
    endTime=pt::not_a_date_time;

    if (client == nullptr)
    {
        throw RentException(RentException::exceptionClientNullPtr);
    }

    if (vehicle == nullptr)
    {
        throw RentException(RentException::exceptionVehicleNullPtr);
    }
}

Rent::~Rent()
{
}

std::string Rent::getRentInfo()
{
    std::string stringID = to_string(Rent::ID);
    ostringstream sout;
    sout << "ID wypozyczenia: " << stringID << endl;
    sout << "Wypozyczony pojazd: " << vehicle->getVehicleInfo() << endl;
    sout << "Osoba wypozyczajaca: " << client->getClientInfo() << endl;
    sout << "Poczatek wypozyczenia: " << Rent::get_beginTime() << endl;
    sout << "Koniec wypozyczenia: " << Rent::get_endTime() << endl;
    sout << "Dlugosc okresu wypozyczenia (w dniach): " << Rent::getRentDays() << endl;
    sout << "Koszt wypozyczenia: " << Rent::get_rentCost() << endl;
    return sout.str();
}

const boost::uuids::uuid Rent::get_ID() const
{
    return Rent::ID;
}

VehiclePtr Rent::get_vehicle() const
{
    return vehicle;
}

ClientPtr Rent::get_client() const
{
    return client;
}

const pt::ptime &Rent::get_beginTime() const
{
    return beginTime;
}

const pt::ptime &Rent::get_endTime() const
{
    return endTime;
}

void Rent::endRent(pt::ptime& endtime)
{
    if (this->endTime==pt::not_a_date_time)
    {
        if (endTime.is_not_a_date_time())
        {
            this->endTime = pt::second_clock::local_time();
        }

        else if (endTime < beginTime)
        {
            throw RentException(RentException::exceptionRentEndTimeSmallerThanRentBeginTime);
        }

        else
        {
            this->endTime = endtime;
        }

        rentCost = getRentDays() * vehicle->get_basePrice();
    }
}

int Rent::getRentDays()
{
    if (endTime==pt::not_a_date_time)
    {
        return 0;
    }

    pt::time_period period(beginTime, endTime);

    if (period.length().minutes()<1 and period.length().hours()<1)
    {
        return 0;
    }

    int RentDays=(period.length().hours()/24)+1;
    return RentDays;
}


double Rent::get_rentCost() const
{
    return rentCost;
}


void Rent::set_ID(boost::uuids::uuid uuidID)
{
    Rent::ID=uuidID;
}





