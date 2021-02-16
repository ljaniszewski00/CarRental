//
// Created by student on 5/1/20.
//

#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include <model/Rent.h>
#include <repositories/RentRepository.h>
#include <exceptions/RentException.h>
#include <model/Predicates.h>
#include "managers/VehicleManager.h"
#include <iostream>


class RentManager{
private:
    RentRepositoryPtr currentRentsList=std::make_shared<RentRepository>();
    RentRepositoryPtr archiveRentsList=std::make_shared<RentRepository>();

public:
    RentPtr makeRent(ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime);
    void cancelRent(VehiclePtr vehicle);
    static boost::uuids::uuid GenerateRentRandomID();
    void checkClientRentBalance(ClientPtr client);
    void changeClientType(ClientPtr client, int sum);
    std::list<RentPtr> getAllClientRents(ClientPtr client);
    void addCurrent(RentPtr r);
    void addArchive(RentPtr r);
    std::list<RentPtr> findAll(RentPredicate check);
    RentPtr find(RentPredicate check);
    std::string reportCurrentRents();
    std::string reportArchiveRents();
    int currentRentsSize();
    int archiveRentsSize();
};


#endif //CARRENTAL_RENTMANAGER_H
