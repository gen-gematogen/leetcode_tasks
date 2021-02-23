class Solution {
public:
    void wiggleSort(vector<int>& nums) {   
        int n = nums.size();
        vector<int> sorted(n);
        
        sort(nums.begin(), nums.end());
            
        int pos = 1;
        
        for (int i = n - 1; i > (n - 1) / 2; --i){
            sorted[pos] = nums[i];
            pos += 2;
        }
        
        pos = 0;
            
        for (int i = (n - 1) / 2; i >= 0; --i){
            sorted[pos] = nums[i];
            pos += 2;
        }
        
        nums = sorted;
    }
};
