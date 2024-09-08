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

Restaurant CollectRestaurantInfo();
void OutputRestaurantInfo(const Restaurant &);

int main()
{
    // Array of testing data to be randomly assigned to restaurants
    const string NAME[10] = {"Pascals", "Giovanni's", "Leopold's", "The Artemis", "Burrito Shaq", "55 Ethiopian", "The Pizza Joint", "Family Spaghetti", "Dumpling Town", "Sizzling Sushi"};
    // Fake addresses compliments of ChatGPT. Should've asked it to create the names also, but I had fun coming up with names
    const string ADDRESS[10] = {"123 Maple Street", "456 Oak Avenue", "789 Pine Road", "101 Birch Lane", "202 Cedar Blvd", "303 Elm Street", "404 Willow Way", "505 Cherry Circle", "606 Aspen Drive", "707 Walnut Terrace"};
    // Random number generators for creating data to populate vector of restaurants for testing
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 9);
    uniform_int_distribution<> dist1(1900, 2024);
    uniform_int_distribution<> dist2(15, 100);
    uniform_int_distribution<> dist3(0, 1);
    // Temp restaurant object
    Restaurant r;
    vector<Restaurant> Restaurants = {};

    // Loop to populate restaurant data and vector
    for (size_t i = 0; i < 5; i++)
    {
        r.name = NAME[dist(gen)];
        r.address = ADDRESS[dist(gen)];
        r.yearEstablished = dist1(gen);
        r.seatingCapacity = dist2(gen);
        if (dist3(gen) == 0)
        {
            r.acceptsReservations = false;
        }
        else
        {
            r.acceptsReservations = true;
        }

        Restaurants.push_back(r); // Output data after it's been created

        OutputRestaurantInfo(r);
    }

    Restaurants.push_back(CollectRestaurantInfo());

    return 0;
}

// Output function to cout restaurant info in formatted form
void OutputRestaurantInfo(const Restaurant & r)
{
    string acceptingReservations = "";

    cout << left << setw(25) << r.name << setw(25) << r.address << setw(6) << r.yearEstablished;
    acceptingReservations = (r.acceptsReservations == 0) ? "No" : "Yes";
    cout << left << setw(6) << acceptingReservations << endl;
};

// Collects retaurant information from user
Restaurant CollectRestaurantInfo()
{
    Restaurant r;
    string acceptsRes = "";

    cout << "Please enter restaurant name: ";
    getline(cin, r.name);
    cout << "Please enter restaurant address: ";
    getline(cin, r.address);
    cout << "Please enter year established: ";
    cin >> r.yearEstablished;
    cout << "Please enter the seating capacity: ";
    cin >> r.seatingCapacity;
    cout << "Does the restaurant accept reservations (Yes/No): ";
    getline(cin, acceptsRes);

    r.acceptsReservations = (acceptsRes == "Yes") ? true : false;

    return r;
};