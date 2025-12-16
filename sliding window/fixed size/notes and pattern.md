Perfect.
Below are **INTERVIEW-GRADE, EXACT templates** for **every sliding-window pattern** you’ll see in those lists.

These are **copy-paste mental models**, not just code.

---

# 🧠 SLIDING WINDOW — MASTER MAP

| Pattern                | Window           | DS Used         |
| ---------------------- | ---------------- | --------------- |
| Fixed sum / avg        | Fixed            | Variables       |
| Fixed freq             | Fixed            | Hash / Array    |
| Fixed distinct         | Fixed            | HashSet         |
| Fixed + Deque          | Fixed            | Monotonic deque |
| Fixed + Heap           | Fixed            | Two heaps       |
| Fixed + Math transform | Fixed            | Deque           |
| Pick from ends         | Fixed complement | Prefix sum      |
| Multi-window DP        | Fixed            | DP + prefix     |
| Variable window        | Expand / shrink  | Hash            |

---

## 1️⃣ FIXED WINDOW — SUM / AVERAGE

### Used in

* Maximum Average Subarray I
* Number of Subarrays ≥ Threshold
* K Radius Subarray Averages

### 🧠 Idea

Keep running sum, add right, remove left.

### ✅ Template

```cpp
long long sum = 0;
int l = 0;

for (int r = 0; r < n; r++) {
    sum += nums[r];

    if (r - l + 1 > k) {
        sum -= nums[l];
        l++;
    }

    if (r - l + 1 == k) {
        // use sum
    }
}
```

📌 **Invariant:** window size is always `k`.

---

## 2️⃣ FIXED WINDOW — FREQUENCY MATCH

### Used in

* Find All Anagrams in a String
* Permutation in String

### 🧠 Idea

Track frequency difference between pattern and window.

### ✅ Template

```cpp
vector<int> freq(26, 0);
for (char c : p) freq[c - 'a']++;

int l = 0, need = p.size();

for (int r = 0; r < s.size(); r++) {
    if (freq[s[r] - 'a']-- > 0)
        need--;

    if (r - l + 1 > p.size()) {
        if (freq[s[l] - 'a']++ >= 0)
            need++;
        l++;
    }

    if (need == 0)
        // valid window
}
```

📌 **Invariant:** `need == 0` ⇒ perfect match.

---

## 3️⃣ FIXED WINDOW — DISTINCT ELEMENTS

### Used in

* Maximum Sum of Distinct Subarrays With Length K
* Substrings with Distinct Characters

### 🧠 Idea

No duplicates allowed inside window.

### ✅ Template

```cpp
unordered_map<int,int> cnt;
long long sum = 0;
int l = 0;

for (int r = 0; r < n; r++) {
    cnt[nums[r]]++;
    sum += nums[r];

    while (cnt[nums[r]] > 1) {
        cnt[nums[l]]--;
        sum -= nums[l];
        l++;
    }

    if (r - l + 1 == k) {
        // valid window
        cnt[nums[l]]--;
        sum -= nums[l];
        l++;
    }
}
```

📌 **Invariant:** all elements are unique.

---

## 4️⃣ FIXED WINDOW — MONOTONIC DEQUE (MAX / MIN)

### Used in

* Sliding Window Maximum

### 🧠 Idea

Deque stores indices in decreasing order.

### ✅ Template

```cpp
deque<int> dq;

for (int i = 0; i < n; i++) {
    while (!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();

    dq.push_back(i);

    if (dq.front() <= i - k)
        dq.pop_front();

    if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
}
```

📌 **Invariant:** deque front is always window max.

---

## 5️⃣ FIXED WINDOW — MEDIAN (TWO HEAPS)

### Used in

* Sliding Window Median

### 🧠 Idea

Two heaps maintain balance.

### ✅ Template (Conceptual)

```cpp
maxHeap (left), minHeap (right)

add(x):
    push x to left
    balance

remove(x):
    mark x removed
    prune heaps
    balance

balance:
    size(left) == size(right) OR +1
```

📌 **Invariant:** median always on top of heaps.

---

## 6️⃣ FIXED WINDOW — ORDER STATISTICS (BEAUTY)

### Used in

* Sliding Subarray Beauty

### 🧠 Idea

Frequency array (range bounded).

### ✅ Template

```cpp
int freq[101] = {0};

add(x): freq[x + 50]++
remove(x): freq[x + 50]--

getKthSmallest():
    walk freq[]
```

📌 **Invariant:** frequency always reflects window.

---

## 7️⃣ FIXED WINDOW — MATHEMATICAL TRANSFORM

### Used in

* Max Value of Equation

### 🧠 Idea

Rewrite:

```
yi + yj + |xi - xj|
= (yi - xi) + (yj + xj)
```

### ✅ Template

```cpp
deque<pair<int,int>> dq; // (y - x, x)

for (j = 0; j < n; j++) {
    while (!dq.empty() && x[j] - dq.front().second > k)
        dq.pop_front();

    ans = max(ans, dq.front().first + y[j] + x[j]);

    while (!dq.empty() && dq.back().first <= y[j] - x[j])
        dq.pop_back();

    dq.push_back({y[j] - x[j], x[j]});
}
```

📌 **Invariant:** deque max candidate always valid.

---

## 8️⃣ FIXED WINDOW — PICK FROM ENDS

### Used in

* Maximum Points You Can Obtain from Cards

### 🧠 Idea

Pick k from ends = remove n−k subarray with min sum.

### ✅ Template

```cpp
int window = n - k;
int sum = total;
int curr = 0;

for (int i = 0; i < n; i++) {
    curr += nums[i];
    if (i >= window)
        curr -= nums[i - window];
    if (i >= window - 1)
        sum = min(sum, curr);
}
return total - sum;
```

---

## 9️⃣ MULTI FIXED WINDOW — DP + PREFIX

### Used in

* Maximum Sum of 3 Non-Overlapping Subarrays

### 🧠 Idea

* Precompute window sums
* Left best + right best

### ✅ Template (Concept)

```cpp
prefixSum
windowSum[]
leftBest[]
rightBest[]
```

📌 **Invariant:** windows never overlap.

---

## 🔟 VARIABLE WINDOW (For Transition)

### Used in

* Longest Substring Without Repeating
* Minimum Window Substring

### ✅ Template

```cpp
unordered_map<char,int> cnt;
int l = 0;

for (int r = 0; r < n; r++) {
    cnt[s[r]]++;

    while (invalid window) {
        cnt[s[l]]--;
        l++;
    }

    // update answer
}
```

---

## 🧠 FINAL INTERVIEW LINE

> “The window size is fixed; only state changes, so we update in O(1).”

---

## 🎯 WHAT TO DO NEXT

1️⃣ Memorize **pattern → template**, not problems
2️⃣ Practice **1 problem per pattern**
3️⃣ Explain **window invariant out loud**

If you want:

* 🔥 **One dry-run per template**
* 🔥 **When sliding window FAILS**
* 🔥 **Binary Search vs Sliding Window decision tree**

Say the word.
