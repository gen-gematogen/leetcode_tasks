class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums_end(k);

        k %= nums.size();

        for (int i = 0; i < k; ++i){
            nums_end[i] = nums[nums.size() - k + i];
        }

        for (int i = nums.size() - 1; i >= k; --i){
            nums[i] = nums[i - k];
        }

        for (int i = 0; i < k; ++i){
            nums[i] = nums_end[i];
        }
    }
};
