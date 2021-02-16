//
// Created by student on 5/1/20.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H

#include <model/Client.h>
#include <repositories/ClientRepository.h>
#include <model/ClientType.h>
#include <model/Predicates.h>


class ClientManager{
private:
    ClientRepositoryPtr clientManagerRepositoryList=std::make_shared<ClientRepository>();

public:
    ClientPtr registerClient(std::string firstName, std::string lastName, std::string personalID, AddressPtr address);
    void unregisterClient(ClientPtr client);
    ClientPtr getClient(std::string personalID);
    void add(ClientPtr);
    template <class P> std::list<ClientPtr> findAll(const P &predicate) const;
    template <class P> ClientPtr find(const P &check);
    std::string report();
    unsigned int size();

};


template<class P> std::list<ClientPtr> ClientManager::findAll(const P &predicate) const
{
    std::list<ClientPtr> Searched;
    for (std::list<ClientPtr>::const_iterator iter = this->clientManagerRepositoryList->begin(),
                 end = this->clientManagerRepositoryList->end();
         iter != end;
         ++iter)
    {
        if(predicate(*iter))
        {
            Searched.push_back(*iter);
        }

    }

    return Searched;
}


template<class P> ClientPtr ClientManager::find(const P &predicate)
{
    for (std::list<ClientPtr>::const_iterator iter = this->clientManagerRepositoryList->begin(); iter != this->clientManagerRepositoryList->end(); ++iter)
    {
        if(predicate(*iter))
        {
            return *iter;
        }

    }

    return nullptr;
}

#endif //CARRENTAL_CLIENTMANAGER_H
