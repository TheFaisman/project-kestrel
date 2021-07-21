#include "../std_lib_facilities.h"

/*
    Read a sequence of double values into a vector. Think of each value as the distance
    between two cities along a given route. Compute and print the total distance (sum of
    all distances). Find and print the smallest and greatest distance between two neighboring
    cities. Find and print the mean distance between two neighboring cities.
*/

int main() {
    cout << "Provide a sequence of distances (in KM) between two cities along a given route.\n";
    vector<double> distances;

    for (double temp_val; cin >> temp_val;) {
        distances.push_back(temp_val);
    }

    double min_distance = distances[0];
    double max_distance = distances[0];
    double total_distance = 0;
    for (double temp_val : distances) {
        if (temp_val <= min_distance) { min_distance = temp_val; }
        if (temp_val >= max_distance) { max_distance = temp_val; }
        total_distance += temp_val; 
    }
    double mean_distance = total_distance / distances.size();

    cout << endl;
    cout << "Total distance: " << total_distance << endl;
    cout << "Minimum distance between two cities: " << min_distance << endl;
    cout << "Maximum distance between two cities: " << max_distance << endl;
    cout << "Average distance: " << mean_distance << endl;

    return 0;
}