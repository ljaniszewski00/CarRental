//
// Created by student on 4/29/20.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include "repositories/Repository.h"

class RentRepository : public Repository<Rent>
{
private:
    friend class RentManager;

public:
    RentRepository();
    virtual ~RentRepository();

};

#endif //CARRENTAL_RENTREPOSITORY_H
