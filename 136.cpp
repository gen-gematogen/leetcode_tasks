class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;

        for (int i = 0; i < nums.size(); ++i){
            ans ^= nums[i];
        }

        return ans;
    }
};
