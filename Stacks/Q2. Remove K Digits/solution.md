## Problem: Remove K Digits

**Difficulty:** Medium  
**Tags:** stack, greedy, strings  

**Platform:** LeetCode  
**Problem Link:** https://leetcode.com/problems/remove-k-digits/

---

## Problem Statement

Given a numeric string `num` and an integer `k`, remove exactly `k` digits from the string such that the resulting number is the **smallest possible**.

The resulting number:
- Must not contain leading zeros (unless the number is `0`)
- Should return `"0"` if all digits are removed

---

## Approach: Greedy + Monotonic Increasing Stack

This problem is solved using a **greedy strategy** combined with a **monotonic increasing stack**.

### Key Observations:
- Digits on the left have higher place value and impact the number more.
- If a larger digit appears before a smaller digit, removing the larger digit results in a smaller number.
- A stack helps maintain digits in increasing order while processing the string.

---

## Algorithm Steps

1. Initialize an empty string to act as a stack.
2. Traverse each digit in the input string:
   - While the stack is not empty, `k > 0`, and the top of the stack is greater than the current digit:
     - Pop the stack and decrement `k`.
   - Push the current digit onto the stack.
3. If `k > 0` after traversal, remove remaining digits from the end of the stack.
4. Remove leading zeros from the resulting string.
5. If the final string is empty, return `"0"`.

---

## C++ Solution

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }
        int i = 0;
        while (i < stack.size() && stack[i] == '0') {
            i++;
        }
        stack = stack.substr(i);
        return stack.empty() ? "0" : stack;
    }
};
```

## Complexity Analysis
- Time Complexity - O(n)
- Space Complexity - O(n)
