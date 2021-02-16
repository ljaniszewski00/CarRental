//
// Created by student on 5/13/20.
//

#include "exceptions/ClientException.h"

using namespace std;

ClientException::ClientException(const string &what) : logic_error(what)
{}

const string ClientException::exceptionFirstName = "NIEPRAWIDLOWE IMIE";
const string ClientException::exceptionLastName = "NIEPRAWIDLOWE NAZWISKO";
const string ClientException::exceptionPersonalID = "NIEPRAWIDLOWY PESEL";
const string ClientException::exceptionAddress = "NIEPRAWIDLOWY ADRES";
const string ClientException::exceptionClientType = "NIEPRAWIDLOWY TYP KLIENTA";
const string ClientException::exceptionClientManagerFindDidNotBringAnyResults = "METODA FIND KLASY CLIENT MANAGER NIE ZNALAZLA ZADNYCH OBIEKTOW PO PODANYM PREDYKACIE";
const string ClientException::exceptionClientManagerFindAllDidNotBringAnyResults = "METODA FINDALL KLASY CLIENT MANAGER NIE ZNALAZLA ZADNYCH OBIEKTOW PO PODANYM PREDYKACIE";