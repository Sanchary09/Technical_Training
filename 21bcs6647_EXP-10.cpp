#include <iostream>
#include <vector>
using namespace std;

// Function to check if there is a subset with the given sum
bool isSubsetSum(vector<int>& set, int sum) {
    int n = set.size();
    // DP array to store the subset sum existence
    vector<bool> dp(sum + 1, false);
    dp[0] = true;  // There is always a subset with sum 0: the empty subset

    // Process each element in the set
    for (int num : set) {
        // Traverse from sum to the current number to prevent using the same element more than once
        for (int j = sum; j >= num; j--) {
            if (dp[j - num]) {
                dp[j] = true;
            }
        }
    }

    return dp[sum];
}

int main() {
    // Input the number of elements in the set
    int n, targetSum;
    cout << "Enter number of elements in the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    // Check if there's a subset with the given sum
    bool result = isSubsetSum(set, targetSum);
    if (result) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}
