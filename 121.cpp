class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){
            return 0;
        }

        vector<int> max_on_suf(prices.size());

        max_on_suf[prices.size() - 1] = prices[prices.size() - 1];

        for (int i = prices.size() - 2; i >= 0; --i){
            max_on_suf[i] = max(max_on_suf[i + 1], prices[i]);
        }

        int ans = 0;
        int min_on_pref = prices[0];

        for (int i = 0; i < prices.size() - 1; ++i){
            ans = max(ans, max_on_suf[i + 1] - min_on_pref);

            min_on_pref = min(min_on_pref, prices[i + 1]);
        }

        return ans;
    }
};
