class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pref_max(nums.size());

        pref_max[0] = nums[0];
        int mx = pref_max[0];

        for (int i = 1; i < nums.size(); ++i){
            pref_max[i] = max(pref_max[i - 1], 0) + nums[i];
            mx = max(mx, pref_max[i]);
        }

        return mx;
    }
};  
