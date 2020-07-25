class Solution {
public:
    int numSquares(int n) { //DP
        vector<int> nums(n + 1, INT_MAX);
        
        nums[0] = 0;
        
        for (int i = 1; i <= n; ++i){
            for (int j = 1; i - j * j >= 0; ++j){
                nums[i] = min(nums[i], nums[i - j * j] + 1);
            }
        }
        
        return nums[n];
    }
};

/* if we add static array of nums, than it works faster on multiple tests because ans is precalculated already for some of them
