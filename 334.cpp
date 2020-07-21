class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        if (n < 3){
            return false;
        }

        vector<int> maxOnSuf(n);

        maxOnSuf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i){
            maxOnSuf[i] = max(nums[i], maxOnSuf[i + 1]);
        }

        int minOnPref = nums[0];

        for (int i = 1; i < n - 1; ++i){
            if (minOnPref < nums[i] && maxOnSuf[i + 1] > nums[i]){
                return true;
            }

            minOnPref = min(minOnPref, nums[i]);
        }

        return false;
    }
};
