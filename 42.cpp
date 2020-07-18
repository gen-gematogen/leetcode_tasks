class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n == 0){
            return 0;
        }

        vector<int> max_suf(height.size());

        max_suf[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; --i){
            max_suf[i] = max(max_suf[i + 1], height[i]);
        }

        int max_pref = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; ++i){
            max_pref = max(max_pref, height[i]);

            ans += max(0, min(max_pref, max_suf[i]) - height[i]);
        }

        return ans;
    }
};
