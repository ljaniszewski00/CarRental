//
// Created by student on 4/30/20.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include "repositories/Repository.h"

class ClientRepository : public Repository<Client>
{
public:
    ClientRepository();
    virtual ~ClientRepository();

};
#endif //CARRENTAL_CLIENTREPOSITORY_H
