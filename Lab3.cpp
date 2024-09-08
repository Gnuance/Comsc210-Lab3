/*
Lab3 (Restaurant) - Create a struct to hold restaurant data with 5 attributes. Create a function to collect user input and return it to program
  and a function that receives restaurant objects and outputs to consol.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>

using namespace std;

// Restaurant struct
struct Restaurant
{
    string name;
    string address;
    int yearEstablished;
    int seatingCapacity;
    bool acceptsReservations;
};

int main()
{
    random_device rd;

    return 0;
}

// Collects retaurant information from user
Restaurant CollectRestaurantInfo()
{
    Restaurant r;
    string acceptsRes = "";

    cout << "Please enter restaurant name: ";
    cin >> r.name;
    cout << "Please enter restaurant address: ";
    cin >> r.address;
    cout << "Please enter year established: ";
    cin >> r.yearEstablished;
    cout << "Please enter the seating capacity: ";
    cin >> r.seatingCapacity;
    cout << "Does the restaurant accept reservations (Yes/No): ";
    cin >> acceptsRes;

    r.acceptsReservations = (acceptsRes == "Yes") ? true : false;

    return r;
};

void OutputRestaurantInfo() {



};
