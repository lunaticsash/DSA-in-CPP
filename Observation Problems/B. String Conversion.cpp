#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    // Only one run => all characters are same
    // => cannot be balanced
    if (k == n - 1)
    {
        cout << -1 << '\n';
        return;
    }

    int runs = n - k;

    int zeros = n / 2;
    int ones = n - zeros;

    int zeroRuns = (runs + 1) / 2;
    int oneRuns = runs / 2;

    string ans;

    // Minimum characters required for the runs
    int extraZeros = zeros - zeroRuns;
    int extraOnes = ones - oneRuns;

    for (int i = 0; i < runs; i++)
    {
        if (i % 2 == 0)
        {
            // 0-run
            int len = 1;

            if (i == 0)
            {
                len += extraZeros;
            }

            ans += string(len, '0');
        }
        else
        {
            // 1-run
            int len = 1;

            if (i == 1)
            {
                len += extraOnes;
            }

            ans += string(len, '1');
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}