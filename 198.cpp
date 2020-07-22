class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> money(n);
        int maxMoney = nums[0];
        
        money[0] = nums[0];
        money[1] = nums[1];
        
        for (int i = 2; i < n; ++i){
            money[i] = max(0, maxMoney) + nums[i];
            maxMoney = max(maxMoney, money[i - 1]);
        }
        
        return max(maxMoney, money[n - 1]);
    }
};
