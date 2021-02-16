//
// Created by student on 5/1/20.
//

#include "managers/RentManager.h"
#include <model/Predicates.h>

using namespace std;

RentPtr RentManager::makeRent(ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime)
{
    list<RentPtr> ClientRents=findAll([client](RentPtr r){return r->get_client()==client;});
    RentPtr VehicleCheck=find([vehicle](RentPtr r){return r->get_vehicle()==vehicle;});

    if (ClientRents.size()==client->get_maxVehicles())
    {
        throw RentException(RentException::exceptionMaxVehiclesExceeded);
    }

    else if (VehicleCheck!=nullptr)
    {
        throw RentException(RentException::exceptionVehicleIsAlreadyRented);
    }

    else{
        RentPtr newRent(new Rent(vehicle, client, beginTime));
        newRent->set_ID(GenerateRentRandomID());
        addCurrent(newRent);
        return newRent;
    }
}


void RentManager::cancelRent(VehiclePtr vehicle)
{
    RentPtr VehicleCheck=find([vehicle](RentPtr r){return r->get_vehicle()==vehicle;});
    pt::ptime endTime=pt::not_a_date_time;
    if (VehicleCheck != nullptr)
    {
        VehicleCheck->endRent(endTime);
        list<RentPtr>::const_iterator i;
        for (i = currentRentsList->begin(); i != currentRentsList->end(); i++)
        {
            if ((*i)->get_vehicle() == vehicle)
            {
                currentRentsList->repositoryRemove(*i);
                archiveRentsList->repositoryAdd(*i);
                break;
            }
        }
        checkClientRentBalance(VehicleCheck->get_client());
    }

    else
    {
        throw RentException(RentException::exceptionVehicleIsNotRented);
    }
}


void RentManager::checkClientRentBalance(ClientPtr client)
{
    list<RentPtr> ClientRents=findAll([client](RentPtr r){return r->get_client()==client;});
    int balance=0;
    list<RentPtr>::const_iterator i;
    for (i=ClientRents.begin();i!=ClientRents.end();i++)
    {
        balance=balance+(*i)->get_rentCost();
    }
    changeClientType(client, balance);
}


void RentManager::changeClientType(ClientPtr client, int sum) {
    ClientTypePtr bronze(new ClientBronze());
    ClientTypePtr silver(new ClientSilver());
    ClientTypePtr gold(new ClientGold());
    ClientTypePtr platinum(new ClientPlatinum());
    ClientTypePtr diamond(new ClientDiamond());

    if (client->get_maxVehicles()==1)
    {
        if(sum>=100)
        {
            client->set_clientType(bronze);
        }
    }
    else if (client->get_maxVehicles()==2)
    {
        if(sum>=200)
        {
            client->set_clientType(silver);
        }
    }
    else if (client->get_maxVehicles()==3)
    {
        if(sum>=400)
        {
            client->set_clientType(gold);
        }
    }
    else if (client->get_maxVehicles()==4)
    {
        if(sum>=800)
        {
            client->set_clientType(platinum);
        }
    }
    else if (client->get_maxVehicles()==5)
    {
        if(sum>=1600)
        {
            client->set_clientType(diamond);
        }
    }
}


list<RentPtr> RentManager::getAllClientRents(ClientPtr client)
{
    list<RentPtr> ClientTotalRents=findAll([client](RentPtr r){return r->get_client()==client;});
    return ClientTotalRents;
}


void RentManager::addCurrent(RentPtr r)
{
    currentRentsList->repositoryAdd(r);
}


void RentManager::addArchive(RentPtr r)
{
    archiveRentsList->repositoryAdd(r);
}



std::string RentManager::reportCurrentRents()
{
    ostringstream sout;
    sout << endl;
    for (list<RentPtr>::const_iterator iter = currentRentsList->begin(); iter != currentRentsList->end(); iter++)
    {
        sout << (*iter)->getRentInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


std::string RentManager::reportArchiveRents()
{
    ostringstream sout;
    sout << endl;
    for (list<RentPtr>::const_iterator iter = archiveRentsList->begin(); iter != archiveRentsList->end(); iter++)
    {
        sout << (*iter)->getRentInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


int RentManager::currentRentsSize()
{
    return currentRentsList->repositorySize();
}


int RentManager::archiveRentsSize()
{
    return archiveRentsList->repositorySize();
}


boost::uuids::uuid RentManager::GenerateRentRandomID()
{
    boost::uuids::random_generator gen;
    boost::uuids::uuid ID = gen();
    return ID;
}


std::list<RentPtr> RentManager::findAll(RentPredicate check)
{
    list<RentPtr> Searched;


    for (std::list<RentPtr>::const_iterator iter = currentRentsList->begin(); iter != currentRentsList->end(); iter++)
    {
        if (check(*iter))
            Searched.push_back(*iter);
    }

    for (std::list<RentPtr>::const_iterator iter = archiveRentsList->begin(); iter != archiveRentsList->end(); iter++)
    {
        if (check(*iter))
            Searched.push_back(*iter);
    }

    return Searched;

}


RentPtr RentManager::find(RentPredicate check)
{
    for (std::list<RentPtr>::const_iterator iter = currentRentsList->begin(); iter != currentRentsList->end(); iter++)
    {
        if(check(*iter)==1)
        {
            return *iter;
        }
    }

    for (std::list<RentPtr>::const_iterator iter = archiveRentsList->begin(); iter != archiveRentsList->end(); iter++)
    {
        if(check(*iter)==1)
        {
            return *iter;
        }
    }

    return nullptr;
}


