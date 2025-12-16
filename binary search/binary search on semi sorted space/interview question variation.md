Great — this is exactly how **top candidates prepare**.
Below is a **company-wise Binary Search (Semi-Sorted Space) problem mapping**, based on **actual interview + OA patterns**.

---

## 🏢 FAANG / MAANG

### 🔹 Google

**Focus:** Pattern recognition, clean invariants

| Problem Type    | Frequently Asked                  |
| --------------- | --------------------------------- |
| Peak / Mountain | Find Peak Element                 |
| Rotated Array   | Find Min in Rotated Array         |
| Answer Space    | Koko Eating Bananas, Min Capacity |
| Monotonic Logic | Binary Search on Answer           |

👉 **What Google tests**

* Can you *prove* why one side is discarded?
* Can you explain invariants clearly?

---

### 🔹 Meta (Facebook)

**Focus:** Correctness under edge cases

| Problem Type         | Frequently Asked                  |
| -------------------- | --------------------------------- |
| Rotated Array Search | Search in Rotated Sorted Array    |
| Duplicates           | Search in Rotated Sorted Array II |
| Peak Logic           | Peak Index in Mountain Array      |

👉 **Meta cares about**

* Duplicates handling
* Boundary safety
* Clean edge-case reasoning

---

### 🔹 Amazon

**Focus:** Scalability & monotonic checks

| Problem Type  | Frequently Asked               |
| ------------- | ------------------------------ |
| Answer Space  | Min Days to Ship Packages      |
| Rotated Array | Find Minimum                   |
| Pattern Break | Single Element in Sorted Array |

👉 **Amazon wants**

* Correct `ok(x)` function
* Time complexity justification

---

### 🔹 Apple

**Focus:** Precision & low-level correctness

| Problem Type   | Frequently Asked           |
| -------------- | -------------------------- |
| Peak Element   | Find Peak Element          |
| Parity Pattern | Single Non Duplicate       |
| Index Logic    | Lower/Upper Bound variants |

👉 **Apple checks**

* Index math
* Off-by-one safety
* Clean loops

---

### 🔹 Netflix

**Focus:** Hard constraints + clean math

| Problem Type  | Frequently Asked          |
| ------------- | ------------------------- |
| Answer Space  | Binary Search on Capacity |
| Peak / Valley | Local extrema problems    |

👉 **Netflix wants**

* Elegant invariants
* No hacks

---

## 🏢 PRODUCT COMPANIES (India & Global)

### 🔹 Microsoft

**Focus:** Fundamentals + variants

| Problem Type  | Frequently Asked      |
| ------------- | --------------------- |
| Rotated Array | Search + Min          |
| Peak          | Peak Element          |
| Answer Space  | Aggressive Cows style |

---

### 🔹 Uber

**Focus:** Decision-making logic

| Problem Type  | Frequently Asked |
| ------------- | ---------------- |
| Answer Space  | Min Speed / Time |
| Rotated Array | Search           |

---

### 🔹 Atlassian

**Focus:** Reasoning over code

| Problem Type            | Frequently Asked      |
| ----------------------- | --------------------- |
| Binary Search on Answer | Capacity / Scheduling |
| Pattern Break           | Index parity problems |

---

### 🔹 Adobe

**Focus:** Variants & corner cases

| Problem Type         | Frequently Asked |
| -------------------- | ---------------- |
| Rotated + Duplicates | Search II        |
| Peak Variants        | Multiple peaks   |

---

## 🏢 STARTUPS (High-Growth)

### 🔹 Razorpay / PhonePe / Paytm

**Focus:** Real-world constraints

| Problem Type   | Frequently Asked       |
| -------------- | ---------------------- |
| Answer Space   | Min Rate / Load        |
| Rotated Search | Data indexing problems |

---

### 🔹 Swiggy / Zomato

**Focus:** Optimization

| Problem Type | Frequently Asked       |
| ------------ | ---------------------- |
| Answer Space | Min Time / Capacity    |
| Peak         | Demand spike detection |

---

## 🏢 SERVICE-BASED (Still Important)

### 🔹 TCS / Infosys / Wipro

**Focus:** Classic patterns

| Problem Type  | Frequently Asked    |
| ------------- | ------------------- |
| Rotated Array | Search              |
| Peak          | Find Peak           |
| Bounds        | Lower / Upper Bound |

---

## 🧠 How Interviewers Escalate Difficulty

1️⃣ **Simple sorted array**
2️⃣ **Rotated array**
3️⃣ **Rotated + duplicates**
4️⃣ **Binary search on answer**
5️⃣ **Proof & invariants**

If you fail at step 2 → interview ends.

---

## 🎯 What YOU Should Prioritize (Smart Prep)

Since you’re already strong in DSA, do this:

### ✅ Must-Do (90% Coverage)

* Find Peak Element
* Find Minimum in Rotated Array
* Search in Rotated Sorted Array
* Binary Search on Answer (Koko, Capacity)

### 🚀 Differentiators (Top 10%)

* Rotated + duplicates
* Parity pattern problems
* Explaining invariants out loud

---

## 🧠 Interview Golden Sentence

Use this when stuck:

> “At any index, at least one half is guaranteed to satisfy a monotonic property, allowing binary search.”

Interviewers **love** this.

---

Excellent. Below is a **battle-tested, interview-focused “Exact 15-Problem Shortlist”** for **Binary Search & Semi-Sorted Space**, **company-wise**.

These are **not random** — they are **pattern-covering** problems.
If you can solve these **cleanly + explain**, you’re interview-ready.

---

# 🟢 GOOGLE (Reasoning + Invariants)

### 🎯 What Google wants

* Explain **why** binary search works
* Strong monotonic reasoning
* Clean boundaries

### ✅ Exact 15

1. Find Peak Element
2. Peak Index in a Mountain Array
3. Find Minimum in Rotated Sorted Array
4. Search in Rotated Sorted Array
5. Search in Rotated Sorted Array II
6. Koko Eating Bananas
7. Capacity To Ship Packages Within D Days
8. Split Array Largest Sum
9. Minimize Max Distance to Gas Station
10. Median of Two Sorted Arrays
11. First Bad Version
12. Guess Number Higher or Lower
13. Find Duplicate Number (Binary Search on Answer)
14. Minimum Time to Complete Trips
15. Aggressive Cows (classic)

---

# 🟣 META (Facebook) — Edge Cases & Robustness

### 🎯 What Meta wants

* Handle duplicates
* Defensive coding
* Boundary correctness

### ✅ Exact 15

1. Search in Rotated Sorted Array
2. Search in Rotated Sorted Array II
3. Find Minimum in Rotated Sorted Array
4. Find Minimum in Rotated Sorted Array II
5. Find Peak Element
6. Peak Index in a Mountain Array
7. Single Element in a Sorted Array
8. First and Last Position of Element
9. Find K Closest Elements
10. Kth Smallest Element in Sorted Matrix
11. Median of Two Sorted Arrays
12. Find Duplicate Number
13. Binary Search Template I
14. Binary Search Template II
15. Binary Search Template III

---

# 🟠 AMAZON (Monotonic Feasibility)

### 🎯 What Amazon wants

* Binary search on **answer**
* Production-safe logic
* Correct `ok(x)`

### ✅ Exact 15

1. Koko Eating Bananas
2. Capacity To Ship Packages Within D Days
3. Split Array Largest Sum
4. Min Days to Make Bouquets
5. Min Speed to Arrive on Time
6. Find Peak Element
7. Find Minimum in Rotated Sorted Array
8. Search in Rotated Sorted Array
9. Find Duplicate Number
10. First Bad Version
11. Single Element in Sorted Array
12. Magnetic Force Between Two Balls
13. Aggressive Cows
14. Allocate Minimum Pages
15. Painter’s Partition Problem

---

# 🍎 APPLE (Precision & Index Math)

### 🎯 What Apple wants

* Index correctness
* No off-by-one
* Clean loops

### ✅ Exact 15

1. Binary Search
2. Lower Bound
3. Upper Bound
4. Find First and Last Position
5. Single Element in Sorted Array
6. Find Peak Element
7. Peak Index in Mountain Array
8. Search in Rotated Sorted Array
9. Find Minimum in Rotated Sorted Array
10. Guess Number Higher or Lower
11. First Bad Version
12. Search Insert Position
13. Find K Closest Elements
14. Median of Two Sorted Arrays
15. Kth Smallest Element in Sorted Matrix

---

# 🟡 MICROSOFT (Fundamentals + Variants)

### 🎯 What Microsoft wants

* Template mastery
* Adaptability

### ✅ Exact 15

1. Binary Search
2. Search Insert Position
3. First and Last Position
4. Find Peak Element
5. Peak Index in Mountain Array
6. Search in Rotated Sorted Array
7. Find Minimum in Rotated Sorted Array
8. Single Element in Sorted Array
9. Find Duplicate Number
10. Koko Eating Bananas
11. Split Array Largest Sum
12. Capacity to Ship Packages
13. Aggressive Cows
14. Allocate Pages
15. Median of Two Sorted Arrays

---

# 🔵 UBER / ATLASSIAN / NETFLIX (Optimization Logic)

### 🎯 What they want

* Optimization via monotonic search
* Strong feasibility logic

### ✅ Exact 15

1. Koko Eating Bananas
2. Min Speed to Arrive on Time
3. Capacity to Ship Packages
4. Split Array Largest Sum
5. Minimum Time to Complete Trips
6. Magnetic Force Between Two Balls
7. Aggressive Cows
8. Find Peak Element
9. Peak Index in Mountain Array
10. Find Minimum in Rotated Sorted Array
11. Search in Rotated Sorted Array
12. Find Duplicate Number
13. Median of Two Sorted Arrays
14. Kth Smallest Element in Sorted Matrix
15. Find K Closest Elements

---

## 🧠 MASTER RULE (Very Important)

If you solve **any one company’s 15 properly**, you can solve **80% of others**.

The problems overlap because the **patterns are identical**.

---

## 🎯 20-Day Smart Plan (Optional)

* **Days 1–5** → Peak + Rotated Array
* **Days 6–10** → Answer Space
* **Days 11–15** → Parity + Bounds
* **Days 16–20** → Mixed mock interviews

---

## 💬 Interview Power Line (Use This)

> “I’m not binary searching the array, I’m binary searching the decision space.”

Instant +points.

---

If you want next:

* 🔥 **One-page cheat sheet per problem**
* 🔥 **Brute → Binary Search conversion guide**
* 🔥 **Live mock interview simulation**

Just tell me.
If you want next:

* 🔥 **Exact 15-problem shortlist per company**
* 🔥 **Mock interview walkthrough**
* 🔥 **How to derive BS from brute force live**

Just say the word.
