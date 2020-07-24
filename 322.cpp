class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> money(amount + 1, INT_MAX - 1);
        money[0] = 0;
        
        for (int i = 1; i <= amount; ++i){
            for (int j: coins){
                if (i - j >= 0) money[i] = min(money[i], money[i - j] + 1);
            }
        }
        
        if (money[amount] == INT_MAX - 1) return -1;
        
        return money[amount];
    }
};
