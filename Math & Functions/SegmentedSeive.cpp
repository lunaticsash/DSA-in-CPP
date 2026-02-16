#include <bits/stdc++.h>
using namespace std;

// Function to find all primes up to sqrt(R) using the normal sieve method
void simpleSieve(int limit, vector<int>& primes) {
    vector<bool> isPrime(limit + 1, true);
    
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i); // Storing small primes
        }
    }
}

// Function to apply the segmented sieve algorithm
void segmentedSieve(int L, int R) {
    int limit = sqrt(R);  // Get square root of R
    vector<int> primes;   // Store small primes up to sqrt(R)

    simpleSieve(limit, primes); // Step 1: Find small primes

    vector<bool> isPrime(R - L + 1, true); // Step 2: Mark all numbers in range [L, R] as prime initially

    // Step 3: Mark multiples of small primes
    int i = 0;
    while (i < primes.size()) { // Using normal while loop
        int p = primes[i];
        int start = max(p * p, (L + p - 1) / p * p);  // Find the first multiple of p in range

        for (int j = start; j <= R; j += p) {
            isPrime[j - L] = false; // Mark non-primes
        }
        i++;
    }

    // Step 4: Print remaining primes
    for (int i = 0; i < isPrime.size(); i++) {
        if (isPrime[i] && (i + L) > 1) {
            cout << (i + L) << " ";
        }
    }
    cout << endl;
}

int main() {
    int L = 10, R = 50;
    cout << "Primes between " << L << " and " << R << " are: ";
    segmentedSieve(L, R);
    return 0;
}
