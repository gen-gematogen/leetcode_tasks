class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r = 0;
        bool ans = true;

        for (int i = 0; i < nums.size() - 1; ++i){
            r = max(r, i + nums[i]);

            if (i >= r){
                ans = false;
            }
        }

        return ans;
    }
};
