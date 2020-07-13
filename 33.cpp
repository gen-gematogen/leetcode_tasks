class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return -1;
        }

        int rotate = findRotate(nums);

        int pos1 = binSearch(nums, target, 0, rotate + 1);
        int pos2 = binSearch(nums, target, rotate + 1, nums.size());
        
        
        if (pos1 < nums.size() && nums[pos1] == target){
            return pos1;
        }

        if (pos2 < nums.size() && nums[pos2] == target){
            return pos2;
        }

        return -1;
    }

private:
    int binSearch(vector<int>& nums, int target, int L, int R) {
        int l = L;
        int r = R;

        while (r - l > 1){
            int m = (r + l) / 2;

            if (nums[m] > target)
                r = m;
            else
                l = m;
        }

        return l;
    }

    int findRotate(vector<int>& nums){
        int l = 0;
        int r = nums.size();

        while (r - l > 1){
            int m = (r + l) / 2;

            if (nums[m] >= nums[l]){
                l = m;
            } else{
                r = m;
            }
        }

        return l;
    }
};
