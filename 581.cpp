class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_dup = nums;
        
        sort(nums_dup.begin(), nums_dup.end());
        
        int l = 0;
        
        for (; l < nums.size(); ++l){
            if (nums[l] != nums_dup[l]){
                break;
            }
        }
        
        int r = nums.size() - 1;
        
        for (; r >= 0; --r){
            if (nums[r] != nums_dup[r]){
                break;
            }
        }
        
        return max(r - l + 1, 0);
    }
};
