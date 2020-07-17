class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size());
        vector<int> cur;
        
        for (int i = 0; i <= nums.size(); ++i){
            genSet(nums, ans, used, cur, i, 0);
        }

        return ans;
    }

private:
    void genSet(vector<int>& nums, vector<vector<int>>& ans, vector<bool>& used, vector<int>& cur, int len, int pos){
        if (len == 0){
            ans.push_back(cur);
            return;
        }

        for (int i = pos; i < nums.size(); ++i){
            if (used[i] == false){
                used[i] = true;
                cur.push_back(nums[i]);
                genSet(nums, ans, used, cur, len - 1, i + 1);
                cur.pop_back();
                used[i] = false;
            }
        }
    }
};
