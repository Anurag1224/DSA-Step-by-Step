// ============================================================================
// PROBLEM 4: Fibonacci in Triangle
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> fib;
    fib.push_back(1);
    fib.push_back(1);
    
    while (fib.size() < n * (n + 1) / 2) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << fib[idx++] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Combine Fibonacci with patterns.
Example (n=4):
1
1 1
2 3 5
8 13 21 34
*/
