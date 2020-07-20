class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windMax(n - k + 1);
        int curMax = INT_MIN;

        for (int i = 0; i < k; ++i){
            curMax = max(curMax, nums[i]);
        }

        windMax[0] = curMax;

        for (int i = 1; i <= n - k; ++i){
            if (nums[i - 1] == curMax){
                //find new max
                curMax = INT_MIN;

                for (int j = i; j < i + k; ++j){
                    curMax = max(curMax, nums[j]);
                }
            } else{
                curMax = max(curMax, nums[i + k - 1]);
            }

            windMax[i] = curMax;
        }

        return windMax;
    }
};
