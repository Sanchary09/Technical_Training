#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int d) {
    // Create a temporary array to store the rotated elements
    int temp[d];

    // Copy the first d elements to the temporary array
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Shift the remaining elements to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Copy the elements from the temporary array back to the original array
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

int main() {
    int n, d;
    cin >> n >> d;

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform left rotation
    leftRotate(arr, n, d);

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
