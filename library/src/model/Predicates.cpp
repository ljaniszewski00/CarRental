//
// Created by student on 5/20/20.
//

#include "model/Predicates.h"

using namespace std;


FirstNamePredicate::FirstNamePredicate(const std::string &wzorzec) : wzorzec(wzorzec)
{
}


bool FirstNamePredicate::operator()(const ClientPtr &ptr) const
{
    regex wzorzec2{"\\w*"+wzorzec+"\\w*"};
    return regex_match(ptr->get_firstName(),wzorzec2);
}


LastNamePredicate::LastNamePredicate(const string &wzorzec) : wzorzec(wzorzec)
{
}


bool LastNamePredicate::operator()(const ClientPtr &ptr) const
{
    regex wzorzec2{"\\w*"+wzorzec+"\\w*"};
    return regex_match(ptr->get_lastName(),wzorzec2);
}


personalIDPredicate::personalIDPredicate(const string &wzorzec) : wzorzec(wzorzec)
{
}


bool personalIDPredicate::operator()(const ClientPtr &ptr) const
{
    regex wzorzec2{"\\w*"+wzorzec+"\\w*"};
    return regex_match(ptr->get_personalID(),wzorzec2);
}


plateNumberPredicate::plateNumberPredicate(const string &wzorzec) : wzorzec(wzorzec)
{
}


bool plateNumberPredicate::operator()(const VehiclePtr &ptr) const
{
    regex wzorzec2{"\\w*"+wzorzec+"\\w*"};
    return regex_match(ptr->get_plateNumber(),wzorzec2);
}