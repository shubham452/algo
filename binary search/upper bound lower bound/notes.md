
For **binary search bounds**, remember only 2 templates:

---

## ✅ LOWER BOUND (first index where value ≥ target)

```cpp
int lowerBound(vector<int>& a, int target) {
    int l = 0, r = a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= target)   r = mid;
        else                   l = mid + 1;
    }
    return l; // first index where a[i] >= target
}
```

---

## ✅ UPPER BOUND (first index where value > target)

```cpp
int upperBound(vector<int>& a, int target) {
    int l = 0, r = a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] > target)   r = mid;
        else                  l = mid + 1;
    }
    return l; // first index where a[i] > target
}
```

---

### 🔥 Single Solid Concept

| Bound           | Condition          | Moves                    |
| --------------- | ------------------ | ------------------------ |
| **Lower Bound** | `a[mid] >= target` | shrink right (`r = mid`) |
| **Upper Bound** | `a[mid] > target`  | shrink right (`r = mid`) |

Else → move left (`l = mid + 1`).

---



---

### Key Takeaway

Just remember these 2 lines mentally:

```
LOWER → a[mid] >= target  → r = mid
UPPER → a[mid] >  target  → r = mid
```

That's it.
Use the same two functions everywhere — no confusion. 🚀
