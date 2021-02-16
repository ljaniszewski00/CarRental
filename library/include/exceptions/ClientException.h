//
// Created by student on 5/13/20.
//

#ifndef CARRENTAL_CLIENTEXCEPTION_H
#define CARRENTAL_CLIENTEXCEPTION_H
#include <stdexcept>

class ClientException : public std::logic_error {
public:
    explicit ClientException(const std::string& what);
    static const std::string exceptionFirstName;
    static const std::string exceptionLastName;
    static const std::string exceptionPersonalID;
    static const std::string exceptionAddress;
    static const std::string exceptionClientType;
    static const std::string exceptionClientManagerFindDidNotBringAnyResults;
    static const std::string exceptionClientManagerFindAllDidNotBringAnyResults;
};


#endif //CARRENTAL_CLIENTEXCEPTION_H
