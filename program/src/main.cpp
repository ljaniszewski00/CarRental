#include <iostream>
#include "model/Client.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"
#include "model/Bicycle.h"
#include "model/Car.h"
#include "model/Moped.h"
#include "utils.h"
#include "repositories/RentRepository.h"

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main()
{
    cout << endl;
    RentManagerPtr rentManager(new RentManager());
    ClientManagerPtr clientManager(new ClientManager());
    VehicleManagerPtr vehicleManager(new VehicleManager());
    Wypelnij(clientManager,vehicleManager,rentManager);
//    cout << clientManager->report();
//    cout << vehicleManager->report();
//
//
//    cout << "To co dodalem w mainie" << endl;
//
    AddressPtr address(new Address("Lodz","Widzewska","30"));
    clientManager->registerClient("Grzegorz", "Brzeczyszczykiewicz", "21425432", address);
    vehicleManager->registerMoped("TR24255",30,400);
//
//
//    cout << clientManager->getClient("21425432")->getClientInfo();
//
//
//    cout << "Teraz pora na koncowe findy" << endl;
//
//    RentPtr test1=rentManager->find([](RentPtr r){return r->get_client()->get_firstName()=="Patryk";});
//    RentPtr test2=rentManager->find([](RentPtr r){return r->get_client()->get_firstName()=="Szymon";});
//    RentPtr test3=rentManager->find([](RentPtr r){return r->get_client()->get_firstName()=="Grzegorz";});
//    cout << test1->get_client()->getClientInfo() << endl;
//    cout << test2->get_client()->getClientInfo() << endl;
//    cout << test3->get_client()->getClientInfo() << endl;


//    // Test prostej wyszukiwarki w repozytorium klienta przyjmujacej imie jako predykat
//    string imie;
//    cout << "Podaj imie: ";
//    cin >> imie;
//    FirstNamePredicate predicate1(imie);
//    list<ClientPtr> wynik1=clientManager->findAll<FirstNamePredicate>(predicate1);
//    cout << "Dane znalezionego klienta: " << endl;
//    cout << wynik1.front()->getClientInfo();
//    cout << wynik1.back()->getClientInfo();
//
//
//    // Test prostej wyszukiwarki w repozytorium klienta przyjmujacej nazwisko jako predykat
//    string nazwisko;
//    cout << "Podaj nazwisko: ";
//    cin >> nazwisko;
//    LastNamePredicate predicate2(nazwisko);
//    list<ClientPtr> wynik2=clientManager->findAll<LastNamePredicate>(predicate2);
//    cout << "Dane znalezionego klienta: " << endl;
//    cout << wynik2.front()->getClientInfo();
//    cout << wynik2.back()->getClientInfo();
//
//
//    // Test prostej wyszukiwarki w repozytorium klienta przyjmujacej pesel jako predykat
//    string pesel;
//    cout << "Podaj pesel: ";
//    cin >> pesel;
//    personalIDPredicate predicate3(pesel);
//    list<ClientPtr> wynik3=clientManager->findAll<personalIDPredicate>(predicate3);
//    cout << "Dane znalezionego klienta: " << endl;
//    cout << wynik3.front()->getClientInfo();
//    cout << wynik3.back()->getClientInfo();
//
//
//    // Test prostej wyszukiwarki w repozytorium pojazdu przyjmujacej plateNumber jako predykat
//    string nrtablicy;
//    cout << "Podaj nr tablicy: ";
//    cin >> nrtablicy;
//    plateNumberPredicate predicate4(nrtablicy);
//    list<VehiclePtr> wynik4=vehicleManager->findAll<plateNumberPredicate>(predicate4);
//    cout << "Dane znalezionego pojazdu: " << endl;
//    cout << wynik4.front()->getVehicleInfo();
//    cout << wynik4.back()->getVehicleInfo();
//
//
}
