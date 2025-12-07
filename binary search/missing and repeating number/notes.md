For all of these “weird” binary-search problems, the **process is always the same**.
Forget the story (“missing”, “duplicate”, etc.) and think in terms of:

> **“I want the smallest / largest `x` such that some condition is true.”**

That’s it. Then you binary search on `x`.

---

## 0. Two types of binary search in these problems

1. **On index** – classic: array is sorted, we search on `idx`.
2. **On value/answer** – array may or may not be sorted, but there is a monotonic condition in terms of a *value* (like number itself, count, k, etc.).
   This is usually called **binary search on answer**.

Most of the problems in your screenshot are type (2).

---

## 1. Generic “binary search on answer” template

### Step 1 – Decide what you are searching on

Pick a variable `x`:

* “smallest `x` such that …” → **lower bound pattern**
* “largest `x` such that …” → **upper bound pattern**

### Step 2 – Define a monotonic predicate

Write a function `ok(x)` that returns `true` or `false` and is monotonic:

* If you search for **smallest `x` with `ok(x) == true`**
  then: `F F F ... F T T T ... T`
* If you search for **largest `x` with `ok(x) == true`**
  then: `T T T ... T F F F ... F`

If you can define such an `ok(x)`, you can always do BS.

### Step 3 – Choose search space `[lo, hi]`

Take **smallest possible x** as `lo`, **largest possible x** as `hi`.
Sometimes that’s indexes, sometimes values, sometimes even an answer like time, speed, etc.

### Step 4 – Standard code

**Lower bound (first true)**:

```cpp
// smallest x such that ok(x) == true
int lo = L, hi = R;              // [L, R]
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (ok(mid)) hi = mid;       // mid is good, try left
    else lo = mid + 1;           // mid is bad, go right
}
int ans = lo;                    // or hi (same)
```

**Upper bound (last true)**:

```cpp
// largest x such that ok(x) == true
int lo = L, hi = R;
while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2; // bias to right
    if (ok(mid)) lo = mid;            // mid is good, go right
    else hi = mid - 1;                // mid is bad, go left
}
int ans = lo;                         // or hi
```

If you remember just these two patterns, you can solve all the “variations”.

---

## 2. How this applies to your specific problems

I’ll show the thought process (not just final code).

### (A) Kth Missing Positive Number

**Idea**

* Array `arr` is sorted & positive.
* For any number `x` ≥ 1, we can count how many positives ≤ `x` are **missing**.
* Let `missing(x)` = `x - count(arr[i] ≤ x)`
  (because out of `1..x` there are `x` numbers total, and `count` present → rest missing).

Observe:
if `x1 < x2` then `missing(x1) ≤ missing(x2)` → **monotonic**.

We want the **smallest `x` such that `missing(x) ≥ k`**.

So:

```cpp
bool ok(long long x) {
    // count how many arr[i] <= x
    int c = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    long long missing = x - c;
    return missing >= k;       // predicate
}
```

Search space?

* Minimum answer is `1`
* Maximum roughly `k + arr.back()` → safe hi: `1e9` or `k + n` depending on constraints.

Then use **lower bound template** with this `ok(x)`.

---

### (B) Find the Duplicate Number (1..n, n+1 numbers)

Binary search on answer as well.

* For any value `x`, count how many numbers in `nums` are `≤ x`.
* If there were **no duplicate ≤ x**, count should be `≤ x`.
* If `count > x`, some number in range `[1, x]` is duplicated.

So we want the **smallest `x` such that `count(nums[i] ≤ x) > x`** → monotonic.

```cpp
bool ok(int x) {
    int cnt = 0;
    for (int v : nums) if (v <= x) cnt++;
    return cnt > x;    // true means duplicate is <= x
}
```

Search `x` in `[1, n]` with **lower bound pattern**.

---

### (C) Missing Number (0..n with one missing)

Simple version doesn’t even need BS (sum / xor), but BS way:

If you sort `nums`, then:

* In a perfect array `[0,1,2,...]`, we have `nums[i] == i`.
* When a number is missing, from that index onwards: `nums[i] > i`.

So predicate:

> `ok(i) = (nums[i] > i)`

This is **false** while indices are correct (no missing yet), and becomes **true** from first missing onward:

`F F F ... F T T T ...`

We want the **smallest index `i` with `nums[i] > i`**,
and that index itself is the missing number.

This is an **index-based lower bound**.

```cpp
int lo = 0, hi = n - 1;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] > mid) hi = mid;
    else lo = mid + 1;
}
int missing = (nums[lo] == lo ? n : lo); // handle “no break” case
```

---

### (D) Single Element in a Sorted Array

Array sorted, every element appears twice except one.

Observation:

* Before the single element, pairs start at **even** indices: `0,1`, `2,3`, ...
* After the single element, pairs start at **odd** indices.

Predicate:

> “Is the single element on the left side (including mid)?”

One standard way: ensure `mid` is even, compare `nums[mid]` with `nums[mid+1]`.

```cpp
int lo = 0, hi = n - 1;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (mid % 2 == 1) mid--;        // force to even
    if (nums[mid] == nums[mid + 1]) // left side is full pairs
        lo = mid + 2;
    else
        hi = mid;
}
int single = nums[lo];
```

Here you are not explicitly writing `ok(x)`, but it’s the same logic:
“Is single element ≤ mid?”

---

## 3. Mental checklist when you see a new “variation”

When a new LeetCode/GfG problem says “binary search” but it’s not obvious:

1. **Can I phrase the answer as “smallest x such that …” or “largest x such that …”?**
2. **Can I define a function `ok(x)` which is monotonic in `x`?**
3. **What is the search domain `[lo, hi]` for `x`?**
4. **Is this a lower bound (first true) or upper bound (last true) problem?**
5. Plug into one of the two **fixed templates**.


