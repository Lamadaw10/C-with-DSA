//LeetCode Problem -47
//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set> // Include unordered_set for tracking duplicates
using namespace std;

void helper(vector<int>& nums, vector<vector<int>>& ans, unsigned int start)
{
    if(start == nums.size())
    {
        ans.push_back(nums); //stores the current permutation
        return;
    }
    
    unordered_set<int> seen;    //set track to seen elements
    for(unsigned int i = start; i < nums.size(); i++)
    {
        if(seen.find(nums[i]) != seen.end())
        {
            continue; //skip duplicates
        }
        seen.insert(nums[i]); //mark the element as seen
        swap(nums[i], nums[start]); //swap to create the new permutation
        helper(nums, ans, start + 1); //recurse with next index
        swap(nums[i], nums[start]); //backtrack to restore the original state
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    sort(nums.begin(), nums.end()); //sort to make sure permutation are generated in order
    vector<vector<int>> ans;
    helper(nums, ans, 0); //start backtracking from index 0
    return ans;
}

int main()
{
    int n;
    cin >> n; //input size of the array
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i]; //input array elements
    }
    vector<vector<int>> result = permuteUnique(nums); //get all unique permutation
    for(unsigned int i = 0; i < result.size(); i++)
    {
        for(unsigned int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}