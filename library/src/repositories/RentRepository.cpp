//
// Created by student on 4/29/20.
//

#include "repositories/RentRepository.h"

using namespace std;

RentRepository::RentRepository()
{
}

RentRepository::~RentRepository()
{
    for (list<RentPtr>::iterator iter = objectsRepository.begin(); iter != objectsRepository.end(); iter++)
    {
        (*iter)=nullptr;
    }
}



