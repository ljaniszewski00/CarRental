//
// Created by student on 27.03.2020.
//

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include <sstream>

class Rent;

using namespace std;


Client::Client(const string &fN, const string &lN, const string &pID,  AddressPtr address) : firstName(fN), lastName(lN), personalID(pID), address(address)
{
    clientType=std::make_shared<ClientDefault>();

    if (firstName.empty())
    {
        throw ClientException(ClientException::exceptionFirstName);
    }
    if (lastName.empty())
    {
        throw ClientException(ClientException::exceptionLastName);
    }
    if (personalID.empty())
    {
        throw ClientException(ClientException::exceptionPersonalID);
    }
    if (address == nullptr || address->get_cityName().empty() || address->get_streetName().empty() || address->get_streetNumber().empty())
    {
        throw ClientException(ClientException::exceptionAddress);
    }
    if (clientType == nullptr)
    {
        throw ClientException(ClientException::exceptionClientType);
    }
}

Client::~Client()
{
}

string Client::getClientInfo()
{
     ostringstream sout;
     sout << endl;
     sout << "Informacje o kliencie: " << endl;
     sout << Client::firstName << " " << Client::lastName << "  " << Client::personalID << endl;
     sout << address->getAddressInfo() << endl;
     return sout.str();
}


std::string Client::getFullClientInfo()
{
    ostringstream sout;
    sout << getClientInfo() << endl;
    return sout.str();
}


const string &Client::get_firstName() const
{
    return Client::firstName;
}

const string &Client::get_lastName() const
{
    return Client::lastName;
}

const string &Client::get_personalID() const
{
    return Client::personalID;
}

AddressPtr Client::get_adres() const
{
    return Client::address;
}


void Client::set_firstName(const string &I)
{
    if (I.empty())
    {
        throw ClientException(ClientException::exceptionFirstName);
    }
    else
    {
        Client::firstName = I;
    }

}

void Client::set_lastName(const string &J)
{
    if (J.empty())
    {
        throw ClientException(ClientException::exceptionLastName);
    }
    else
    {
        Client::lastName = J;
    }
}

void Client::set_adres(AddressPtr adres)
{
    if (adres==nullptr)
    {
        throw ClientException(ClientException::exceptionAddress);
    }
    else{
        Client::address=adres;
    }
}


const ClientTypePtr &Client::get_clientType() const
{
    return Client::clientType;
}


void Client::set_clientType(ClientTypePtr clienttype)
{
    if (clienttype==nullptr)
    {
        throw ClientException(ClientException::exceptionClientType);
    }
    else{
        Client::clientType=clienttype;
    }
}


const bool &Client::get_isArchive() const
{
    return Client::isArchive;
}


void Client::set_isArchive(const bool &archived)
{
    Client::isArchive=archived;
}


unsigned long int Client::get_maxVehicles() const
{
    return this->clientType->getMaxVehicles();
}
