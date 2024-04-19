#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Function to calculate the total travel distance for the current permutation of cities
int calculateDistance(int n, vector<vector<int>>& distanceMatrix, vector<int>& cities) {
    int totalDistance = 0;
    for (int i = 0; i < n - 1; i++) {
        totalDistance += distanceMatrix[cities[i]][cities[i + 1]];
    }
    // Adding the distance to return to the starting city
    totalDistance += distanceMatrix[cities[n - 1]][cities[0]];
    return totalDistance;
}

// Function to find the shortest path using a naive permutation-based approach
int tspNaive(int n, vector<vector<int>>& distanceMatrix) {
    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cities[i] = i; // Initialize cities with indices 0 to n-1
    }

    int minPathDistance = numeric_limits<int>::max();

    // Generate all permutations of cities, calculate the travel distance for each
    do {
        int currentDistance = calculateDistance(n, distanceMatrix, cities);
        minPathDistance = min(minPathDistance, currentDistance);
    } while (next_permutation(cities.begin(), cities.end()));

    return minPathDistance;
}

int main() {
    // Input number of cities and the distance matrix
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> distanceMatrix(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distanceMatrix[i][j];
        }
    }

    // Calculate the minimum path using the naive TSP approach
    int minPath = tspNaive(n, distanceMatrix);
    cout << "The minimum travel distance is: " << minPath << endl;

    return 0;
}
