//https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, vector<int>& temp, unordered_map<int, int>& freq) {
        int n = nums.size();
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        
        for (auto& pair : freq) {
            if (pair.second > 0) {
                temp.push_back(pair.first);
                pair.second--;
                solve(nums, temp, freq);
                temp.pop_back();
                pair.second++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int, int> freq;
    
        for (int num : nums) {
            freq[num]++;
        }
        
        solve(nums, temp, freq);
        return ans;
    }
};
/*
    sort(nums.begin(), nums.end());
    do {
        result.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return result;
    */
