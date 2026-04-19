/*
╔════════════════════════════════════════════════════════════════════════════╗
║                          EXTENDED GCD (Euclidean)                         ║
║                    Deep Dive into Mathematical Foundations               ║
╚════════════════════════════════════════════════════════════════════════════╝

📚 LEARNING OBJECTIVES:
1. Understand Extended Euclidean Algorithm
2. Learn how to find coefficients (x, y) where: a*x + b*y = gcd(a, b)
3. Use EGcd for solving linear Diophantine equations
4. Real-world applications in cryptography and number theory

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🔍 WHAT IS EXTENDED GCD?

Regular GCD finds: gcd(a, b)

Extended GCD finds: gcd(a, b) AND coefficients x, y such that:
    a*x + b*y = gcd(a, b)

Example:
    gcd(35, 15) = 5
    Extended: 35 * 1 + 15 * (-2) = 35 - 30 = 5
    So x = 1, y = -2

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// ============================================================================
// APPROACH 1: Extended Euclidean Algorithm (Recursive)
// ============================================================================

/*
The key insight:
    If we know: b*x1 + (a%b)*y1 = gcd(a, b)
    Then we can express: a%b = a - (a/b)*b
    
    So: b*x1 + (a - (a/b)*b)*y1 = gcd(a, b)
        b*x1 + a*y1 - (a/b)*b*y1 = gcd(a, b)
        a*y1 + b*(x1 - (a/b)*y1) = gcd(a, b)
    
    Therefore: x = y1, y = x1 - (a/b)*y1
*/

struct GCDResult {
    long long gcd;
    long long x;  // Coefficient for a
    long long y;  // Coefficient for b
};

GCDResult extendedGCD(long long a, long long b) {
    // Base case: if b = 0, then ax + by = a has solution x=1, y=0
    if (b == 0) {
        return {a, 1, 0};
    }
    
    // Recursive case: solve for smaller problem
    GCDResult result = extendedGCD(b, a % b);
    
    // Convert solution back
    long long x = result.y;
    long long y = result.x - (a / b) * result.y;
    
    return {result.gcd, x, y};
}

// Verify: a*x + b*y = gcd
long long verifyExtGCD(long long a, long long x, long long b, long long y, long long gcd) {
    return a * x + b * y == gcd;
}

// ============================================================================
// APPROACH 2: Extended GCD (Iterative) - Better for large recursion depth
// ============================================================================

GCDResult extendedGCD_Iterative(long long a, long long b) {
    // Initialize: we're solving for the original (a, b)
    // At each step: old_x = 1, old_y = 0, x = 0, y = 1
    
    long long old_x = 1, x = 0;
    long long old_y = 0, y = 1;
    
    while (b != 0) {
        long long quotient = a / b;
        
        // Update values
        long long temp_a = b;
        b = a % b;
        a = temp_a;
        
        long long temp_x = x;
        x = old_x - quotient * x;
        old_x = temp_x;
        
        long long temp_y = y;
        y = old_y - quotient * y;
        old_y = temp_y;
    }
    
    return {a, old_x, old_y};
}

// ============================================================================
// APPLICATION 1: Solving Linear Diophantine Equations
// ============================================================================

/*
Problem: Find integer solutions to: a*x + b*y = c

Solution exists iff: gcd(a, b) divides c

If gcd(a, b) | c, then:
    1. Find x0, y0 using Extended GCD for: a*x0 + b*y0 = gcd(a, b)
    2. Scale: x = x0 * (c / gcd), y = y0 * (c / gcd)
    3. General solution: x = x + k*(b/gcd), y = y - k*(a/gcd) for any integer k
*/

bool solveDiophantine(long long a, long long b, long long c,
                      long long &x, long long &y) {
    GCDResult result = extendedGCD(a, b);
    
    // Check if solution exists
    if (c % result.gcd != 0) {
        return false;  // No solution
    }
    
    // Scale the solution
    long long factor = c / result.gcd;
    x = result.x * factor;
    y = result.y * factor;
    
    return true;
}

// ============================================================================
// APPLICATION 2: Modular Multiplicative Inverse
// ============================================================================

/*
Problem: Find x such that: a*x ≡ 1 (mod m)
This exists iff: gcd(a, m) = 1

Solution:
    Using Extended GCD: a*x + m*y = 1
    Taking mod m: a*x ≡ 1 (mod m)
    So x is the modular inverse!
*/

long long modularInverse(long long a, long long m) {
    GCDResult result = extendedGCD(a, m);
    
    if (result.gcd != 1) {
        return -1;  // Inverse doesn't exist
    }
    
    // Make sure x is positive
    long long x = result.x % m;
    if (x < 0) x += m;
    
    return x;
}

// ============================================================================
// MAIN FUNCTION: Testing
// ============================================================================

int main() {
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║           EXTENDED GCD - DEMONSTRATION                     ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n\n";
    
    // Test 1: Basic Extended GCD
    cout << "━━━ TEST 1: Basic Extended GCD ━━━\n";
    long long a = 35, b = 15;
    
    GCDResult result = extendedGCD(a, b);
    cout << "extendedGCD(" << a << ", " << b << "):\n";
    cout << "  gcd = " << result.gcd << "\n";
    cout << "  " << a << "*(" << result.x << ") + " << b << "*(" << result.y << ") = ";
    cout << (a * result.x + b * result.y) << "\n";
    cout << "  Verification: " << (verifyExtGCD(a, result.x, b, result.y, result.gcd) ? "✓" : "✗") << "\n\n";
    
    // Test 2: Compare Recursive vs Iterative
    cout << "━━━ TEST 2: Recursive vs Iterative ━━━\n";
    a = 1071, b = 462;
    
    GCDResult recursive = extendedGCD(a, b);
    GCDResult iterative = extendedGCD_Iterative(a, b);
    
    cout << "Recursive:  gcd=" << recursive.gcd << ", x=" << recursive.x << ", y=" << recursive.y << "\n";
    cout << "Iterative:  gcd=" << iterative.gcd << ", x=" << iterative.x << ", y=" << iterative.y << "\n";
    cout << "Recursive Verify:  " << (verifyExtGCD(a, recursive.x, b, recursive.y, recursive.gcd) ? "✓" : "✗") << "\n";
    cout << "Iterative Verify:  " << (verifyExtGCD(a, iterative.x, b, iterative.y, iterative.gcd) ? "✓" : "✗") << "\n\n";
    
    // Test 3: Diophantine Equation
    cout << "━━━ TEST 3: Linear Diophantine Equation ━━━\n";
    cout << "Solve: 6x + 9y = 15\n";
    long long x, y;
    if (solveDiophantine(6, 9, 15, x, y)) {
        cout << "  Solution: x=" << x << ", y=" << y << "\n";
        cout << "  Verify: 6*" << x << " + 9*" << y << " = " << (6*x + 9*y) << "\n";
    } else {
        cout << "  No solution exists\n";
    }
    
    cout << "\nSolve: 7x + 5y = 3\n";
    if (solveDiophantine(7, 5, 3, x, y)) {
        cout << "  Solution: x=" << x << ", y=" << y << "\n";
        cout << "  Verify: 7*" << x << " + 5*" << y << " = " << (7*x + 5*y) << "\n";
    } else {
        cout << "  No solution exists\n";
    }
    
    cout << "\nSolve: 3x + 6y = 10\n";
    if (solveDiophantine(3, 6, 10, x, y)) {
        cout << "  Solution: x=" << x << ", y=" << y << "\n";
        cout << "  Verify: 3*" << x << " + 6*" << y << " = " << (3*x + 6*y) << "\n";
    } else {
        cout << "  No solution exists (gcd(3,6)=3 doesn't divide 10)\n";
    }
    
    // Test 4: Modular Inverse
    cout << "\n━━━ TEST 4: Modular Multiplicative Inverse ━━━\n";
    cout << "Find x such that: (3*x) ≡ 1 (mod 11)\n";
    long long inv = modularInverse(3, 11);
    if (inv != -1) {
        cout << "  x = " << inv << "\n";
        cout << "  Verify: (3 * " << inv << ") % 11 = " << ((3 * inv) % 11) << "\n";
    }
    
    cout << "\nFind x such that: (7*x) ≡ 1 (mod 26)\n";
    inv = modularInverse(7, 26);
    if (inv != -1) {
        cout << "  x = " << inv << "\n";
        cout << "  Verify: (7 * " << inv << ") % 26 = " << ((7 * inv) % 26) << "\n";
    }
    
    cout << "\nFind x such that: (4*x) ≡ 1 (mod 8)\n";
    inv = modularInverse(4, 8);
    if (inv != -1) {
        cout << "  x = " << inv << "\n";
        cout << "  Verify: (4 * " << inv << ") % 8 = " << ((4 * inv) % 8) << "\n";
    } else {
        cout << "  Modular inverse doesn't exist (gcd(4,8)≠1)\n";
    }
    
    // Test 5: Real-world Application
    cout << "\n━━━ TEST 5: Real-world Application ━━━\n";
    cout << "Payment Distribution Problem:\n";
    cout << "Distribute $1000 in two methods:\n";
    cout << "  - Method A: $23 per transaction\n";
    cout << "  - Method B: $17 per transaction\n";
    cout << "  - Find: x transactions of A, y of B to get exactly $1000\n\n";
    
    if (solveDiophantine(23, 17, 1000, x, y)) {
        cout << "  Possible solution: " << x << " transactions of $23, ";
        cout << y << " transactions of $17\n";
        cout << "  Total: $" << (23*x + 17*y) << "\n";
        
        // Find non-negative solution
        cout << "\n  Finding non-negative solution:\n";
        long long g = result.gcd;
        for (long long k = -100; k <= 100; k++) {
            long long new_x = x + k * (17 / g);
            long long new_y = y - k * (23 / g);
            if (new_x >= 0 && new_y >= 0) {
                cout << "  ✓ " << new_x << " of A + " << new_y << " of B = $" 
                     << (23*new_x + 17*new_y) << "\n";
                break;
            }
        }
    }
    
    cout << "\n";
    return 0;
}

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

⏱️  TIME COMPLEXITY:
    • Both recursive and iterative: O(log(min(a, b)))
    • Same as regular GCD

💾 SPACE COMPLEXITY:
    • Recursive: O(log(min(a, b))) due to recursion stack
    • Iterative: O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🚨 EDGE CASES & MISTAKES:

❌ Problem: Forgetting to handle negative and zero cases
   Integer can overflow during multiplication (especially a*x + b*y)
   → Solution: Use long long, check for overflow

❌ Problem: Incorrectly computing the backtracking formula
   Easy to mess up: x = y1, y = x1 - (a/b)*y1
   → Solution: Trace through one example manually

❌ Problem: Modular inverse doesn't exist when gcd ≠ 1
   Some might not check gcd(a, m) before computing inverse
   → Solution: Always verify gcd = 1 first

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

💎 KEY FORMULAS:

1. Extended GCD:
   a*x + b*y = gcd(a, b)

2. Solution to Diophantine:
   If gcd(a,b) | c, then ax + by = c has solutions:
   x = x0 * (c/gcd) + k*(b/gcd)
   y = y0 * (c/gcd) - k*(a/gcd)

3. Modular Inverse:
   If gcd(a,m) = 1, then x = a^(-1) ≡ x (mod m)
   where a*x + m*y = 1

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/
