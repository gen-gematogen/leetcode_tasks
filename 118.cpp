class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;

        if (!numRows){
            return nums;
        }

        nums.push_back({1});

        for (int i = 1; i < numRows; ++i){
            nums.push_back({});
            for (int j = 0; j <= nums[i - 1].size(); ++j){
                nums[i].push_back(0);
                if (j != 0){
                    nums[i][j] += nums[i - 1][j - 1];
                }
                if (j != nums[i - 1].size()){
                    nums[i][j] += nums[i - 1][j];
                }
            }
        }

        return nums;
    }
};
