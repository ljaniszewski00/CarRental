//
// Created by student on 5/13/20.
//

#ifndef CARRENTAL_REPOSITORY_H
#define CARRENTAL_REPOSITORY_H
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include "model/typedefs.h"


template<class T> class Repository
{
protected:
    std::list<std::shared_ptr<T>> objectsRepository;

public:
    void repositoryAdd(std::shared_ptr<T>);
    void repositoryRemove(std::shared_ptr<T>);
    int repositorySize();
    std::_List_iterator<std::shared_ptr<T>> begin();
    std::_List_iterator<std::shared_ptr<T>> end();
};


template<class T> void Repository<T>::repositoryAdd(std::shared_ptr<T> ptr)
{
    objectsRepository.push_back(ptr);
}


template<class T> void Repository<T>::repositoryRemove(std::shared_ptr<T> ptr)
{
    objectsRepository.remove(ptr);
}


template<class T> int Repository<T>::repositorySize()
{
    return objectsRepository.size();
}


template<class T> std::_List_iterator<std::shared_ptr<T>> Repository<T>::begin()
{
    return objectsRepository.begin();
}


template<class T> std::_List_iterator<std::shared_ptr<T>> Repository<T>::end()
{
    return objectsRepository.end();
}

#endif //CARRENTAL_REPOSITORY_H
