class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){
            return 0;
        }

        int ans = 0;
        int share = 0;
        int buy_val;

        for (int i = 0; i < prices.size() - 1; ++i){
            if (share && prices[i] > prices[i + 1] && prices[i] - buy_val > 0){
                share = 0;
                ans += prices[i] - buy_val;
            } else if (!share){
                if (prices[i] < prices[i + 1]){            
                    share = 1;
                    buy_val = prices[i];
                }
            }
        }

        if (share && prices[prices.size() - 1] - buy_val > 0){
            ans += prices[prices.size() - 1] - buy_val;
        }

        return ans;
        
    }
};
