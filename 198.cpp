class Solution {
public:
    /*int rob(vector<int>& nums) { //with rray
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
    }*/
    
    int rob(vector<int>& nums){ //without array
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
    
        int  prevMax = nums[0];
        int last = nums[1];
        int cur;
        
        for (int i = 2; i < n; ++i){
            cur = max(prevMax, 0) + nums[i];
            prevMax = max(prevMax, last);
            last = cur;
        }
        
        return max(prevMax, last);
    }
};
