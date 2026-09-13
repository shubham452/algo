Perfect — this list is **Dynamic Size (Variable) Sliding Window**.
I’ll break it down **exactly the way interviewers think**:

* ✅ **Patterns**
* ✅ **Question types**
* ✅ **Canonical template per pattern**
* ✅ **Mapping of YOUR listed problems → pattern**

---

# 🧠 DYNAMIC (VARIABLE) SLIDING WINDOW — BIG PICTURE

### Core rule (this never changes):

> **Right pointer expands the window, left pointer shrinks it to restore validity.**

This is used when:

* Window size is **NOT fixed**
* Constraint is based on **counts / sum / distinct / max-min**
* You are asked **longest / shortest / count of valid subarrays**

---

# 🧩 PATTERN 1: **Longest window with constraint ≤ K**

*(Maximize length)*

### 🔍 Question type

> Find the **longest subarray / substring** satisfying a constraint

### 🧠 Generic condition

```
while (window is invalid)
    shrink from left
```

### ✅ Canonical Template

```cpp
int l = 0;
for (int r = 0; r < n; r++) {
    add(nums[r]);

    while (invalid()) {
        remove(nums[l]);
        l++;
    }

    ans = max(ans, r - l + 1);
}
```

---

### 📌 Problems using this pattern

* Longest Substring Without Repeating Characters
* Longest Repeating Character Replacement
* Max Consecutive Ones III
* Fruit Into Baskets
* Frequency of the Most Frequent Element
* Longest Continuous Subarray with Absolute Diff ≤ Limit
* Longest Subarray of 1s After Deleting One Element

---

# 🧩 PATTERN 2: **Shortest window with constraint ≥ target**

*(Minimize length)*

### 🔍 Question type

> Find the **minimum length subarray** satisfying a condition

### 🧠 Generic condition

```
while (window is valid)
    try to shrink and update answer
```

### ✅ Canonical Template

```cpp
int l = 0;
for (int r = 0; r < n; r++) {
    add(nums[r]);

    while (valid()) {
        ans = min(ans, r - l + 1);
        remove(nums[l]);
        l++;
    }
}
```

---

### 📌 Problems using this pattern

* Minimum Size Subarray Sum
* Minimum Window Substring
* Minimum Consecutive Cards to Pick Up
* Minimum Operations to Reduce X to Zero

---

# 🧩 PATTERN 3: **Count subarrays satisfying constraint**

*(Counting, not length)*

### 🔍 Question type

> Count **number of valid subarrays**

### 🧠 Key trick

Once window is valid at `[l…r]`,
👉 **all subarrays starting from `l` to `r` are valid**

### ✅ Canonical Template

```cpp
int l = 0;
long long count = 0;

for (int r = 0; r < n; r++) {
    add(nums[r]);

    while (invalid()) {
        remove(nums[l]);
        l++;
    }

    count += (r - l + 1);
}
```

---

### 📌 Problems using this pattern

* Subarray Product Less Than K
* Count Number of Nice Subarrays
* Count Number of Good Subarrays
* Number of Subarrays with Bounded Maximum
* Count the Number of Substrings with Dominant Ones

---

# 🧩 PATTERN 4: **At Most K distinct**

*(Classic frequency window)*

### 🔍 Question type

> Subarrays with **at most K distinct elements**

### ✅ Canonical Template

```cpp
unordered_map<int,int> freq;
int l = 0;

for (int r = 0; r < n; r++) {
    freq[nums[r]]++;

    while (freq.size() > k) {
        freq[nums[l]]--;
        if (freq[nums[l]] == 0)
            freq.erase(nums[l]);
        l++;
    }

    ans += (r - l + 1);
}
```

---

### 📌 Problems using this pattern

* Fruit Into Baskets
* Subarrays with K Different Integers *(via atMost(K) − atMost(K−1))*

---

# 🧩 PATTERN 5: **AtMost trick (Hard but powerful)**

### 🔍 Question type

> Exactly K something

### 🧠 Trick

```
exactlyK = atMost(K) - atMost(K - 1)
```

### 📌 Problems using this pattern

* Subarrays with K Different Integers
* Count Number of Nice Subarrays

---

# 🧩 PATTERN 6: **Window with max–min constraint**

*(Two deques)*

### 🔍 Question type

> `max(window) - min(window) ≤ limit`

### ✅ Canonical Template

```cpp
deque<int> maxD, minD;
int l = 0;

for (int r = 0; r < n; r++) {
    while (!maxD.empty() && nums[maxD.back()] < nums[r])
        maxD.pop_back();
    while (!minD.empty() && nums[minD.back()] > nums[r])
        minD.pop_back();

    maxD.push_back(r);
    minD.push_back(r);

    while (nums[maxD.front()] - nums[minD.front()] > limit) {
        if (maxD.front() == l) maxD.pop_front();
        if (minD.front() == l) minD.pop_front();
        l++;
    }

    ans = max(ans, r - l + 1);
}
```

---

### 📌 Problems using this pattern

* Longest Continuous Subarray With Absolute Diff ≤ Limit

---

# 🧩 PATTERN 7: **Prefix + Sliding Window Hybrid**

### 🔍 Question type

> Reduce / remove elements from ends

### 📌 Problems

* Minimum Operations to Reduce X to Zero
  *(Convert to longest subarray with sum = total − x)*

---

# 🧠 YOUR LIST → PATTERN MAP (IMPORTANT)

| Problem                                 | Pattern   |
| --------------------------------------- | --------- |
| Longest Substring Without Repeating     | Pattern 1 |
| Longest Repeating Character Replacement | Pattern 1 |
| Max Consecutive Ones III                | Pattern 1 |
| Fruit Into Baskets                      | Pattern 4 |
| Subarray Product < K                    | Pattern 3 |
| Minimum Size Subarray Sum               | Pattern 2 |
| Minimum Window Substring                | Pattern 2 |
| Nice Subarrays                          | Pattern 5 |
| Bounded Maximum                         | Pattern 3 |
| Frequency of Most Frequent Element      | Pattern 1 |
| K Different Integers                    | Pattern 5 |
| Max Abs Diff ≤ Limit                    | Pattern 6 |

---

# 🧠 INTERVIEW GOLDEN RULE (Dynamic Window)

> “Right pointer explores possibilities, left pointer restores validity.”

Say this → interviewer **knows you understand sliding window deeply**.

---

## 🎯 What to do next (recommended)

1️⃣ Memorize **patterns, not problems**
2️⃣ Practice **one problem per pattern**
3️⃣ Always explain **why shrinking is correct**

If you want next:

* 🔥 **One dry-run per dynamic pattern**
* 🔥 **Sliding Window vs Prefix Sum vs Binary Search**
* 🔥 **Top 10 trickiest sliding window traps**

Just tell me 👍
