//LeetCode Problem -46
//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& ans, int start)
{
    if (start == nums.size()) {
        ans.push_back(nums); // Store current permutation
        return;
    }
    
    for (int i = start; i < nums.size(); i++) { // Fix: Corrected semicolon in for loop
        swap(nums[i], nums[start]); // Swap to generate new permutation
        backtrack(nums, ans, start + 1); // Recurse with next element and pass ans
        swap(nums[i], nums[start]); // Backtrack to restore original state
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans; // Store all permutations
    backtrack(nums, ans, 0); // Start backtracking from index 0
    return ans;
}

int main() {
    int n;
    cin >> n; // Input size of the array
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input array elements
    }

    vector<vector<int>> res = permute(nums); // Get all permutations

    // Print all the permutations
    for (unsigned int i = 0; i < res.size(); i++) {
        for (unsigned int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl; // New line after each permutation
    }
    
    return 0;
}
