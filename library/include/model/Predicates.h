//
// Created by student on 5/20/20.
//

#ifndef CARRENTAL_PREDICATES_H
#define CARRENTAL_PREDICATES_H
#include "model/typedefs.h"
#include "model/Rent.h"
#include <regex>

class FirstNamePredicate {
private:
    std::string wzorzec;

public:
    explicit FirstNamePredicate(const std::string& wzorzec);
    bool operator()(const ClientPtr &ptr) const;
};


class LastNamePredicate{
private:
    std::string wzorzec;

public:
    explicit LastNamePredicate(const std::string& wzorzec);
    bool operator()(const ClientPtr &ptr) const;
};


class personalIDPredicate
{
private:
    std::string wzorzec;

public:
    explicit personalIDPredicate(const std::string& wzorzec);
    bool operator()(const ClientPtr &ptr) const;
};


class plateNumberPredicate
{
private:
    std::string wzorzec;

public:
    explicit plateNumberPredicate(const std::string &wzorzec);
    bool operator()(const VehiclePtr &ptr) const;
};

#endif //CARRENTAL_PREDICATES_H