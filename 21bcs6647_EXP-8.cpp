#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute the maximum sum that does not exceed the capacity `k` using
// elements from the array `arr` an unlimited number of times.
int unboundedKnapsack(int k, vector<int>& arr) {
    vector<int> dp(k + 1, 0); // DP array for storing maximum sums up to k

    // Build the dp array from 1 to k
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] <= i) {
                // Update dp[i] if using arr[j] can increase the sum up to i
                dp[i] = max(dp[i], dp[i - arr[j]] + arr[j]);
            }
        }
    }
    return dp[k]; // The maximum sum we can achieve that is <= k
}

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k; // Read the size of the array and the target sum
        vector<int> arr(n); // Create the array of size n
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Input each element into the array
        }
        // Call the unboundedKnapsack function to get the result
        int result = unboundedKnapsack(k, arr);
        // Output the result
        cout << "Maximum sum: " << result << endl;
    }
    return 0;
}
