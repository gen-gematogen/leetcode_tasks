class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return {-1, -1};
        }

        int l_last = binSearchLast(nums, target);
        int l_first = binSearchFirst(nums, target);

        vector<int> ans(2);

        if (nums[l_first] == target && nums[l_last] == target){
            return {l_first, l_last};
        } else{
            return {-1, -1};
        }
    }

private:
    int binSearchLast(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size();

        while (r - l > 1){
            int m = (r + l) / 2;

            if (nums[m] > target)
                r = m;
            else
                l = m;
        }

        return l;
    }

    int binSearchFirst(vector<int>& nums, int target){
        int l = -1;
        int r = nums.size() - 1;

        while (r - l > 1){
            int m = (r + l) / 2;

            if (nums[m] >= target)
                r = m;
            else
                l = m;
        }

        return r;
    }
};
