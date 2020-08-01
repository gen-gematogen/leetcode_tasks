class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sufSum = 0;
        
        for (int i: nums) sufSum += i;
        
        int prefSum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i){
            if (prefSum == sufSum - nums[i]) return i;
            
            prefSum += nums[i];
            sufSum -= nums[i];
        }
        
        return -1;
    }
};
