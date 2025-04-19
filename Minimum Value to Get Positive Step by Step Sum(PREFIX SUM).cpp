class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        int  min1=*min_element(pre.begin(),pre.end());
        int ans=min1;
        if(ans>=1){
            return 1;
        }else
        {
            return abs(ans)+1;
        }
    }
};
