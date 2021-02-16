#include <boost/test/unit_test.hpp>
#include "utils.h"

using namespace std;

struct TestSuiteManagersFixture
        {
    const std::string testFirstName = "Patryk";
    const std::string testLastName = "Makowski";
    const std::string testPersonalID = "2321455";
    const std::string testPlateNumber = "WWE2345";
    const std::string testFirstNameV2 = "Szymon";
    const unsigned int testBasePrice = 500;
    pt::ptime testDefaultTime = pt::not_a_date_time;
    ClientPtr testClient;
    VehiclePtr testCar;
    AddressPtr testAddress;

    TestSuiteManagersFixture()
    {
        testAddress=std::make_shared<Address>("Warszawa","ulica","2");
        testClient=std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress);
        testCar=std::make_shared<Car>(testPlateNumber,testBasePrice,8000,Car::E);
    }

    ~TestSuiteManagersFixture()
    {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteManager, TestSuiteManagersFixture)

    BOOST_AUTO_TEST_CASE(RepositoryConstructorTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        RentManagerPtr testRentManager(new RentManager());
        Wypelnij(testClientManager,testVehicleManager,testRentManager);
        RentPtr test=testRentManager->find([](RentPtr r){return r->get_client()->get_firstName()=="Szymon";});
        BOOST_TEST_CHECK(test->get_client()->get_firstName()=="Szymon");
    }

    BOOST_AUTO_TEST_CASE(RepositoryFindAllTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        RentManagerPtr testRentManager(new RentManager());
        Wypelnij(testClientManager,testVehicleManager,testRentManager);
        FirstNamePredicate predicate(testFirstNameV2);
        std::list<ClientPtr> Searched = testClientManager->findAll<FirstNamePredicate>(predicate);
        BOOST_TEST_CHECK(Searched.front()->get_lastName() == "Blazynski");
        BOOST_TEST_CHECK(Searched.back()->get_lastName()=="Makowski");
    }

    BOOST_AUTO_TEST_CASE(RepositoryFindTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        RentManagerPtr testRentManager(new RentManager());
        Wypelnij(testClientManager,testVehicleManager,testRentManager);
        FirstNamePredicate check(testFirstNameV2);
        BOOST_TEST_CHECK(testClientManager->find(check)->get_firstName()==testFirstNameV2);
    }


    BOOST_AUTO_TEST_CASE(RegisterNewClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress)->getClientInfo()==testClient->getClientInfo());
        BOOST_TEST_CHECK(testClientManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterExistingClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        FirstNamePredicate check(testFirstName);
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress)==(testClientManager->find(check)));
        BOOST_TEST_CHECK(testClientManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterNullAddressTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testPersonalID,nullptr)==nullptr);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ClientPtr newClient=testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        testClientManager->unregisterClient(newClient);
        BOOST_TEST_CHECK(newClient->get_isArchive());
    }

    BOOST_AUTO_TEST_CASE(RegisterBicycleTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        BOOST_TEST_CHECK(testVehicleManager->registerBicycle(testPlateNumber,testBasePrice)->get_plateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterMopedTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        BOOST_TEST_CHECK(testVehicleManager->registerMoped(testPlateNumber,testBasePrice,200)->get_plateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterCarTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        BOOST_TEST_CHECK(testVehicleManager->registerCar(testPlateNumber,testBasePrice,200,Car::C)->get_plateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterVehicleNegativeTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        testVehicleManager->registerBicycle(testPlateNumber,testBasePrice);
        BOOST_TEST_CHECK(testVehicleManager->registerBicycle(testPlateNumber,testBasePrice)==nullptr);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RentVehiclePositiveTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        BOOST_TEST_CHECK(testRentManager->makeRent(testClient,testCar,testDefaultTime)->get_client()==testClient);
        BOOST_TEST_CHECK(testRentManager->currentRentsSize()==1);
    }

    BOOST_AUTO_TEST_CASE(RentVehicleNumberExceededMaxVehiclesPerClientTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        VehiclePtr newBicycle(new Bicycle("rower",40));
        testRentManager->makeRent(testClient,testCar,testDefaultTime);
        BOOST_TEST_CHECK(testRentManager->makeRent(testClient,newBicycle,testDefaultTime)==nullptr);
        BOOST_TEST_CHECK(testRentManager->currentRentsSize()==1);
        BOOST_TEST_CHECK(testRentManager->getAllClientRents(testClient).size()==1);
    }

    BOOST_AUTO_TEST_CASE(RentVehicleAlreadyRentedTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        ClientManagerPtr testClientManager(new ClientManager());
        ClientPtr newClient(new Client("Lukasz","Janiszewski","229898",testAddress));
        testRentManager->makeRent(testClient,testCar,testDefaultTime);
        BOOST_TEST_CHECK(testRentManager->makeRent(newClient,testCar,testDefaultTime)==nullptr);
    }

    BOOST_AUTO_TEST_CASE(ReturnVehicleTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        testRentManager->makeRent(testClient,testCar,testDefaultTime);
        testRentManager->cancelRent(testCar);
        BOOST_TEST_CHECK(testRentManager->archiveRentsSize()==1);
        BOOST_TEST_CHECK(testRentManager->currentRentsSize()==0);
    }

    BOOST_AUTO_TEST_CASE(ReturnVehicleTypeChangeTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        pt::ptime preminute = pt::ptime(gr::date(2020, 4, 17), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        testRentManager->makeRent(testClient,testCar,preminute);
        testRentManager->cancelRent(testCar);
        BOOST_TEST_CHECK(testClient->get_maxVehicles()==2);
    }

    BOOST_AUTO_TEST_CASE(MultipleVehiclesBalanceCheckTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        ClientTypePtr bronze(new ClientBronze());
        testClient->set_clientType(bronze);
        VehiclePtr newBicycle1(new Bicycle("rower1",70));
        VehiclePtr newBicycle2(new Bicycle("rower2",80));
        pt::ptime preminute = pt::ptime(gr::date(2020, 5, 16), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        testRentManager->makeRent(testClient,newBicycle1,preminute);
        testRentManager->makeRent(testClient,newBicycle2,preminute);
        testRentManager->cancelRent(newBicycle1);
        testRentManager->cancelRent(newBicycle2);
        BOOST_TEST_CHECK(testClient->get_maxVehicles()==3);
    }

    BOOST_AUTO_TEST_CASE(GetAllClientRentsTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        ClientTypePtr gold(new ClientGold());
        testClient->set_clientType(gold);
        VehiclePtr newBicycle1(new Bicycle("rower1",70));
        VehiclePtr newBicycle2(new Bicycle("rower2",80));
        pt::ptime preminute = pt::ptime(gr::date(2020, 5, 5), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        RentPtr rent1=testRentManager->makeRent(testClient,newBicycle1,preminute);
        RentPtr rent2=testRentManager->makeRent(testClient,newBicycle2,preminute);
        testRentManager->cancelRent(newBicycle1);
        std::list<RentPtr> testResult=testRentManager->getAllClientRents(testClient);
        BOOST_TEST_CHECK(testResult.front()==rent2);
        BOOST_TEST_CHECK(testResult.back()==rent1);
        BOOST_TEST_CHECK(testResult.size()==2);
    }

BOOST_AUTO_TEST_SUITE_END()