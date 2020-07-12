class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        if (nums.size() < 3){
            return answer;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i){
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r){
                if (nums[l] + nums[r] > -nums[i])
                    r--;
                else if (nums[l] + nums[r] < -nums[i])
                    l++;
                else {
                    vector<int> tripl = {nums[i], nums[l], nums[r]};

                    answer.push_back(tripl);

                    while (l < nums.size() && tripl[1] == nums[l])
                        l++;

                    while (r >= 0 && tripl[2] == nums[r])
                        r--;
                }
            }

            while ((i < nums.size() - 1) && nums[i + 1] == nums[i])
                i++;
        }

        return answer;
    }
};
