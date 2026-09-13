Perfect. Below is **exactly what you asked for**, in a **clean, interview-usable format**.

---

# ✅ EXACT 10 SLIDING-WINDOW PROBLEMS PER COMPANY (RANKED)

> **Ranking logic**
> **1–3** = must-solve (almost guaranteed patterns)
> **4–7** = very common
> **8–10** = differentiators (strong candidates)

---

## 🟢 GOOGLE (Reasoning + Invariants)

### 🔥 Top 10 (Ranked)

1. **Minimum Window Substring**
2. **Longest Repeating Character Replacement**
3. **Sliding Window Maximum**
4. Subarrays with K Different Integers
5. Longest Substring Without Repeating Characters
6. Sliding Window Median
7. Longest Continuous Subarray with Abs Diff ≤ Limit
8. Subarray Product Less Than K
9. Max Value of Equation
10. Maximum Sum of 3 Non-Overlapping Subarrays

📌 *Google expects you to explain WHY shrinking works.*

---

## 🟣 META (Facebook) (Frequency Precision)

### 🔥 Top 10 (Ranked)

1. **Longest Substring Without Repeating Characters**
2. **Find All Anagrams in a String**
3. **Permutation in String**
4. Subarrays with K Different Integers
5. Longest Repeating Character Replacement
6. Minimum Window Substring
7. Count Number of Nice Subarrays
8. Fruit Into Baskets
9. Subarray Product Less Than K
10. Maximum Number of Vowels in a Substring

📌 *Meta heavily checks frequency correctness.*

---

## 🟠 AMAZON (Production-Safe Logic)

### 🔥 Top 10 (Ranked)

1. **Minimum Size Subarray Sum**
2. **Maximum Average Subarray I**
3. **Subarray Product Less Than K**
4. Grumpy Bookstore Owner
5. Fruit Into Baskets
6. Longest Repeating Character Replacement
7. Maximum Points You Can Obtain from Cards
8. Minimum Operations to Reduce X to Zero
9. Longest Subarray of 1s After Deleting One Element
10. Count Number of Subarrays with Bounded Maximum

📌 *Amazon focuses on edge cases & correctness.*

---

## 🍎 APPLE (Precision & Clean Code)

### 🔥 Top 10 (Ranked)

1. **Longest Substring Without Repeating Characters**
2. **Minimum Window Substring**
3. **Maximum Number of Vowels in a Substring**
4. Find All Anagrams in a String
5. Sliding Window Maximum
6. Maximum Average Subarray I
7. Fruit Into Baskets
8. Subarray Product Less Than K
9. Longest Repeating Character Replacement
10. Maximum Points from Cards

📌 *Apple rejects off-by-one bugs instantly.*

---

## 🟡 MICROSOFT (Template Mastery)

### 🔥 Top 10 (Ranked)

1. **Longest Substring Without Repeating Characters**
2. **Minimum Size Subarray Sum**
3. **Maximum Average Subarray I**
4. Find All Anagrams in a String
5. Fruit Into Baskets
6. Subarray Product Less Than K
7. Longest Repeating Character Replacement
8. Count Number of Nice Subarrays
9. Sliding Window Maximum
10. Minimum Window Substring

📌 *Microsoft expects pattern recognition.*

---

## 🔵 UBER / NETFLIX / ATLASSIAN (Optimization)

### 🔥 Top 10 (Ranked)

1. **Sliding Window Maximum**
2. **Sliding Window Median**
3. **Longest Continuous Subarray with Abs Diff ≤ Limit**
4. Max Value of Equation
5. Longest Repeating Character Replacement
6. Subarray Product Less Than K
7. Fruit Into Baskets
8. Minimum Window Substring
9. Count Number of Subarrays with Bounded Maximum
10. Maximum Sum of 3 Non-Overlapping Subarrays

📌 *They care about correct DS choice (deque vs heap).*

---

# 🌳 DECISION TREE

## Sliding Window vs Prefix Sum vs Binary Search

This is **EXTREMELY IMPORTANT** for interviews.

---

## STEP 1: Are elements CONTIGUOUS (subarray / substring)?

❌ No → **Not Sliding Window**
✅ Yes → Go to Step 2

---

## STEP 2: Does the window move monotonically?

Meaning:

* Expanding **only worsens or improves** the condition predictably

❌ No → **Prefix Sum / HashMap**

* Example: Subarray sum = K (with negatives)

✅ Yes → Go to Step 3

---

## STEP 3: Is window size FIXED?

✅ Yes → **Fixed Sliding Window**

* Max Average Subarray
* Anagrams
* Sliding Window Maximum

❌ No → Go to Step 4

---

## STEP 4: Are you asked for:

### 🔹 Longest window satisfying constraint?

→ **Variable Sliding Window (maximize)**

Examples:

* Longest Substring Without Repeating
* Fruit Into Baskets

---

### 🔹 Shortest window satisfying constraint?

→ **Variable Sliding Window (minimize)**

Examples:

* Minimum Window Substring
* Minimum Size Subarray Sum

---

### 🔹 Count of valid subarrays?

→ **Variable Sliding Window + Count Trick**

Examples:

* Subarray Product < K
* Bounded Maximum

---

## STEP 5: Is the answer SPACE monotonic (not the array)?

→ **Binary Search on Answer**

Examples:

* Koko Eating Bananas
* Capacity to Ship Packages
* Min Speed to Arrive on Time

📌 Rule:

> If you can write `ok(x)` → Binary Search

---

# 🧠 ONE-LINE CHEAT RULES (MEMORIZE)

* **Sliding Window** → contiguous + monotonic validity
* **Prefix Sum** → exact count / negative numbers
* **Binary Search** → monotonic answer space

---

## 🎯 FINAL INTERVIEW POWER LINE

Use this confidently:

> “Since the constraint behaves monotonically with expansion, a sliding window guarantees O(n) time.”

---

If you want next:

* 🔥 **20-day company-wise DSA execution plan**
* 🔥 **Mock interview with follow-up traps**
* 🔥 **When NOT to use sliding window (trick questions)**

Just say the word.
