class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> amt(3);

        for (int i = 0; i < nums.size(); ++i){
            amt[nums[i]]++;
        }

        int k = 0;

        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < amt[i]; ++j){
                nums[k++] = i;
            }
        }
    }
};
