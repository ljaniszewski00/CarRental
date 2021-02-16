//
// Created by student on 5/13/20.
//

#ifndef CARRENTAL_RENTEXCEPTION_H
#define CARRENTAL_RENTEXCEPTION_H
#include <stdexcept>

class RentException : public std::logic_error {
public:
    explicit RentException(const std::string& what);
    static const std::string exceptionClientNullPtr;
    static const std::string exceptionVehicleNullPtr;
    static const std::string exceptionRentEndTimeSmallerThanRentBeginTime;
    static const std::string exceptionMaxVehiclesExceeded;
    static const std::string exceptionVehicleIsAlreadyRented;
    static const std::string exceptionVehicleIsNotRented;
    static const std::string exceptionRentManagerFindDidNotBringAnyResults;
    static const std::string exceptionRentManagerFindAllDidNotBringAnyResults;
};


#endif //CARRENTAL_RENTEXCEPTION_H
