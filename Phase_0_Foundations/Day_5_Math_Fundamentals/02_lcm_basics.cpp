/*
╔════════════════════════════════════════════════════════════════════════════╗
║              LCM: LEAST COMMON MULTIPLE - Building Block                  ║
║                     Simple Yet Powerful Concept                           ║
╚════════════════════════════════════════════════════════════════════════════╝

📚 LEARNING OBJECTIVES:
1. Understand Least Common Multiple (LCM)
2. Learn relationship between LCM and GCD
3. Handle edge cases and overflow
4. Real-world applications: scheduling, synchronization, fractions

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🔍 WHAT IS LCM?

LCM(a, b) = Least Common Multiple
            = Smallest positive integer divisible by both a and b

Example:
    LCM(12, 18):
    - Multiples of 12: 12, 24, 36, 48, 60, 72, ...
    - Multiples of 18: 18, 36, 54, 72, 90, ...
    - LCM = 36 (first common multiple)

Key Formula:
    LCM(a, b) = (a * b) / GCD(a, b)

Why? Because:
    a = GCD * a'  where gcd(a', b') = 1
    b = GCD * b'
    Then LCM = GCD * a' * b' = (a * b) / GCD

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ============================================================================
// HELPER: Basic GCD (needed for LCM)
// ============================================================================

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// ============================================================================
// APPROACH 1: LCM using GCD Formula
// ============================================================================

/*
Formula: LCM(a, b) = (a * b) / GCD(a, b)

Advantage: Super efficient - just one GCD call!

Limitation: Multiplication (a*b) can overflow before dividing by GCD
Solution: Compute as (a / GCD(a, b)) * b to avoid intermediate overflow
*/

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    
    a = abs(a);
    b = abs(b);
    
    long long g = gcd(a, b);
    
    // Avoid overflow: divide first, then multiply
    return (a / g) * b;
}

// ============================================================================
// APPROACH 2: LCM with Overflow Safety
// ============================================================================

/*
For very large numbers, even (a/gcd)*b can overflow.
We need to detect and handle this.
*/

const long long LIMIT = 1e18;  // Safe limit for long long

long long lcm_SafeOverflow(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    
    a = abs(a);
    b = abs(b);
    
    long long g = gcd(a, b);
    long long a_reduced = a / g;
    
    // Check if multiplication will overflow
    if (a_reduced > LIMIT / b) {
        return -1;  // Indicates overflow
    }
    
    return a_reduced * b;
}

// ============================================================================
// APPROACH 3: LCM of Multiple Numbers
// ============================================================================

/*
LCM(a, b, c) = LCM(LCM(a, b), c)

General pattern for array of numbers
*/

long long lcm_Array(vector<long long> nums) {
    if (nums.empty()) return 0;
    
    long long result = abs(nums[0]);
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == 0 || result == 0) {
            result = 0;
            break;
        }
        
        long long g = gcd(result, abs(nums[i]));
        
        // Check overflow
        if (result / g > LIMIT / abs(nums[i])) {
            return -1;  // Overflow
        }
        
        result = (result / g) * abs(nums[i]);
    }
    
    return result;
}

// ============================================================================
// APPROACH 4: Prime Factorization Method (Alternative Understanding)
// ============================================================================

/*
Understanding LCM through prime factorization:

Example: 12 = 2² × 3¹, 18 = 2¹ × 3²
LCM(12, 18) = 2^max(2,1) × 3^max(1,2) = 2² × 3² = 4 × 9 = 36

This is conceptual; the GCD method is more efficient for code.
*/

// Get prime factorization
map<long long, int> primeFactors(long long n) {
    map<long long, int> factors;
    
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    
    return factors;
}

// LCM using prime factorization (educational, less efficient)
long long lcm_PrimeMethod(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    
    a = abs(a);
    b = abs(b);
    
    auto factors_a = primeFactors(a);
    auto factors_b = primeFactors(b);
    
    long long result = 1;
    
    // Get all unique prime factors
    for (auto &p : factors_a) {
        long long prime = p.first;
        int power = max(p.second, factors_b[prime]);
        
        for (int i = 0; i < power; i++) {
            if (result > LIMIT / prime) return -1;  // Overflow
            result *= prime;
        }
    }
    
    for (auto &p : factors_b) {
        long long prime = p.first;
        if (factors_a.find(prime) == factors_a.end()) {
            int power = p.second;
            for (int i = 0; i < power; i++) {
                if (result > LIMIT / prime) return -1;  // Overflow
                result *= prime;
            }
        }
    }
    
    return result;
}

// ============================================================================
// APPLICATION 1: Synchronized Task Scheduling
// ============================================================================

/*
Problem: Two tasks repeat every (a) and (b) seconds.
When will they run simultaneously?

Answer: After LCM(a, b) seconds

Example: Task A every 12 sec, Task B every 18 sec
LCM(12, 18) = 36 seconds
*/

void taskScheduling(long long interval_a, long long interval_b) {
    long long sync_time = lcm(interval_a, interval_b);
    
    cout << "Task A (every " << interval_a << "s) and Task B (every "
         << interval_b << "s) will synchronize every " << sync_time << " seconds\n";
}

// ============================================================================
// APPLICATION 2: Fraction Operations
// ============================================================================

/*
Problem: Add fractions with different denominators
    1/12 + 1/18

Solution:
    LCM(12, 18) = 36
    1/12 = 3/36, 1/18 = 2/36
    Sum = 5/36
*/

struct Fraction {
    long long numerator;
    long long denominator;
    
    Fraction(long long n, long long d) : numerator(n), denominator(d) {}
    
    void reduce() {
        long long g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }
    
    Fraction operator+(const Fraction &other) const {
        long long common = lcm(denominator, other.denominator);
        long long new_num = numerator * (common / denominator) + 
                           other.numerator * (common / other.denominator);
        Fraction result(new_num, common);
        result.reduce();
        return result;
    }
    
    void print() const {
        cout << numerator << "/" << denominator;
    }
};

// ============================================================================
// MAIN FUNCTION: Testing
// ============================================================================

int main() {
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║                   LCM - DEMONSTRATION                      ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n\n";
    
    // Test 1: Basic LCM
    cout << "━━━ TEST 1: Basic LCM Calculation ━━━\n";
    vector<pair<long long, long long>> test_cases_basic = {
        {12, 18},
        {5, 7},
        {24, 36},
        {13, 26}
    };
    
    for (auto [a, b] : test_cases_basic) {
        long long result = lcm(a, b);
        long long g = gcd(a, b);
        cout << "LCM(" << a << ", " << b << ") = " << result;
        cout << "  [GCD=" << g << ", Formula: (" << a << "*" << b << ")/" 
             << g << " = " << result << "]\n";
    }
    
    // Test 2: Edge Cases
    cout << "\n━━━ TEST 2: Edge Cases ━━━\n";
    cout << "LCM(0, 5) = " << lcm(0, 5) << " (one of them is zero)\n";
    cout << "LCM(1, 1) = " << lcm(1, 1) << " (both one)\n";
    cout << "LCM(7, 7) = " << lcm(7, 7) << " (same number)\n";
    cout << "LCM(-12, 18) = " << lcm(-12, 18) << " (negative number)\n";
    
    // Test 3: LCM of Multiple Numbers
    cout << "\n━━━ TEST 3: LCM of Multiple Numbers ━━━\n";
    vector<long long> nums1 = {4, 6, 9};
    cout << "LCM(4, 6, 9) = " << lcm_Array(nums1) << "\n";
    
    vector<long long> nums2 = {5, 10, 15, 20};
    cout << "LCM(5, 10, 15, 20) = " << lcm_Array(nums2) << "\n";
    
    // Test 4: Prime Factorization Method (showing equivalence)
    cout << "\n━━━ TEST 4: Prime Factorization Method vs GCD Method ━━━\n";
    long long a = 24, b = 36;
    long long lcm_gcd = lcm(a, b);
    long long lcm_prime = lcm_PrimeMethod(a, b);
    cout << "LCM(" << a << ", " << b << "):\n";
    cout << "  Using GCD method:         " << lcm_gcd << "\n";
    cout << "  Using Prime method:       " << lcm_prime << "\n";
    cout << "  Match: " << (lcm_gcd == lcm_prime ? "✓" : "✗") << "\n";
    
    // Test 5: Real-world Application - Task Scheduling
    cout << "\n━━━ TEST 5: Task Scheduling ━━━\n";
    taskScheduling(12, 18);
    taskScheduling(15, 20);
    taskScheduling(7, 11);
    
    // Test 6: Real-world Application - Fraction Addition
    cout << "\n━━━ TEST 6: Fraction Addition ━━━\n";
    Fraction f1(1, 12);
    Fraction f2(1, 18);
    cout << "Adding: ";
    f1.print();
    cout << " + ";
    f2.print();
    cout << " = ";
    Fraction sum = f1 + f2;
    sum.print();
    cout << "\n";
    
    Fraction f3(3, 14);
    Fraction f4(2, 21);
    cout << "Adding: ";
    f3.print();
    cout << " + ";
    f4.print();
    cout << " = ";
    Fraction sum2 = f3 + f4;
    sum2.print();
    cout << "\n";
    
    // Test 7: Overflow Safety
    cout << "\n━━━ TEST 7: Overflow Detection ━━━\n";
    long long large_a = 1000000000LL;
    long long large_b = 999999999LL;
    long long result = lcm_SafeOverflow(large_a, large_b);
    if (result == -1) {
        cout << "Overflow detected for LCM(" << large_a << ", " << large_b << ")\n";
    } else {
        cout << "LCM(" << large_a << ", " << large_b << ") = " << result << "\n";
    }
    
    cout << "\n";
    return 0;
}

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

⏱️  TIME COMPLEXITY:
    • Using GCD method: O(log(min(a, b)))
    • Using Prime factorization: O(√a + √b)
    
💾 SPACE COMPLEXITY:
    • GCD method: O(1)
    • Prime factorization: O(log(min(a,b))) for storing factors

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🚨 COMMON MISTAKES:

❌ Problem: Computing a*b without checking overflow
    long long result = a * b / gcd(a, b);
    If a*b overflows, result is garbage!
    
    ✅ Solution: Divide first!
    long long result = (a / gcd(a, b)) * b;

❌ Problem: Not handling zero
    LCM(n, 0) should be 0 (no common multiple)
    
    ✅ Solution: Always check if either is zero

❌ Problem: Using int instead of long long
    LCM values grow quickly!
    
    ✅ Solution: Always use long long for intermediate calculations

❌ Problem: Negative numbers
    LCM should always be positive
    
    ✅ Solution: Use abs() on inputs

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

💡 INTUITION:

GCD vs LCM:
    GCD: What's the LARGEST number that divides both?
    LCM: What's the SMALLEST number that both divide?

Visual:
    12 = 4 × 3
    18 = 6 × 3
    GCD = 6 (largest common factor)
    LCM = 36 (smallest common multiple)
    LCM × GCD = 12 × 18  (always true!)
    36 × 6 = 12 × 18 = 216 ✓

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/
