//
// Created by student on 5/13/20.
//

#include "exceptions/VehicleException.h"

using namespace std;

VehicleException::VehicleException(const string& what) : logic_error(what)
{}

const string VehicleException::exceptionBasePrice = "NIEPRAWIDLOWA CENA BAZOWA POJAZDU";
const string VehicleException::exceptionPlateNumber = "NIEPRAWIDLOWY NUMER REJESTRACYJNY POJAZDU";
const string VehicleException::exceptionVehicleManagerFindDidNotBringAnyResults = "METODA FIND KLASY VEHICLE MANAGER NIE ZNALAZLA ZADNYCH OBIEKTOW PO PODANYM PREDYKACIE";
const string VehicleException::exceptionVehicleManagerFindAllDidNotBringAnyResults = "METODA FINDALL KLASY VEHICLE MANAGER NIE ZNALAZLA ZADNYCH OBIEKTOW PO PODANYM PREDYKACIE";