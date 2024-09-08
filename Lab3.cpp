/*
Lab3 (Restaurant) - Create a struct to hold restaurant data with 5 attributes. Create a function to collect user input and return it to program
  and a function that receives restaurant objects and outputs to consol.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <random>
#include <format> // Format() and fmt() not working for me, so I'm using stringstream instead

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

    return r;
};
