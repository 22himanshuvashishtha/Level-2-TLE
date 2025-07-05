class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(), nums.end()); 
        backtrack(nums, 0, current, ans);
        return ans;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current); 
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, ans);
            current.pop_back(); // Backtrack
        }
    }
};
