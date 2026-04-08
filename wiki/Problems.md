# Problems

This page lists all LeetCode problems that have been solved in this repository, along with a brief description and the approach used.

---

## Index

| # | Problem | Difficulty | Approach |
|---|---------|------------|----------|
| 1 | [Two Sum](#1-two-sum) | Easy | Brute Force |
| 9 | [Palindrome Number](#9-palindrome-number) | Easy | Number Reversal |
| 14 | [Longest Common Prefix](#14-longest-common-prefix) | Easy | Sort and Compare |
| 20 | [Valid Parentheses](#20-valid-parentheses) | Easy | Stack |
| 22 | [Generate Parentheses](#22-generate-parentheses) | Medium | Recursion / DFS |
| 26 | [Remove Duplicates from Sorted Array](#26-remove-duplicates-from-sorted-array) | Easy | Set |
| 27 | [Remove Element](#27-remove-element) | Easy | Two Pointers |
| 28 | [Find the Index of the First Occurrence in a String](#28-find-the-index-of-the-first-occurrence-in-a-string) | Easy | Sliding Window |
| 485 | [Max Consecutive Ones](#485-max-consecutive-ones) | Easy | Linear Scan |
| 1022 | [Sum of Root to Leaf Binary Numbers](#1022-sum-of-root-to-leaf-binary-numbers) | Easy | DFS / Recursion |
| 1470 | [Shuffle the Array](#1470-shuffle-the-array) | Easy | Index Mapping |
| 1929 | [Concatenation of Array](#1929-concatenation-of-array) | Easy | Array Append |

---

## 1. Two Sum

**Link:** [leetcode.com/problems/two-sum](https://leetcode.com/problems/two-sum/)  
**Difficulty:** Easy  
**File:** [1.TwoSum.py](../Codes/1.TwoSum.py)

Given an array of integers and a target, return the indices of the two numbers that add up to the target.

**Approach:** Brute force nested loop. For each pair of elements, check whether their sum equals the target and return their indices.

---

## 9. Palindrome Number

**Link:** [leetcode.com/problems/palindrome-number](https://leetcode.com/problems/palindrome-number/)  
**Difficulty:** Easy  
**File:** [9.Palindrome.py](../Codes/9.Palindrome.py)

Determine whether an integer reads the same forwards and backwards.

**Approach:** Reverse the digits of the number by extracting remainders in a loop, then compare the reversed value to the original.

---

## 14. Longest Common Prefix

**Link:** [leetcode.com/problems/longest-common-prefix](https://leetcode.com/problems/longest-common-prefix/)  
**Difficulty:** Easy  
**File:** [14.Longest Common Prefix.py](<../Codes/14.Longest Common Prefix.py>)

Find the longest string that is a prefix of all strings in the given array.

**Approach:** Sort the array lexicographically. The longest common prefix of the entire array must be the common prefix of the first and last strings after sorting. Compare character by character until a mismatch is found.

---

## 20. Valid Parentheses

**Link:** [leetcode.com/problems/valid-parentheses](https://leetcode.com/problems/valid-parentheses/)  
**Difficulty:** Easy  
**File:** [20.ValidParenthesis.py](../Codes/20.ValidParenthesis.py)

Given a string containing only `(`, `)`, `{`, `}`, `[`, and `]`, determine if the input is valid (brackets are opened and closed in the correct order).

**Approach:** Use a stack. Push opening brackets onto the stack. When a closing bracket is encountered, check that the top of the stack holds the matching opening bracket.

---

## 22. Generate Parentheses

**Link:** [leetcode.com/problems/generate-parentheses](https://leetcode.com/problems/generate-parentheses/)  
**Difficulty:** Medium  
**File:** [22.GenerateParenthesis.py](../Codes/22.GenerateParenthesis.py)

Given n pairs of parentheses, generate all combinations of well-formed parentheses.

**Approach:** Depth-first search (DFS) with backtracking. Track the number of open and close brackets added so far and only add a bracket when it keeps the string valid.

---

## 26. Remove Duplicates from Sorted Array

**Link:** [leetcode.com/problems/remove-duplicates-from-sorted-array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)  
**Difficulty:** Easy  
**File:** [26.RemoveDuplicatesFromSortedArray.py](../Codes/26.RemoveDuplicatesFromSortedArray.py)

Remove duplicates from a sorted array in-place and return the number of unique elements.

**Approach:** Convert to a set to eliminate duplicates, sort the result, and assign it back to the original list in-place.

---

## 27. Remove Element

**Link:** [leetcode.com/problems/remove-element](https://leetcode.com/problems/remove-element/)  
**Difficulty:** Easy  
**File:** [27.RemoveElement.py](../Codes/27.RemoveElement.py)

Remove all occurrences of a given value in-place from an array and return the new length.

**Approach:** Two-pointer technique. Iterate through the array and overwrite positions that hold the target value with elements that do not.

---

## 28. Find the Index of the First Occurrence in a String

**Link:** [leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)  
**Difficulty:** Easy  
**File:** [28.FindtheIndexoftheFirstOccurrenceinString.py](../Codes/28.FindtheIndexoftheFirstOccurrenceinString.py)

Return the index of the first occurrence of a needle string in a haystack string, or -1 if not found.

**Approach:** Sliding window. At each position in the haystack, extract a substring of the same length as the needle and compare.

---

## 485. Max Consecutive Ones

**Link:** [leetcode.com/problems/max-consecutive-ones](https://leetcode.com/problems/max-consecutive-ones/)  
**Difficulty:** Easy  
**File:** [485.MaxConsecutiveOnes.py](../Codes/485.MaxConsecutiveOnes.py)

Given a binary array, find the maximum number of consecutive 1s.

**Approach:** Linear scan with a running counter. Increment a counter for each 1, reset it on a 0, and track the maximum value seen.

---

## 1022. Sum of Root to Leaf Binary Numbers

**Link:** [leetcode.com/problems/sum-of-root-to-leaf-binary-numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)  
**Difficulty:** Easy  
**File:** [1022.SumOfRootToLeafBinaryNumbers.py](../Codes/1022.SumOfRootToLeafBinaryNumbers.py)

Given a binary tree where each node has value 0 or 1, each root-to-leaf path represents a binary number. Return the sum of all such numbers.

**Approach:** Recursive DFS. Build the binary string path as the tree is traversed. At each leaf node, convert the collected binary string to an integer and add it to the total.

---

## 1470. Shuffle the Array

**Link:** [leetcode.com/problems/shuffle-the-array](https://leetcode.com/problems/shuffle-the-array/)  
**Difficulty:** Easy  
**File:** [1470.ShuffleTheArray.py](../Codes/1470.ShuffleTheArray.py)

Given an array of 2n elements in the form `[x1, x2, ..., xn, y1, y2, ..., yn]`, return the shuffled array as `[x1, y1, x2, y2, ..., xn, yn]`.

**Approach:** Create a result array of size 2n. Place elements from the first half at even indices and elements from the second half at odd indices.

---

## 1929. Concatenation of Array

**Link:** [leetcode.com/problems/concatenation-of-array](https://leetcode.com/problems/concatenation-of-array/)  
**Difficulty:** Easy  
**File:** [1929.ConcatenationOfArray.py](../Codes/1929.ConcatenationOfArray.py)

Given an integer array, return a new array that is the concatenation of the array with itself.

**Approach:** Copy all elements of the original array into a temporary list, then append each element to the original array to form the concatenation.
