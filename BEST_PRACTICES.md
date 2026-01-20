# ✅ Best Coding Practices (Non-Negotiable)

These practices are not optional. They're how real engineers write code.

---

## 1️⃣ Variable Naming

### ✔️ DO This
```cpp
int digitCount = 0;
int reversedNumber = 0;
bool isPalindrome = true;
```

### ❌ DON'T Do This
```cpp
int c = 0;          // meaningless
int rev = 0;        // too vague
int p = true;       // what does p mean?
```

**Why?**
- 6 months later, you won't remember `c` means count
- Interviewers notice variable names
- Code is read 10x more than written

---

## 2️⃣ Magic Numbers Are Forbidden

### ✔️ DO This
```cpp
const int MOD = 1e9 + 7;
const int MAX_DIGITS = 10;
const long long LONG_MAX_VAL = 2147483647;

int result = (n * m) % MOD;
```

### ❌ DON'T Do This
```cpp
int result = (n * m) % 1000000007;  // where did this come from?
if (digits > 10) { ... }             // magic number
```

**Why?**
- Constants are self-documenting
- Easy to change later
- Prevents errors from typos

---

## 3️⃣ Explicit Edge Case Handling

### ✔️ DO This
```cpp
int countDigits(int n) {
    // Handle zero explicitly
    if (n == 0) return 1;
    
    // Handle negatives explicitly
    n = abs(n);
    
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}
```

### ❌ DON'T Do This
```cpp
int countDigits(int n) {
    int count = 0;
    while (n > 0) {          // fails for 0 and negatives
        count++;
        n /= 10;
    }
    return count;            // buried bugs
}
```

**Why?**
- Shows you thought about edge cases
- Prevents production bugs
- Interviewers love this

---

## 4️⃣ Comments: Intent, Not Syntax

### ✔️ DO This
```cpp
// Handle the case where number is zero (mathematically has 1 digit)
if (n == 0) return 1;

// Remove negative sign; we only care about digit count
n = abs(n);
```

### ❌ DON'T Do This
```cpp
// Increment count
count++;

// Check if n is not zero
while (n > 0) {
    // Divide n by 10
    n = n / 10;
}
```

**Why?**
- Your code explains what, not why
- Comments should explain why
- Good comments are rare and valuable

---

## 5️⃣ Data Types: Think About Ranges

### ✔️ DO This
```cpp
// For multiplication, use long long to prevent overflow
long long result = 1LL * a * b;

// For large sums, use long long
long long sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];
}

// For GCD, use int (result is always ≤ min(a,b))
int gcd_result = gcd(a, b);
```

### ❌ DON'T Do This
```cpp
int result = a * b;        // overflow!
int sum = 0;               // sum might overflow
long long gcd_result = gcd(a, b);  // unnecessary
```

**Why?**
- Integer overflow is silent and deadly
- Production bugs come from this
- Shows you understand data types

---

## 6️⃣ Function Design: Small & Focused

### ✔️ DO This
```cpp
// Separate concerns
int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return reversed;
}

bool isPalindrome(int n) {
    if (n < 0) return false;
    return n == reverseNumber(n);
}
```

### ❌ DON'T Do This
```cpp
bool isPalindrome(int n) {
    // Everything jammed together
    if (n < 0) return false;
    
    int reversed = 0;
    int temp = n;
    while (temp > 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    return n == reversed;
}
```

**Why?**
- Reusability (reverseNumber can be used elsewhere)
- Readability (easy to understand)
- Testability (can test each function separately)

---

## 7️⃣ Early Termination (Guard Clauses)

### ✔️ DO This
```cpp
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    
    if (b == 0) return a;           // early return
    return gcd(b, a % b);
}
```

### ❌ DON'T Do This
```cpp
int gcd(int a, int b) {
    if (a != 0 && b != 0) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
    return 0;
}
```

**Why?**
- Less nesting = easier to read
- Handles special cases immediately
- Reduces cognitive load

---

## 8️⃣ No Global Variables

### ✔️ DO This
```cpp
int main() {
    int a = 10, b = 20;
    int result = gcd(a, b);
    cout << result;
}
```

### ❌ DON'T Do This
```cpp
int a = 10;        // global
int b = 20;        // global

int main() {
    cout << gcd();  // where are parameters?
}
```

**Why?**
- Globals are debugging nightmares
- Hard to test
- Can cause unexpected interactions

---

## 9️⃣ Test Your Code

### ✔️ DO This
```cpp
// Test normal case
assert(countDigits(12345) == 5);

// Test edge case: zero
assert(countDigits(0) == 1);

// Test edge case: single digit
assert(countDigits(5) == 1);

// Test edge case: negative
assert(countDigits(-123) == 3);
```

### ❌ DON'T Do This
```cpp
// Just code and hope it works
```

**Why?**
- Catches bugs before submission
- Confidence in your solution
- Shows you test-think

---

## 🔟 Optimize Only After Correctness

### ✔️ DO This
```cpp
// Step 1: Write brute force (O(n²))
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // find match
    }
}

// Step 2: Verify it works
// Test with examples...

// Step 3: Then optimize (use HashMap)
unordered_map<int, int> freq;
for (int i = 0; i < n; i++) {
    if (freq.find(target - arr[i]) != freq.end()) {
        // found match
    }
    freq[arr[i]]++;
}
```

### ❌ DON'T Do This
```cpp
// Jump straight to "clever" optimization
// without knowing if it's correct
```

**Why?**
- Correctness first, speed later
- Premature optimization causes bugs
- Interviewers want to see your thinking

---

## Code Review Checklist

Before submitting your code, ask:

- [ ] Does it handle n = 0?
- [ ] Does it handle negative inputs?
- [ ] Does it handle very large inputs?
- [ ] Are variable names clear?
- [ ] Are magic numbers constants?
- [ ] Are edge cases explicit?
- [ ] Are functions small and focused?
- [ ] Did I test it?
- [ ] Can I explain it clearly?
- [ ] Is there a better approach?

---

## C++ Specific Tips

### Use `auto` Wisely (C++11+)
```cpp
// Good use of auto (type is obvious)
auto it = map.find(key);

// Bad use of auto (type is unclear)
auto result = complexFunction();  // what type is result?
```

### Prefer `const`
```cpp
const int MOD = 1e9 + 7;           // constants
const int arr[] = {1, 2, 3};       // arrays that don't change
```

### Use Range-Based Loops
```cpp
// Modern C++
for (int num : arr) {
    cout << num;
}

// Instead of
for (int i = 0; i < n; i++) {
    cout << arr[i];
}
```

### STL Containers & Methods
```cpp
vector<int> v = {1, 2, 3};
unordered_map<int, int> freq;
set<int> unique_elements;
```

---

## Final Checklist: Before Every Submission

✅ **Syntax Check** — Code compiles  
✅ **Logic Check** — Dry run on examples  
✅ **Edge Case Check** — Special inputs handled  
✅ **Complexity Check** — Time/space acceptable  
✅ **Name Check** — Variables are clear  
✅ **Comment Check** — Intent is obvious  
✅ **Test Check** — Works on all cases  

---

## Remember

> "Code is read much more often than it is written. 
> Make it easy for future you and other engineers."

**Write code as if your job depends on it — because it does!** 💪
