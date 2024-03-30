#include <iostream>
#include <string>

using namespace std;

long repeatedString(string s, long n) {
    long count_a = 0;
    long len = s.length();

    // Count the number of 'a's in the given string
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'a') {
            count_a++;
        }
    }

    // Calculate how many times the string 's' is repeated completely
    long repeat_count = n / len;

    // Calculate the remaining characters after complete repetition
    long remaining_chars = n % len;

    // Count the number of 'a's in the remaining characters
    for (int i = 0; i < remaining_chars; ++i) {
        if (s[i] == 'a') {
            count_a++;
        }
    }

    // Total count of 'a's in the first 'n' characters
    return count_a + (repeat_count * count_a);
}

int main() {
    string s;
    long n;
    cout << "Enter the infinite string (lowercase English letters only): ";
    cin >> s;
    cout << "Enter the value of n: ";
    cin >> n;

    long result = repeatedString(s, n);
    cout << "Number of 'a's in the first " << n << " characters: " << result << endl;

    return 0;
}
