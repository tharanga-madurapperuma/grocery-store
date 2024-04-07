#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Store class, This will store all the details of stores fetch from the text file
class Store
{
private:
    string name;
    int squareFeet;
    string size;
    string address;
    string neighborhood;
    double latitude;
    double longitude;

public:
    // Constructor
    Store(string name, int squareFeet, string size, string address, string neighborhood, double latitude, double longitude)
        : name(name), squareFeet(squareFeet), size(size), address(address), neighborhood(neighborhood), latitude(latitude), longitude(longitude) {}

    // Accessor methods
    string getName() const { return name; }
    int getSquareFeet() const { return squareFeet; }
    string getSize() const { return size; }
    string getAddress() const { return address; }
    string getNeighborhood() const { return neighborhood; }
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
};

// This class for store data in neighborhood store details
class Neighborhood
{
private:
    string name;
    int numLargeStores;
    int numSmallStores;

public:
    // Constructor
    Neighborhood(string name) : name(name), numLargeStores(0), numSmallStores(0) {}

    // Methods to update counts
    void incrementLargeStore() { numLargeStores++; }
    void incrementSmallStore() { numSmallStores++; }

    // Accessor methods
    string getName() const { return name; }
    int getNumLargeStores() const { return numLargeStores; }
    int getNumSmallStores() const { return numSmallStores; }
};

// This function use for calculate the distance of two latitude, longitude points
double distance(double lat1, double lon1, double lat2, double lon2)
{
#define pi 3.14159265358979323846
    constexpr double earthRadius = 6371.0 * 0.621371; // Conversion to miles

    double latDiff = (lat2 - lat1) * (pi / 180.0);
    double lonDiff = (lon2 - lon1) * (pi / 180.0);

    double a = sin(latDiff / 2) * sin(latDiff / 2) +
               cos(lat1 * (pi / 180.0)) * cos(lat2 * (pi / 180.0)) *
                   sin(lonDiff / 2) * sin(lonDiff / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadius * c; // return the distance in miles
}

vector<Store> readStoresFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "\nError: Unable to open file " << filename;
        exit(1);
    }

    // Vector for enter data of Store objects
    vector<Store> stores;

    string name, squareFeetString, size, address, neighborhood, latitudeString, longitudeString;
    int squareFeet;
    double latitude, longitude;

    string line;

    // Loop for get all data line by line from the file and store into store object
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, squareFeetString, ',');
        getline(ss, size, ',');
        getline(ss, address, ',');
        getline(ss, neighborhood, ',');
        getline(ss, latitudeString, ',');
        getline(ss, longitudeString, ',');
        squareFeet = stoi(squareFeetString);
        latitude = stod(latitudeString);
        longitude = stod(longitudeString);

        stores.emplace_back(name, squareFeet, size, address, neighborhood, latitude, longitude);
    }
    file.close();
    return stores;
}

// After user choose 1 from the menu, this snippet will run
void displayGeneralInfo(const vector<Store> &stores)
{
    int totalStores = stores.size();
    int largeStores = count_if(stores.begin(), stores.end(), [](const Store &store)
                               { return store.getSize() == "Large"; });

    // Below variable stands for get the count of stores which have no square footages.
    int largeStoresNoSqaureFootage = count_if(stores.begin(), stores.end(), [](const Store &store)
                                              { return store.getSize() == "Large" && store.getSquareFeet() != NULL; });

    double totalSquareFeet = 0;
    for (const auto &store : stores)
    {
        if (store.getSquareFeet() != 0 && store.getSize() == "Large")
        {
            totalSquareFeet += store.getSquareFeet();
        }
    }
    double avgSquareFeet = largeStores == 0 ? 0 : totalSquareFeet / largeStoresNoSqaureFootage;

    // Display the results
    cout << "\nNumber of grocery stores: " << totalStores << endl;
    cout << "Number of large grocery stores: " << largeStores << endl;
    cout << "Average size of large grocery stores: " << avgSquareFeet;
}

// After user choose 2 from the menu, this snippet will run
void displayNeighborhoodCharts(const vector<Store> &stores)
{
    // Vector to store neighborhood objects
    vector<Neighborhood> neighborhoods;
    for (const auto &store : stores)
    {
        auto it = find_if(neighborhoods.begin(), neighborhoods.end(), [&](const Neighborhood &n)
                          { return n.getName() == store.getNeighborhood(); });
        if (it != neighborhoods.end())
        {
            if (store.getSize() == "Large")
            {
                it->incrementLargeStore();
            }
            else
            {
                it->incrementSmallStore();
            }
        }
        else
        {
            neighborhoods.emplace_back(store.getNeighborhood());
            if (store.getSize() == "Large")
            {
                neighborhoods.back().incrementLargeStore();
            }
            else
            {
                neighborhoods.back().incrementSmallStore();
            }
        }
    }

    // Soring
    sort(neighborhoods.begin(), neighborhoods.end(), [](const Neighborhood &a, const Neighborhood &b)
         {
            if (a.getNumLargeStores() + a.getNumSmallStores() == b.getNumLargeStores() + b.getNumSmallStores()) {
                return a.getName() < b.getName();
            }
            return (a.getNumLargeStores() + a.getNumSmallStores()) > (b.getNumLargeStores() + b.getNumSmallStores()); });

    // This for loop for display values
    for (const auto &neighborhood : neighborhoods)
    {
        cout << "\n";
        cout << neighborhood.getName();
        int num = neighborhood.getName().size();

        // loop for display spaces
        for (int i = 23; i > num; i--)
        {
            cout << " ";
        }

        for (int i = 0; i < neighborhood.getNumLargeStores(); ++i)
        {
            cout << "L";
        }
        for (int i = 0; i < neighborhood.getNumSmallStores(); ++i)
        {
            cout << "S";
        }
    }
}

// After user choose 3 from the menu, this snippet will run
void findClosestStores(const vector<Store> &stores)
{
    double latitude, longitude;
    cout << "\nEnter latitude: ";
    cin >> latitude;
    cout << "\nEnter longitude: ";
    cin >> longitude;

    // Take a large value as first value.
    // double minDistanceLarge = numeric_limits<double>::max();
    // double minDistance = numeric_limits<double>::max();
    double minDistance = 0;
    double largeDistance = 0;

    // Making store objects
    const Store *closestStore = nullptr;
    const Store *closestLargeStore = nullptr;

    for (const auto &store : stores)
    {
        double distanceHigh = distance(latitude, longitude, store.getLatitude(), store.getLongitude());

        if (distanceHigh >= minDistance)
        {
            minDistance = distanceHigh;
            largeDistance = distanceHigh;
            closestStore = &store;
            closestLargeStore = &store;
        }
    }

    // This loop stands for get the large distance store as an initial min distance
    for (const auto &store : stores)
    {
        double dist = distance(latitude, longitude, store.getLatitude(), store.getLongitude()); // Get the distance from destance function
        if (dist <= minDistance)
        {
            minDistance = dist;
            closestStore = &store;
        }

        if (store.getSize() == "Large" && dist <= largeDistance)
        {
            largeDistance = dist;
            closestLargeStore = &store;
        }
    }

    // Rounded to tenth point and get the distance
    minDistance = floor(minDistance * 10 + 0.5) / 10;
    largeDistance = floor(largeDistance * 10 + 0.5) / 10;

    // If the closest store is not a large store.
    if (closestStore != closestLargeStore)
    {
        if (minDistance > 0.5) // small store & food desert
        {
            if (largeDistance > 1) // Display nearest large store
            {
                cout << "\n\nThe closest store is " << minDistance << " miles away." << endl;
                cout << "  " << closestStore->getName() << " is at " << closestStore->getAddress() << endl;
                cout << "This location is a food desert." << endl;
                cout << "The closest large store is " << largeDistance << " miles away." << endl;
                cout << "  " << closestLargeStore->getName() << " is at " << closestLargeStore->getAddress() << endl;
                cout << "This location is a food desert.";
            }
            else
            {
                cout << "\n\nThe closest store is " << minDistance << " miles away." << endl;
                cout << "  " << closestStore->getName() << " is at " << closestStore->getAddress() << endl;
                cout << "This location is a food desert." << endl;
                cout << "The closest large store is " << largeDistance << " miles away." << endl;
                cout << "  " << closestLargeStore->getName() << " is at " << closestLargeStore->getAddress();
            }
        }
        else
        {
            if (largeDistance > 1)
            {
                cout << "\n\nThe closest store is " << minDistance << " miles away." << endl;
                cout << "  " << closestStore->getName() << " is at " << closestStore->getAddress() << endl;
                cout << "The closest large store is " << largeDistance << " miles away." << endl;
                cout << "  " << closestLargeStore->getName() << " is at " << closestLargeStore->getAddress() << endl;
                cout << "This location is a food desert.";
            }
            else
            {
                cout << "\n\nThe closest store is " << minDistance << " miles away." << endl;
                cout << "  " << closestStore->getName() << " is at " << closestStore->getAddress() << endl;
                cout << "The closest large store is " << largeDistance << " miles away." << endl;
                cout << "  " << closestLargeStore->getName() << " is at " << closestLargeStore->getAddress();
            }
        }
    }

    // If the closeststore is a large store
    else if (closestLargeStore == closestLargeStore)
    {
        if (minDistance > 1) // if closest and largest stores are the same
        {
            cout << "\n\nThe closest store is " << minDistance << " miles away." << endl;
            cout << "  " << closestLargeStore->getName() << " is at " << closestLargeStore->getAddress() << endl;
            cout << "That is a large store." << endl;
            cout << "This location is a food desert.";
        }
        else
        {
            cout << "\n\nThe closest store is " << minDistance << " miles away." << endl;
            cout << "  " << closestLargeStore->getName() << " is at " << closestLargeStore->getAddress() << endl;
            cout << "That is a large store.";
        }
    }
    else
    {
        cout << "\nNo stores found.";
    }
}

// After user choose 4 from the menu, this snippet will run
void searchStoreByName(const vector<Store> &stores)
{
    string searchTerm;
    cout << "\nEnter store to search for: ";
    cin.ignore();
    getline(cin, searchTerm);

    // Typecast the search value into Uppercase
    transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(),
              ::toupper);

    bool found = false;
    for (const auto &store : stores)
    {
        if (store.getName().find(searchTerm) != string::npos)
        {
            // Printg the searched value
            found = true;
            cout << "\n\nStore: " << store.getName() << endl;
            cout << "Address: " << store.getAddress() << endl;
            cout << "Community: " << store.getNeighborhood() << endl;
            cout << "Size: " << store.getSize() << endl;
            cout << "Square Feet: " << store.getSquareFeet();
        }
    }

    if (!found)
    {
        cout << "\nNo stores found." << endl;
    }
}

// MAIN FUNCTION RUNS HERE
int main()
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    // Vector for store Store objects
    vector<Store> stores = readStoresFromFile(filename);

    int choice;
    do
    {
        // Menu Printing
        cout << "\n\n  Select a menu option:";
        cout << "\n   1. Display general grocery stores information";
        cout << "\n   2. Display neighborhood charts";
        cout << "\n   3. Find closest stores";
        cout << "\n   4. Search for store by name";
        cout << "\n   5. Exit";
        cout << "\nYour choice: ";
        cin >> choice;

        // Switch case operation for check the user input number and perform the relevent operation
        switch (choice)
        {
        case 1:
            displayGeneralInfo(stores);
            break;
        case 2:
            displayNeighborhoodCharts(stores);
            break;
        case 3:
            findClosestStores(stores);
            break;
        case 4:
            searchStoreByName(stores);
            break;
        case 5:
            break;
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
