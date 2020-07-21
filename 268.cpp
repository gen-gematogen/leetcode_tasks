class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int nxor = 0;
        
        for (int i = 0; i <= n; ++i){
            nxor ^= i;
        }
        
        int numxor = 0;
        
        for (int i = 0; i < n; ++i){
            numxor ^= nums[i];
        }
        
        return nxor ^ numxor;
    }
};
