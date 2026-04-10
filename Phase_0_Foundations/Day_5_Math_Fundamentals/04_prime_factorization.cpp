/*
╔════════════════════════════════════════════════════════════════════════════╗
║           PRIME FACTORIZATION - Breaking Numbers Into Primes             ║
║              The Fundamental Theorem of Arithmetic                        ║
╚════════════════════════════════════════════════════════════════════════════╝

📚 LEARNING OBJECTIVES:
1. Understand Prime Factorization theorem
2. Learn efficient factorization algorithms
3. Handle edge cases: 0, 1, negatives, large numbers
4. Real-world applications: GCD/LCM, cryptography, divisors

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🔍 FUNDAMENTAL THEOREM OF ARITHMETIC:

Every integer > 1 can be uniquely expressed as a product of primes.

Example:
    30 = 2 × 3 × 5
    100 = 2² × 5²
    17 = 17 (prime itself)

This factorization is UNIQUE (up to ordering)!

Key insight for problems:
    • Number of divisors = (a₁+1)(a₂+1)...(aₖ+1) where n = p₁^a₁ · p₂^a₂ · ... · pₖ^aₖ
    • Prime factorization helps find GCD/LCM easily
    • Used in cryptography (RSA relies on difficulty of factoring large numbers)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

// ============================================================================
// APPROACH 1: Simple Prime Factorization
// ============================================================================

/*
Divide by smallest factors first:
    - Try 2: divide out all factors of 2
    - Try 3, 5, 7, ...: divide out all factors
    - Only check up to √n (remaining factor, if any, must be prime)

Time: O(√n)
Space: O(log n) for storing factors
*/

map<long long, int> primeFactorize(long long n) {
    map<long long, int> factors;
    
    if (n <= 1) return factors;  // No factors for 0, 1, negatives
    
    n = abs(n);  // Handle negatives
    
    // Try all potential factors from 2 to √n
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    // If n > 1, then it's a prime factor
    if (n > 1) {
        factors[n]++;
    }
    
    return factors;
}

// ============================================================================
// APPROACH 2: Optimized Factorization (Skip even numbers)
// ============================================================================

/*
Observation: All even numbers except 2 are composite
So after handling 2, we only need to check odd numbers

Roughly 2x faster than basic approach
*/

map<long long, int> primeFactorize_Optimized(long long n) {
    map<long long, int> factors;
    
    if (n <= 1) return factors;
    
    n = abs(n);
    
    // Handle 2 separately
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    
    // Check only odd numbers
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    // Remaining n (if > 1) is prime
    if (n > 1) {
        factors[n]++;
    }
    
    return factors;
}

// ============================================================================
// APPROACH 3: Get all factors (not just primes)
// ============================================================================

/*
Using prime factorization, we can generate ALL divisors of n:
If n = p₁^a₁ · p₂^a₂ · ... · pₖ^aₖ

Each divisor = p₁^b₁ · p₂^b₂ · ... · pₖ^bₖ where 0 ≤ bᵢ ≤ aᵢ
*/

vector<long long> getAllDivisors(long long n) {
    map<long long, int> factors = primeFactorize_Optimized(n);
    vector<long long> divisors = {1};
    
    // For each prime factor
    for (auto [prime, count] : factors) {
        int current_size = divisors.size();
        long long power = prime;
        
        // Multiply existing divisors by powers of this prime
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < current_size; j++) {
                divisors.push_back(divisors[j] * power);
            }
            power *= prime;
        }
    }
    
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// ============================================================================
// APPROACH 4: Count divisors without generating all
// ============================================================================

/*
If n = p₁^a₁ · p₂^a₂ · ... · pₖ^aₖ
Number of divisors = (a₁+1)(a₂+1)...(aₖ+1)

Example: 36 = 2² × 3²
Divisors = (2+1)(2+1) = 9
They are: 1,2,3,4,6,9,12,18,36
*/

long long countDivisors(long long n) {
    map<long long, int> factors = primeFactorize_Optimized(n);
    long long count = 1;
    
    for (auto [prime, exp] : factors) {
        count *= (exp + 1);
    }
    
    return count;
}

// ============================================================================
// APPROACH 5: Sum of divisors
// ============================================================================

/*
If n = p₁^a₁ · p₂^a₂ · ... · pₖ^aₖ
Sum of divisors = (1 + p₁ + p₁² + ... + p₁^a₁) × (1 + p₂ + ... + p₂^a₂) × ...

Formula: ∑(p^(a+1) - 1)/(p - 1)
*/

long long sumOfDivisors(long long n) {
    map<long long, int> factors = primeFactorize_Optimized(n);
    long long sum = 1;
    
    for (auto [prime, exp] : factors) {
        // Calculate (p^(exp+1) - 1) / (p - 1)
        long long prime_sum = 1;
        long long power = prime;
        
        for (int i = 0; i < exp; i++) {
            prime_sum += power;
            power *= prime;
        }
        
        sum *= prime_sum;
    }
    
    return sum;
}

// ============================================================================
// APPLICATION 1: Check if number is perfect power
// ============================================================================

/*
A number is a perfect power if all exponents in its factorization are divisible by k

Example: 36 = 2² × 3² - perfect square (all exponents divisible by 2)
         8 = 2³ - perfect cube (all exponents divisible by 3)
*/

bool isPerfectPower(long long n, int k) {
    map<long long, int> factors = primeFactorize_Optimized(n);
    
    for (auto [prime, exp] : factors) {
        if (exp % k != 0) {
            return false;
        }
    }
    
    return true;
}

// ============================================================================
// APPLICATION 2: Find GCD/LCM from factorizations
// ============================================================================

long long gcdFromFactors(long long a, long long b) {
    auto factors_a = primeFactorize_Optimized(a);
    auto factors_b = primeFactorize_Optimized(b);
    
    long long gcd = 1;
    
    // Take minimum power of each common prime
    for (auto [prime, exp_a] : factors_a) {
        if (factors_b.count(prime)) {
            long long power = prime;
            for (int i = 0; i < min(exp_a, factors_b[prime]); i++) {
                if (gcd > 1e18 / power) break;  // Overflow check
                gcd *= prime;
            }
        }
    }
    
    return gcd;
}

// ============================================================================
// MAIN FUNCTION: Testing
// ============================================================================

int main() {
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║          PRIME FACTORIZATION - DEMONSTRATION              ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n\n";
    
    // Test 1: Basic Factorization
    cout << "━━━ TEST 1: Prime Factorization ━━━\n";
    vector<long long> numbers = {30, 100, 97, 144, 1000};
    
    for (long long n : numbers) {
        auto factors = primeFactorize_Optimized(n);
        cout << n << " = ";
        
        bool first = true;
        long long reconstruct = 1;
        for (auto [prime, exp] : factors) {
            if (!first) cout << " × ";
            cout << prime;
            if (exp > 1) cout << "^" << exp;
            first = false;
            
            for (int i = 0; i < exp; i++) {
                reconstruct *= prime;
            }
        }
        cout << " (Verify: " << reconstruct << ")\n";
    }
    cout << "\n";
    
    // Test 2: Optimized vs Basic (they should be same)
    cout << "━━━ TEST 2: Optimized vs Basic Factorization ━━━\n";
    long long test_num = 2520;
    auto factors_basic = primeFactorize(test_num);
    auto factors_opt = primeFactorize_Optimized(test_num);
    
    cout << "Number: " << test_num << "\n";
    cout << "Basic factors: ";
    for (auto [p, e] : factors_basic) cout << p << "^" << e << " ";
    cout << "\nOptimized factors: ";
    for (auto [p, e] : factors_opt) cout << p << "^" << e << " ";
    cout << "\nMatch: " << (factors_basic == factors_opt ? "✓" : "✗") << "\n\n";
    
    // Test 3: All divisors
    cout << "━━━ TEST 3: Generate All Divisors ━━━\n";
    long long div_test = 36;
    auto divisors = getAllDivisors(div_test);
    cout << "Divisors of " << div_test << ": ";
    for (long long d : divisors) {
        cout << d << " ";
    }
    cout << "\nTotal: " << divisors.size() << "\n\n";
    
    // Test 4: Count divisors
    cout << "━━━ TEST 4: Count Divisors ━━━\n";
    vector<long long> count_tests = {12, 36, 60, 100};
    for (long long n : count_tests) {
        long long count = countDivisors(n);
        long long verify = getAllDivisors(n).size();
        cout << "Divisors of " << n << ": " << count << " (Verify: " << verify << ")\n";
    }
    cout << "\n";
    
    // Test 5: Sum of divisors
    cout << "━━━ TEST 5: Sum of Divisors ━━━\n";
    vector<long long> sum_tests = {6, 12, 28};
    for (long long n : sum_tests) {
        long long sum = sumOfDivisors(n);
        cout << "Sum of divisors of " << n << ": " << sum << "\n";
    }
    cout << "\n";
    
    // Test 6: Perfect powers
    cout << "━━━ TEST 6: Perfect Powers ━━━\n";
    cout << "Is 64 a perfect square? " << (isPerfectPower(64, 2) ? "Yes" : "No") << "\n";
    cout << "Is 64 a perfect cube? " << (isPerfectPower(64, 3) ? "Yes" : "No") << "\n";
    cout << "Is 81 a perfect square? " << (isPerfectPower(81, 2) ? "Yes" : "No") << "\n";
    cout << "Is 32 a perfect power of 2? " << (isPerfectPower(32, 5) ? "Yes" : "No") << "\n";
    cout << "\n";
    
    // Test 7: Edge cases
    cout << "━━━ TEST 7: Edge Cases ━━━\n";
    cout << "Factorize 1: ";
    auto factors_1 = primeFactorize_Optimized(1);
    if (factors_1.empty()) cout << "No factors (correct)";
    else cout << "Error: 1 should have no factors";
    cout << "\n";
    
    cout << "Factorize 2: ";
    auto factors_2 = primeFactorize_Optimized(2);
    cout << (factors_2[2] == 1 ? "2 (correct)" : "Error");
    cout << "\n";
    
    cout << "Factorize -12: ";
    auto factors_neg = primeFactorize_Optimized(-12);
    cout << (factors_neg[2] == 2 && factors_neg[3] == 1 ? "2^2 × 3 (correct)" : "Error");
    cout << "\n\n";
    
    // Test 8: Large number
    cout << "━━━ TEST 8: Large Number ━━━\n";
    long long large = 1000000;
    auto large_factors = primeFactorize_Optimized(large);
    cout << large << " = ";
    for (auto [p, e] : large_factors) {
        cout << p << "^" << e << " × ";
    }
    cout << "(factors shown)\n";
    cout << "Number of divisors: " << countDivisors(large) << "\n\n";
    
    // Test 9: GCD from factorization
    cout << "━━━ TEST 9: GCD from Factorization ━━━\n";
    long long a = 120, b = 90;
    long long gcd_result = gcdFromFactors(a, b);
    cout << "GCD(" << a << ", " << b << ") = " << gcd_result << "\n";
    
    cout << "\n";
    return 0;
}

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

⏱️  TIME COMPLEXITY:
    • Basic factorization: O(√n)
    • Optimized factorization: O(√n/6) ≈ O(√n) with smaller constant
    • Generate all divisors: O(number of divisors) = O(√n) typically

💾 SPACE COMPLEXITY:
    • Storing factors: O(log n) on average, O(√n) worst case for primes
    • Storing divisors: O(d(n)) where d(n) = number of divisors

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🚨 CRITICAL MISTAKES:

❌ Problem: Not handling case when n = 1
    After factorization, n becomes 1, but we don't add 1 as a factor
    (Correct! 1 has no prime factors)
    
    ✅ Solution: Check if (n > 1) before adding it

❌ Problem: Overflow when calculating i*i
    For large i, i*i might overflow!
    
    ✅ Solution: Use (i <= sqrt(n)) or check carefully

❌ Problem: Not handling negative numbers
    Factorization is only defined for positive integers
    
    ✅ Solution: Use abs(n), then handle negative sign separately

❌ Problem: Wrong factorization method for very large numbers
    For n > 10^18, even O(√n) becomes too slow
    
    ✅ Solution: Use Pollard's rho algorithm (advanced)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

💡 OPTIMIZATION INSIGHT:

Why does generation of divisors work through factorization?

If n = 2² × 3²:
    • Start with [1]
    • Multiply by 2: [1, 2]
    • Multiply by 2: [1, 2, 4] (then [1, 2, 2, 4] after second update)
    • Multiply by 3: [1, 2, 4, 3, 6, 12]
    • Multiply by 3: [1, 2, 4, 3, 6, 12, 9, 18, 36]
    
This generates all 3×3 = 9 divisors systematically!

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/
