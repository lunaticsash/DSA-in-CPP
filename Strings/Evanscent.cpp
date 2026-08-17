#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Number of runs in original string
        int runs = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1])
                runs++;
        }

        int reduction = 0;

        for (int i = 1; i < n - 1; i++) {

            // a b a
            // Deleting b merges two runs
            if (s[i - 1] == s[i + 1] &&
                s[i] != s[i - 1]) {

                reduction = 2;
                break;
            }

            // a b c where all three are different
            // Deleting b reduces runs by 1
            if (s[i - 1] != s[i] &&
                s[i] != s[i + 1] &&
                s[i - 1] != s[i + 1]) {

                reduction = 1;
            }
        }

        cout << runs - reduction << '\n';
    }

    return 0;
}