#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int equalStacks(vector<int>& h1, vector<int>& h2, vector<int>& h3) {
    int sum1 = accumulate(h1.begin(), h1.end(), 0);
    int sum2 = accumulate(h2.begin(), h2.end(), 0);
    int sum3 = accumulate(h3.begin(), h3.end(), 0);

    while (!(sum1 == sum2 && sum2 == sum3)) {
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1.front();
            h1.erase(h1.begin());
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2.front();
            h2.erase(h2.begin());
        } else {
            sum3 -= h3.front();
            h3.erase(h3.begin());
        }
    }
    return sum1;
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> h1(n1), h2(n2), h3(n3);

    for (int i = 0; i < n1; i++)
        cin >> h1[i];

    for (int i = 0; i < n2; i++)
        cin >> h2[i];

    for (int i = 0; i < n3; i++)
        cin >> h3[i];

    int result = equalStacks(h1, h2, h3);

    cout << "Maximum possible common height: " << result << endl;

    return 0;
}
