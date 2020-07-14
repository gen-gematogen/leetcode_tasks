class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; ++i){
            int pos = binSearch(nums1, nums2[i], 0, m + i);

            for (int j = m + i; j > pos; --j){
                nums1[j] = nums1[j - 1];
            }

            nums1[pos] = nums2[i];
        }
    }

private:
    int binSearch(vector<int>& nums, int x, int L, int R){
        int l = L - 1;
        int r = R;

        while (r - l > 1){
            int m = (r + l) / 2;

            if (nums[m] > x){   
                r = m;
            } else {
                l = m;
            }
        }

        return r;
    }
};
