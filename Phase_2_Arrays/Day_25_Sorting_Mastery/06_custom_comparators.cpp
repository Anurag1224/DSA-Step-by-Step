// ============================================================================
// PROBLEM 6: Custom Comparators - Sorting by Rules
// ============================================================================
//
// Problem Statement:
// Sort pairs/objects by custom rules (e.g., by one field, ascending/descending).
// Demonstrates how to use comparators in C++.
//
// Examples:
// - Sort pairs by second element
// - Sort descending instead of ascending
// - Sort custom objects (structs)
// - Sort by multiple criteria
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

// Struct for custom sorting
struct Student {
    string name;
    int marks;
    int rollNo;
};

// Comparator 1: Sort ascending by marks
bool compareByMarks(const Student& a, const Student& b) {
    return a.marks < b.marks;
}

// Comparator 2: Sort by marks descending, then by rollNo ascending
bool compareByMarksDesc(const Student& a, const Student& b) {
    if (a.marks != b.marks) {
        return a.marks > b.marks;  // Descending marks
    }
    return a.rollNo < b.rollNo;   // Ascending rollNo (tiebreaker)
}

int main() {
    // Example 1: Sort vector of pairs by second element
    vector<pair<int, int>> pairs = {{3, 1}, {1, 3}, {2, 2}};
    
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;  // Sort by second element
    });
    
    cout << "Pairs sorted by second element:\n";
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n\n";
    
    // Example 2: Sort descending
    vector<int> nums = {3, 1, 4, 1, 5, 9};
    sort(nums.begin(), nums.end(), greater<int>());  // Descending
    
    cout << "Numbers sorted descending: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n\n";
    
    // Example 3: Sort custom objects
    vector<Student> students = {
        {"Alice", 85, 3},
        {"Bob", 92, 1},
        {"Charlie", 85, 2}
    };
    
    sort(students.begin(), students.end(), compareByMarksDesc);
    
    cout << "Students sorted by marks (desc), then rollNo (asc):\n";
    for (auto s : students) {
        cout << s.name << " - Marks: " << s.marks 
             << ", RollNo: " << s.rollNo << "\n";
    }
    cout << "\n";
    
    // Example 4: Lambda with multiple criteria
    vector<pair<string, int>> items = {{"apple", 5}, {"banana", 3}, {"apple", 2}};
    
    sort(items.begin(), items.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;  // Sort by name ascending
        }
        return a.second < b.second;    // Then by number ascending
    });
    
    cout << "Items sorted by name, then by quantity:\n";
    for (auto item : items) {
        cout << item.first << " - " << item.second << "\n";
    }
    
    return 0;
}

/*
COMPARATOR TYPES:

1. FUNCTION POINTER:
bool compare(const int& a, const int& b) {
    return a < b;
}
sort(arr.begin(), arr.end(), compare);

2. LAMBDA FUNCTION (Modern C++):
sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
    return a < b;
});

3. FUNCTION OBJECT (Functor):
struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};
sort(arr.begin(), arr.end(), Compare());

4. STL COMPARATORS:
greater<int>()     // Descending
less<int>()        // Ascending (default)

OUTPUT EXAMPLE:
Pairs sorted by second element:
(3, 1) (2, 2) (1, 3)

Numbers sorted descending: 9 5 4 3 1 1

Students sorted by marks (desc), then rollNo (asc):
Bob - Marks: 92, RollNo: 1
Alice - Marks: 85, RollNo: 3
Charlie - Marks: 85, RollNo: 2

Items sorted by name, then by quantity:
apple - 2
apple - 5
banana - 3

KEY PRINCIPLES:

1. COMPARATOR MUST DEFINE STRICT WEAK ORDERING:
   - Not reflexive: f(a, a) = false
   - Irreflexive: f(a, b) implies not f(b, a)
   - Transitive: f(a, b) and f(b, c) implies f(a, c)

2. RETURN VALUE:
   - true if first argument should come BEFORE second
   - false otherwise

3. MULTIPLE CRITERIA (Common Interview):
if (field1 != field2) {
    return compare(a.field1, b.field1);
}
return compare(a.field2, b.field2);

REAL-WORLD USE CASES:

1. Sort objects by multiple fields
   Student: by marks desc, then name asc
   
2. Sort pairs/tuples
   Coordinates: by x asc, then y desc
   
3. Custom sort orders
   Days of week: Mon, Tue, Wed...
   Custom numeric encoding
   
4. Event scheduling
   Sort events by (endTime asc, startTime asc)
   
5. Competitive programming
   Sort points by distance, then by angle

COMPLEXITY:
- Time: O(n log n) — standard sort complexity
- Space: O(log n) — recursion stack
- Comparator time: O(1) typically

STABILITY CONSIDERATIONS:
- sort() is NOT stable
- stable_sort() IS stable
- Use stable_sort if equal elements must preserve order

INTERVIEW TIP:
"I need to sort by field X ascending, then field Y descending.
I'll use a custom comparator that checks X first, and if equal,
checks Y with the order reversed."
*/
