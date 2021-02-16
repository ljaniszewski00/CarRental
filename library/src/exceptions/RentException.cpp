//
// Created by student on 5/13/20.
//

#include "exceptions/RentException.h"

using namespace std;

RentException::RentException(const string& what) : logic_error(what)
{
}

const string RentException::exceptionClientNullPtr = "NIEPRAWIDLOWY KLIENT (NULL)";
const string RentException::exceptionVehicleNullPtr = "NIEPRAWIDLOWY POJAZD (NULL)";
const string RentException::exceptionRentEndTimeSmallerThanRentBeginTime = "PODANO NIEPRAWIDLOWY CZAS: CZAS ZAKONCZENIA WYPOZYCZENIA NIE MOZE BYC WCZESNIEJSZY NIZ CZAS ROZPOCZECIA WYPOZYCZENIA";
const string RentException::exceptionMaxVehiclesExceeded = "KLIENT MA JUZ ZAREZERWOWANA MAKSYMALNA DOPUSZCZALNA LICZBE POJAZDOW";
const string RentException::exceptionVehicleIsAlreadyRented = "POJAZD, KTOREGO REZERWACJI PROBOUJESZ DOKONAC, JEST JUZ WYPOZYCZONY";
const string RentException::exceptionVehicleIsNotRented = "POJAZD, KTOREGO REZERWACJE PROBUJESZ ANULOWAC, NIE JEST WYPOZYCZONY";
const string RentException::exceptionRentManagerFindDidNotBringAnyResults = "METODA FIND KLASY RENT MANAGER NIE ZNALAZLA ZADNYCH OBIEKTOW PO PODANYM PREDYKACIE";
const string RentException::exceptionRentManagerFindAllDidNotBringAnyResults = "METODA FINDALL KLASY RENT MANAGER NIE ZNALAZLA ZADNYCH OBIEKTOW PO PODANYM PREDYKACIE";