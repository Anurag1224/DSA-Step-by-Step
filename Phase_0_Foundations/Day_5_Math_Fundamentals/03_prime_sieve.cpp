/*
╔════════════════════════════════════════════════════════════════════════════╗
║          SIEVE OF ERATOSTHENES - Prime Filtering Masterpiece             ║
║                    Find All Primes Up to N Efficiently                    ║
╚════════════════════════════════════════════════════════════════════════════╝

📚 LEARNING OBJECTIVES:
1. Understand Sieve of Eratosthenes algorithm
2. Learn efficient prime generation
3. Optimize for memory and speed
4. Real-world applications: prime checking, prime factors, cryptography

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🔍 WHAT IS SIEVE OF ERATOSTHENES?

Ancient algorithm (250 BC!) to find all primes up to N:

Step-by-step for primes up to 30:
    Start: [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, ...]
    
    1. Mark 2 as prime, cross out all multiples: 4, 6, 8, 10, 12, 14, ...
    2. Next unmarked is 3, mark as prime, cross out: 9, 15, 21, 27, ...
    3. Next unmarked is 5, mark as prime, cross out: 25, 35, ...
    4. Continue until √N
    
    Remaining: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 (all primes!)

Why it works:
    Any composite number n has at least one factor ≤ √n
    So we only need to sieve up to √n
    
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
using namespace std;

// ============================================================================
// APPROACH 1: Simple Sieve (Easy to understand)
// ============================================================================

/*
Mark non-primes as we go. Final unmarked numbers are primes.

Time: O(n log log n)  [Very efficient!]
Space: O(n)
*/

vector<bool> sieve_Simple(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime
    
    // Sieve: mark multiples of each prime as composite
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            // Mark all multiples of i as not prime
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    return is_prime;
}

// Get vector of all prime numbers up to n
vector<int> getPrimes_Simple(int n) {
    vector<bool> is_prime = sieve_Simple(n);
    vector<int> primes;
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

// ============================================================================
// APPROACH 2: Optimized Sieve (Skip even numbers)
// ============================================================================

/*
Observation: All even numbers except 2 are not prime!
So we only track odd numbers.

Saves 50% space and about 2x speedup
*/

vector<bool> sieve_Optimized(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    if (n >= 2) is_prime[2] = true;
    
    // Mark all even numbers as not prime (except 2)
    for (int i = 4; i <= n; i += 2) {
        is_prime[i] = false;
    }
    
    // Only check odd numbers
    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                is_prime[j] = false;
            }
        }
    }
    
    return is_prime;
}

// ============================================================================
// APPROACH 3: Segmented Sieve (For very large ranges)
// ============================================================================

/*
Problem: For range [L, R] where R is HUGE but (R-L) is small, 
         we can't allocate array of size R

Solution: Use simple sieve to find primes up to √R,
          then use them to mark composites in [L, R]
*/

vector<bool> segmented_Sieve(long long L, long long R) {
    if (L == 1) L = 2;
    
    // Step 1: Find all primes up to √R
    long long limit = sqrt(R) + 1;
    vector<bool> is_prime_small = sieve_Simple(limit);
    
    vector<long long> primes;
    for (long long i = 2; i <= limit; i++) {
        if (is_prime_small[i]) {
            primes.push_back(i);
        }
    }
    
    // Step 2: Mark composites in [L, R]
    vector<bool> is_prime(R - L + 1, true);
    
    for (long long p : primes) {
        // Find first multiple of p in [L, R]
        long long start = max(p * p, ((L + p - 1) / p) * p);
        
        for (long long j = start; j <= R; j += p) {
            is_prime[j - L] = false;
        }
    }
    
    // 2 is prime if it's in range
    if (L <= 2 && 2 <= R) {
        is_prime[2 - L] = true;
    }
    
    return is_prime;
}

// ============================================================================
// APPLICATION 1: Count primes by Sieve
// ============================================================================

int countPrimes(int n) {
    vector<bool> is_prime = sieve_Simple(n);
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) count++;
    }
    return count;
}

// ============================================================================
// APPLICATION 2: Prime checking
// ============================================================================

bool isPrimeFast(int n, const vector<bool> &sieve) {
    if (n < 2) return false;
    if (n > sieve.size() - 1) return false;  // Out of range
    return sieve[n];
}

// ============================================================================
// APPLICATION 3: Sum of all primes up to N
// ============================================================================

long long sumOfPrimes(int n) {
    vector<bool> is_prime = sieve_Simple(n);
    long long sum = 0;
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            sum += i;
        }
    }
    
    return sum;
}

// ============================================================================
// APPLICATION 4: Prime Gaps Analysis
// ============================================================================

/*
Problem: What's the largest gap between consecutive primes up to N?
         This has applications in cryptography and number theory
*/

int largestPrimeGap(int n) {
    vector<int> primes = getPrimes_Simple(n);
    
    int max_gap = 0;
    for (int i = 1; i < primes.size(); i++) {
        int gap = primes[i] - primes[i-1];
        max_gap = max(max_gap, gap);
    }
    
    return max_gap;
}

// ============================================================================
// MAIN FUNCTION: Testing
// ============================================================================

int main() {
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║        SIEVE OF ERATOSTHENES - DEMONSTRATION              ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n\n";
    
    // Test 1: Simple Sieve
    cout << "━━━ TEST 1: Simple Sieve (up to 100) ━━━\n";
    vector<int> primes_100 = getPrimes_Simple(100);
    cout << "Primes up to 100: ";
    for (int p : primes_100) {
        if (p <= 100) cout << p << " ";
    }
    cout << "\nTotal: " << primes_100.size() << " primes\n\n";
    
    // Test 2: Optimized Sieve
    cout << "━━━ TEST 2: Optimized Sieve (up to 200) ━━━\n";
    vector<bool> primes_200 = sieve_Optimized(200);
    int count = 0;
    for (int i = 2; i <= 200; i++) {
        if (primes_200[i]) count++;
    }
    cout << "Count of primes up to 200: " << count << "\n\n";
    
    // Test 3: Compare Simple vs Optimized
    cout << "━━━ TEST 3: Prime Checking Speed Comparison ━━━\n";
    int test_range = 1000;
    vector<bool> sieve_data = sieve_Optimized(test_range);
    
    cout << "First 50 primes up to " << test_range << ": \n";
    int printed = 0;
    for (int i = 2; i <= test_range && printed < 50; i++) {
        if (sieve_data[i]) {
            cout << i << " ";
            printed++;
            if (printed % 10 == 0) cout << "\n";
        }
    }
    cout << "\n\n";
    
    // Test 4: Count primes
    cout << "━━━ TEST 4: Count Primes ━━━\n";
    vector<int> ranges = {100, 1000, 10000};
    for (int r : ranges) {
        int c = countPrimes(r);
        cout << "Primes up to " << r << ": " << c << "\n";
    }
    cout << "\n";
    
    // Test 5: Sum of primes
    cout << "━━━ TEST 5: Sum of Primes ━━━\n";
    cout << "Sum of primes up to 100: " << sumOfPrimes(100) << "\n";
    cout << "Sum of primes up to 1000: " << sumOfPrimes(1000) << "\n\n";
    
    // Test 6: Prime gaps
    cout << "━━━ TEST 6: Prime Gaps Analysis ━━━\n";
    int max_gap_100 = largestPrimeGap(100);
    int max_gap_1000 = largestPrimeGap(1000);
    cout << "Largest gap between consecutive primes up to 100: " << max_gap_100 << "\n";
    cout << "Largest gap between consecutive primes up to 1000: " << max_gap_1000 << "\n\n";
    
    // Test 7: Segmented Sieve
    cout << "━━━ TEST 7: Segmented Sieve (Large Range) ━━━\n";
    long long L = 1000, R = 1100;
    vector<bool> seg_primes = segmented_Sieve(L, R);
    cout << "Primes in range [" << L << ", " << R << "]: ";
    int seg_count = 0;
    for (long long i = L; i <= R; i++) {
        if (seg_primes[i - L]) {
            cout << i << " ";
            seg_count++;
        }
    }
    cout << "\nTotal: " << seg_count << " primes in this range\n\n";
    
    // Test 8: Special Cases
    cout << "━━━ TEST 8: Special Cases ━━━\n";
    cout << "Is 2 prime? " << isPrimeFast(2, sieve_Optimized(100) ? "Yes" : "No") << "\n";
    cout << "Is 1 prime? " << (sieve_Optimized(100)[1] ? "Yes" : "No") << "\n";
    cout << "Is 0 prime? " << (sieve_Optimized(100)[0] ? "Yes" : "No") << "\n";
    
    cout << "\n";
    return 0;
}

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

⏱️  TIME COMPLEXITY:
    • Simple/Optimized Sieve: O(n log log n)
    • Segmented Sieve: O((R-L) log log R + √R log log √R)

💾 SPACE COMPLEXITY:
    • Simple Sieve: O(n)
    • Optimized Sieve: O(n) [but only half the space in practice]
    • Segmented Sieve: O(√n + (R-L))

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🚨 CRITICAL MISTAKES:

❌ Problem: Starting inner loop from i instead of i²
    for (int j = i; j <= n; j += i)  // WRONG!
    This double-marks numbers unnecessarily
    
    ✅ Solution: Start from i*i
    for (int j = i * i; j <= n; j += i)  // CORRECT!

❌ Problem: Not marking 0 and 1 as non-prime
    They're not considered prime in mathematics
    
    ✅ Solution: is_prime[0] = is_prime[1] = false;

❌ Problem: Array out of bounds for segmented sieve
    When accessing array, must use (index - L) offset
    
    ✅ Solution: Always use is_prime[j - L] not is_prime[j]

❌ Problem: Overflow when computing i*i
    For large i, i*i can overflow!
    
    ✅ Solution: Use long long, check i*i <= n before calculating

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

💡 WHY SIEVE IS SO FAST:

Naive approach: Check each number individually O(n√n)
    For each number n: check divisibility up to √n

Sieve approach: O(n log log n)
    Mark multiples efficiently instead of checking divisibility
    
Why log log n?
    • 2 marks n/2 numbers
    • 3 marks n/3 numbers (but n/6 already marked by 2)
    • 5 marks n/5 numbers (already partially marked)
    • Sum: n(1/2 + 1/3 + 1/5 + ...·) ≈ n log log n

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🎯 WHEN TO USE WHICH:

1. Simple Sieve: Most common, easy to remember
2. Optimized Sieve: When memory is a concern (n > 10^7)
3. Segmented Sieve: When range [L, R] is small but R is huge (10^9+)
4. Naive checking: Only for single prime checks, not bulk queries

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/
