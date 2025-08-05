class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>n;
        for(int i=0;i<k;i++){
           n.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(n.top()<nums[i]){
                n.pop();
                n.push(nums[i]);
            }    
        }
        return n.top();
    }
};
