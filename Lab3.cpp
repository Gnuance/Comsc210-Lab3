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
void OutputRestaurantHeader();
void OutputRestaurantInfo(const Restaurant &);

int main()
{
    // Array of testing data to be randomly assigned to restaurants
    const string NAME[10] = {"Pascals", "Giovanni's", "Leopold's", "The Artemis", "Burrito Shaq", "55 Ethiopian", "The Pizza Joint", "Family Spaghetti", "Dumpling Town", "Sizzling Sushi"};
    // Fake addresses compliments of ChatGPT. Should've asked it to create the names also, but I had fun coming up with names
    const string ADDRESS[10] = {"123 Maple Street", "456 Oak Avenue", "789 Pine Road", "101 Birch Lane", "202 Cedar Blvd", "303 Elm Street", "404 Willow Way", "505 Cherry Circle", "606 Aspen Drive", "707 Walnut Terrace"};
    // Spacing for output
    const int SPACING_LARGE = 25;
    const int SPACING_SMALL = 15;
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

    // Output header info to console
    OutputRestaurantHeader();

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

        Restaurants.push_back(r); // Add restaurant to vector
        OutputRestaurantInfo(r);
    }

    // Restaurants.push_back(CollectRestaurantInfo());

    
    // OutputRestaurantInfo(Restaurants.at(5));

    return 0;
}

// Output header for data
void OutputRestaurantHeader()
{
    cout << left << setw(SPACING_LARGE) << "NAME" << setw(SPACING_LARGE) << "ADDRESS" << setw(SPACING_LARGE) << "YEAR ESTABLISHED" << setw(SPACING_LARGE) << "CAPACITY" << setw(SPACING_SMALL) << "ACCEPTS RESERVATIONS" 
    << endl
    << string(100, '_')
    << endl;
};

// Output function to cout restaurant info in formatted form
void OutputRestaurantInfo(const Restaurant & r)
{
    string acceptingReservations = "";

    cout << left << setw(SPACING_LARGE) << r.name << setw(SPACING_LARGE) << r.address << setw(SPACING_LARGE) << r.yearEstablished << setw(SPACING_SMALL) << r.seatingCapacity;
    acceptingReservations = (r.acceptsReservations == 1) ? "Yes" : "No";
    cout << left << setw(SPACING_LARGE) << acceptingReservations << endl;
};

// Collects retaurant information from user
Restaurant CollectRestaurantInfo()
{
    Restaurant r;
    string userInput = "";

    cout << "Please enter restaurant name: ";
    getline(cin, r.name);
    cout << "Please enter restaurant address: ";
    getline(cin, r.address);
    cout << "Please enter year established: ";
    getline(cin, userInput);
    r.yearEstablished = stoi(userInput);
    cout << "Please enter the seating capacity: ";
    getline(cin, userInput);
    r.seatingCapacity = stoi(userInput);
    cout << "Does the restaurant accept reservations (Yes/No): ";
    getline(cin, userInput);
    cout << "";

    r.acceptsReservations = (userInput == "Yes") ? true : false;

    return r;
};