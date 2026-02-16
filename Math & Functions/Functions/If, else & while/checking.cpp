#include <iostream>
using namespace std;

int main() {
    int n = 4;  // Number of rows
    int start = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << start + j;
        }
        cout << endl;
        start++;  // Increment start for the next row
    }

    return 0;
}