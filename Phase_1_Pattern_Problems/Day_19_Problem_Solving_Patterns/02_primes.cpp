// ============================================================================
// PROBLEM 2: Prime Numbers Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    int primes = 0;
    int num = 2;
    
    for (int i = 0; i < n && primes < n * (n + 1) / 2; i++) {
        for (int j = 0; j <= i; j++) {
            while (!isPrime(num)) num++;
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Combine prime checking with patterns.
Example (n=3):
2 3
5 7 11
13 17 19 23
*/
