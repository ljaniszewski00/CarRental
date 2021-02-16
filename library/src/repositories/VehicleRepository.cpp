//
// Created by student on 4/30/20.
//

#include "repositories/VehicleRepository.h"

using namespace std;


VehicleRepository::VehicleRepository()
{

}


VehicleRepository::~VehicleRepository()
{
    for (list<VehiclePtr>::iterator iter = objectsRepository.begin(); iter != objectsRepository.end(); iter++)
    {
        (*iter)=nullptr;
    }
}



