# 📝 Day 25: Sorting Mastery - Algorithms Comparison

## Core Sorting Algorithms

### O(n²) Algorithms

#### 1. Bubble Sort
```cpp
for (int i = 0; i < n; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            swapped = true;
        }
    }
    if (!swapped) break;  // Optimization
}
```
- Best: O(n) on sorted data
- Worst: O(n²)
- Stable: Yes
- Space: O(1)
- **When to use:** Never in production

#### 2. Selection Sort
```cpp
for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minIdx]) {
            minIdx = j;
        }
    }
    swap(arr[i], arr[minIdx]);
}
```
- All cases: O(n²)
- Stable: No
- Space: O(1)
- **When to use:** When minimizing writes is critical

#### 3. Insertion Sort
```cpp
for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}
```
- Best: O(n) on sorted data
- Worst: O(n²)
- Stable: Yes
- Space: O(1)
- **When to use:** Small arrays, nearly sorted data, online sorting

---

### O(n log n) Algorithms

#### 4. Merge Sort
```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    // Merge two sorted halves
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```
- All cases: O(n log n) **GUARANTEED**
- Stable: Yes
- Space: O(n) - not in-place
- **When to use:** Need guaranteed O(n log n), sorting linked lists, external sorting

#### 5. Quick Sort
```cpp
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i + 1], arr[j]);
            i++;
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```
- Best/Average: O(n log n)
- Worst: O(n²) (sorted array with bad pivot)
- Stable: No
- Space: O(log n) recursion
- **When to use:** General-purpose sorting, fastest average case

---

## Complexity Comparison Table

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | No |

---

## Custom Comparators

### Ascending (Default)
```cpp
sort(arr.begin(), arr.end());  // or
sort(arr.begin(), arr.end(), less<int>());
```

### Descending
```cpp
sort(arr.begin(), arr.end(), greater<int>());
```

### Custom Function Pointer
```cpp
bool compare(const int& a, const int& b) {
    return a < b;
}
sort(arr.begin(), arr.end(), compare);
```

### Lambda Function (Modern C++)
```cpp
sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
    return a < b;
});
```

### Custom Struct Sorting
```cpp
bool compareByMarks(const Student& a, const Student& b) {
    if (a.marks != b.marks) {
        return a.marks > b.marks;  // Descending
    }
    return a.rollNo < b.rollNo;    // Ascending tiebreaker
}
sort(students.begin(), students.end(), compareByMarks);
```

---

## Stability Matters

**Stable Sort:** Equal elements maintain relative order
```
Input:  [(3,'a'), (1,'b'), (3,'c'), (2,'d')]
Stable: [(1,'b'), (2,'d'), (3,'a'), (3,'c')]  ← First 3 is 'a'
Unstable: [(1,'b'), (2,'d'), (3,'c'), (3,'a')]  ← Might be this
```

**Use `stable_sort()` when order matters:**
```cpp
stable_sort(arr.begin(), arr.end(), compare);
```

---

## Real-World Wisdom

### What Standard Libraries Use

**C++ std::sort:**
- Hybrid: Quick sort + Insertion sort + Heap sort
- Best of all worlds: Fast average, avoids worst case

**Python sorted():**
- Tim Sort: Merge sort + Insertion sort
- Optimized for partially sorted data

**Java Arrays.sort():**
- Dual-pivot Quick sort variant
- Better cache performance

### When to Choose

1. **Need O(n log n) guaranteed?** → Merge Sort
2. **Want fastest average?** → Quick Sort
3. **Need stability?** → Merge Sort or Insertion Sort
4. **Small array (<50)?** → Insertion Sort
5. **Nearly sorted?** → Insertion Sort
6. **Many duplicates?** → 3-way Quick Sort
7. **Limited memory?** → Quick Sort (in-place)

---

## Common Mistakes

1. **Bad Comparator:** Doesn't define strict weak ordering
   - Fix: Ensure `f(a,a) = false` and transitivity

2. **Forgetting Stability Requirement**
   - Fix: Use `stable_sort()` when needed

3. **O(n²) on Large Data**
   - Fix: Use O(n log n) for n > 10,000

4. **Not Considering Worst Case**
   - Fix: Quick Sort worst case is O(n²) on sorted input!

5. **Comparing Unstable Sort for Database**
   - Fix: Use Merge Sort for consistency
