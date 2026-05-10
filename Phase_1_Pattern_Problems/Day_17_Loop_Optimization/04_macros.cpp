// ============================================================================
// PROBLEM 4: Optimized Code with Macros
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define SPACES(n) FOR(i, n) cout << " ";
#define STARS(n) FOR(i, n) cout << "*";

int main() {
    int n;
    cin >> n;
    
    FOR(i, n) {
        SPACES(n - i - 1);
        STARS(2 * i + 1);
        cout << "\n";
    }
    
    return 0;
}

/*
Use macros for even shorter code.
Be careful: macros can make code harder to read if overused.
*/
