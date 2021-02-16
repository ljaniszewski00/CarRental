//
// Created by student on 5/13/20.
//

#ifndef CARRENTAL_VEHICLEEXCEPTION_H
#define CARRENTAL_VEHICLEEXCEPTION_H
#include <stdexcept>

class VehicleException : public std::logic_error {
public:
    explicit VehicleException(const std::string& what);
    static const std::string exceptionBasePrice;
    static const std::string exceptionPlateNumber;
    static const std::string exceptionVehicleManagerFindDidNotBringAnyResults;
    static const std::string exceptionVehicleManagerFindAllDidNotBringAnyResults;
};


#endif //CARRENTAL_VEHICLEEXCEPTION_H
