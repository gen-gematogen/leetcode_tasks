class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int sufMult = 1;
        
        for (int i = n - 1; i >= 0; --i){
            result[i] = sufMult;
            sufMult *= nums[i];
        }
        
        int prefMult = 1;
        
        for (int j = 0; j < n; ++j){
            result[j] *= prefMult;
            prefMult *= nums[j];
        }
        
        return result;
    }
};
