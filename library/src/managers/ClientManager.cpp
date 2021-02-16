//
// Created by student on 5/1/20.
//

#include "managers/ClientManager.h"

using namespace std;

ClientPtr ClientManager::registerClient(std::string firstName, std::string lastName, std::string personalID, AddressPtr address)
{
    personalIDPredicate predicate(personalID);
    ClientPtr Check=find<personalIDPredicate>(predicate);
    if (Check != nullptr)
    {
        return Check;
    }
    else if (address == nullptr)
    {
        throw ClientException(ClientException::exceptionAddress);
    }
    else{
        ClientPtr newClient(new Client(firstName,lastName,personalID,address));
        add(newClient);
        return newClient;
    }
}


void ClientManager::unregisterClient(ClientPtr client)
{
    if (client->get_isArchive()==1)
    {
        cout << "Klient zostal juz odrejestrowany."<<endl;
    }

    client->set_isArchive(true);
}


ClientPtr ClientManager::getClient(string personalID)
{
    personalIDPredicate predicate(personalID);
    ClientPtr Check=find<personalIDPredicate>(predicate);
    return Check;
}


void ClientManager::add(ClientPtr client)
{
    clientManagerRepositoryList->repositoryAdd(client);
}

std::string ClientManager::report()
{
    ostringstream sout;
    sout << endl;
    for (list<ClientPtr>::const_iterator iter = clientManagerRepositoryList->begin(); iter != clientManagerRepositoryList->end(); iter++)
    {
        sout << (*iter)->getClientInfo() << endl;
    }
    return sout.str();
}


unsigned int ClientManager::size()
{
    return clientManagerRepositoryList->repositorySize();
}
