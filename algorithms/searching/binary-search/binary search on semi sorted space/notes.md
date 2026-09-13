
Below is a **clean, interview-ready template per category** for **Binary Search on Semi-Sorted Space**.
These are the **exact patterns** top companies expect you to recognize.

---

## 🧠 CATEGORY 1: **Peak / Mountain / Unimodal Array**

**(Find Peak Element, Peak Index in Mountain Array)**

### 🔍 When to use

* Array goes **up then down**
* Need **any peak** or **mountain peak**
* No duplicates issue with neighbors

### 🧠 Key Observation

If `nums[mid] < nums[mid+1]` → you are on the **increasing slope**, peak is **right**
Else → you are on the **decreasing slope**, peak is **left or mid**

---

### ✅ Template

```cpp
int findPeak(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] < nums[mid + 1]) {
            l = mid + 1;   // peak on right
        } else {
            r = mid;       // peak on left or mid
        }
    }
    return l;  // peak index
}
```

📌 **Why it works:**
You always discard one slope completely.

---

## 🧠 CATEGORY 2: **Rotated Sorted Array (No Duplicates)**

**(Search in Rotated Sorted Array, Find Minimum)**

### 🔍 When to use

* Sorted array rotated
* **One half is always sorted**

---

### 🧠 A) Find Minimum in Rotated Array

### Key Observation

* Compare `nums[mid]` with `nums[r]`

---

### ✅ Template

```cpp
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[r]) {
            l = mid + 1;  // min on right
        } else {
            r = mid;      // min on left or mid
        }
    }
    return nums[l];
}
```

---

### 🧠 B) Search Target in Rotated Array

### Key Observation

* One side is sorted
* Check if target lies inside that sorted range

---

### ✅ Template

```cpp
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target) return mid;

        if (nums[l] <= nums[mid]) { // left sorted
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } 
        else { // right sorted
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}
```

---

## 🧠 CATEGORY 3: **Rotated Sorted Array (With Duplicates)**

**(Search II, Find Min II)**

### 🔍 When to use

* Rotated array
* **Duplicates exist**

### 🧠 Problem

Duplicates break the “sorted half” guarantee.

---

### ✅ Template (Key Trick: Shrink Boundaries)

```cpp
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else if (nums[mid] < nums[r]) {
            r = mid;
        } else {
            r--; // remove duplicate
        }
    }
    return nums[l];
}
```

📌 **Worst case degrades to O(n)** — unavoidable.

---

## 🧠 CATEGORY 4: **Binary Search on Answer**

**(Find Duplicate Number, Min Capacity, Koko Bananas, etc.)**

### 🔍 When to use

* Search space is **values**, not indices
* You can write `ok(x)` → true/false
* Condition is **monotonic**

---

### 🧠 Key Idea

```text
false false false true true true
```

---

### ✅ Template (Lower Bound on Answer)

```cpp
int binarySearchAnswer(int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (ok(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
```

Example `ok(x)`:

```cpp
bool ok(int x) {
    // count / capacity / feasibility check
}
```

---

## 🧠 CATEGORY 5: **Index Parity / Pattern Break**

**(Single Element in Sorted Array)**

### 🔍 When to use

* Pairs of elements
* One single element breaks pattern

---

### 🧠 Key Observation

* Before single → pairs start at even index
* After single → pairs start at odd index

---

### ✅ Template

```cpp
int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (mid % 2 == 1) mid--;

        if (nums[mid] == nums[mid + 1])
            l = mid + 2;
        else
            r = mid;
    }
    return nums[l];
}
```

---

## 🧠 MASTER INTERVIEW RULE

If you can answer **YES** to any of these → Binary Search applies:

* Can I **discard half**?
* Is decision **monotonic**?
* Is there a **structural pattern**?

---

## 🧩 Final Cheat Sheet

| Problem Type         | Template          |
| -------------------- | ----------------- |
| Peak / Mountain      | Slope comparison  |
| Rotated Array        | Sorted half logic |
| Rotated + Duplicates | Shrink boundary   |
| Answer Space         | `ok(mid)`         |
| Pattern Break        | Index parity      |

---

