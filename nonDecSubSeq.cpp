#include <bits/stdc++.h>
using namespace std;
// LC 491
class Solution {
    public: 
        int n;
        
        void bt(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& result) {
            if (curr.size() >= 2) {
                result.push_back(curr);
            }
    
            unordered_set<int> st; // To prevent duplicate elements at this recursion level
            
            for (int i = idx; i < n; i++) {
                // Ensure increasing order & avoid duplicates
                if ((curr.empty() || nums[i] >= curr.back()) && st.find(nums[i]) == st.end()) {
                    curr.push_back(nums[i]);   // Choose the element
                    bt(nums, i + 1, curr, result); // Move to the next index
                    curr.pop_back();           // Backtrack
    
                    st.insert(nums[i]); // Mark this element to prevent duplicate usage
                }
            }
        }
    
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            n = nums.size();
            vector<vector<int>> result;
            vector<int> curr;
            bt(nums, 0, curr, result);
            return result;
        }
    };
//     # Problem: Find all increasing subsequences of length >= 2 from nums[]
// # Approach: Backtracking + HashSet to avoid duplicate selections in one recursion level
// # 
// # 1. Start from index 0, and try adding elements to the current sequence
// # 2. Ensure elements are in non-decreasing order
// # 3. Use a hash set to avoid choosing the same element twice in one recursion level
// # 4. If a valid subsequence is formed (size >= 2), store it in result
// # 5. Use backtracking:
// #     - Add element to the sequence
// #     - Explore further with recursion
// #     - Remove the element (pop_back) to try other possibilities
// # 6. Return all possible valid subsequences
// #
// # Complexity: Exponential O(2^N), as we explore all subsets
    
    // # Example:
    // # Input: [4,6,7,7]
    // # Output: [[4,6], [4,6,7], [4,6,7,7], [4,7], [4,7,7], [6,7], [6,7,7], [7,7]]
    
