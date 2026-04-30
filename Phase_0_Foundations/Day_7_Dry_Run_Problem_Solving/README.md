# 🧠 DAY 7: Dry Run & Problem-Solving Mindset

**Think before coding. Verify before submitting.**

---

## 🎯 Goal of Day 7

By the end of today, you will:

✅ Learn how to turn problem statements into working examples  
✅ Practice solving problems with a dry run before writing code  
✅ Build a consistent checklist for every coding task  
✅ Catch edge cases before implementation  
✅ Write code with confidence and fewer bugs

---

## 1️⃣ What is a Dry Run?

A dry run is manually tracing the algorithm step by step using a sample input.

It forces you to:
- understand the problem deeply
- verify every decision
- find mistakes before coding

### Example
For input `[2, 5, 3]` and target `5`:
- Step 1: check index 0 → 2 != 5
- Step 2: check index 1 → 5 == 5 → found at index 1

This is the exact thought process your code must follow.

---

## 2️⃣ Why Plan First?

### Problems caused by rushing
- Wrong assumptions
- Missed edge cases
- Partially correct code
- More debugging later

### Better approach
1. Read the full problem statement
2. Write a few sample cases
3. Show the steps manually
4. Code only after the steps are clear
5. Test with the samples and edge cases

---

## 3️⃣ Problem-Solving Process

### Step 1: Understand inputs and outputs
- What are the input types?
- What is the output format?
- Are there constraints or limits?

### Step 2: Build concrete examples
- Normal case
- Smallest case
- Largest case
- Edge cases

### Step 3: Dry run one example
Write the path the algorithm takes.

### Step 4: Implement carefully
Once the plan is solid, code the algorithm.

### Step 5: Validate and test
Use the example cases from step 2.

---

## 4️⃣ Example Walkthrough

Problem: Find the missing number in a sequence from `1` to `n` with one number removed.

Input: `n = 5`, `arr = [1, 2, 4, 5]`

Dry run:
- Expected sum = 1 + 2 + 3 + 4 + 5 = 15
- Actual sum = 1 + 2 + 4 + 5 = 12
- Missing number = 15 - 12 = 3

If you can trace this correctly on paper, your code will be easier to write.

---

## 5️⃣ Practice Problems

1. Dry run a target search and trace each index
2. Find the missing number in a sequence
3. Validate that a sequence follows the rules
4. Identify the first local peak in a simple array

---

## 🔗 Next Steps

After this, commit your work with a descriptive message like:

`phase0: day7 dry run and problem-solving mindset`

> Good planning saves debugging time. Start solving problems with confidence.
