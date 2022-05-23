#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);


    vector<string>::iterator itr = dests.begin();
    advance(itr, 1);
    sort(itr, dests.end());

    float lowest = computeDistance(me, dests[0], dests);

    vector<string> shortest = dests;

    do {
        float distance = computeDistance(me, dests[0], dests);
        if (distance < lowest) {
            lowest = distance;
            shortest = dests;
        }
        itr = dests.begin();
        advance(itr, 1);
    } while (next_permutation(itr, dests.end()));
 
    cout << "Minimum path has distance " << lowest << ": ";
    printRoute(shortest[0], shortest);

    return 0;
}

/**
 * @brief Computes distance in route
 * 
 * This method will compute the full distance of the cycle that starts at the 'start' parameter, goes to each of the cities in the dests vector IN ORDER, and ends back at the 'start' parameter.
 * 
 * @param &me Middle Earth object
 * @param start Starting city
 * @param dests Itinerary of cities to visit
 * @return Float distance between every sequential city in dests
 */
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
        float distance = me.getDistance(start, dests[1]);
        for (int i = 1; i < dests.size()-1; i++) {
            distance += me.getDistance(dests[i],dests[i+1]);
        }
        distance += me.getDistance(dests[dests.size()-1], start);
    return distance;
}

// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/**
 * @brief Prints full route
 * 
 * This method will print the entire route, starting and ending at the 'start' parameter.
 * 
 * @param start Starting city
 * @dests Itinerary of cities to visit
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    for (auto x : dests) {
        cout << x << "->";
    }
    cout << start << endl;
}