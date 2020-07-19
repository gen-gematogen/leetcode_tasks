class Solution {
public:
    vector<int> num;

    Solution(vector<int>& nums) {
        num = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return num;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = num.size();
        vector<int> shuffled(num);
        
        for (int i = 0; i < n; ++i){
            int pos = rand() % (n - i);

            swap(shuffled[i], shuffled[i + pos]);
        }

        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
