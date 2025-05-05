class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDivide(nums, maxOperations, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    bool canDivide(const vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;

        for (int num : nums) {
            if (num > penalty) {
                operations += (num - 1) / penalty; 
            }
        }

        return operations <= maxOperations;
    }
};
