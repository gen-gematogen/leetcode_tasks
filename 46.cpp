class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size());
        vector<int> cur;

        genPerm(ans, nums, cur, used, 0);

        return ans;
    }

private:
    void genPerm(vector<vector<int>>& ans, vector<int>& nums, vector<int>& cur, vector<bool>& used, int n){
        if (n == nums.size()){
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); ++i){
            if (used[i] == false){
                used[i] = true;
                cur.push_back(nums[i]);

                genPerm(ans, nums, cur, used, n + 1);

                cur.pop_back();
                used[i] = false;
            }
        }
    }
};
