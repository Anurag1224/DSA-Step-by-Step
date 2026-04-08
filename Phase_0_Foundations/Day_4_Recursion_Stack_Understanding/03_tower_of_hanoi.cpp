#include <bits/stdc++.h>
using namespace std;

/*
Problem: Tower of Hanoi
Solve Tower of Hanoi puzzle using recursion.
Shows how recursion depth relates to problem size.

Time: O(2^n) moves
Space: O(n) stack depth
*/

void hanoi(int n, char from, char to, char aux) {
    // Base case: move single disk
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    hanoi(n - 1, from, aux, to);

    // Step 2: Move nth disk from source to destination
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // Step 3: Move n-1 disks from auxiliary to destination
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of disks must be positive" << endl;
        return 1;
    }

    cout << "Tower of Hanoi solution for " << n << " disks:" << endl;
    cout << "Moves required: " << (1LL << n) - 1 << endl << endl;

    hanoi(n, 'A', 'C', 'B');  // A=source, C=destination, B=auxiliary

    // For n=3: 7 moves, stack depth 3
    // For n=10: 1023 moves, stack depth 10
    // For n=20: ~1 million moves, stack depth 20

    return 0;
}