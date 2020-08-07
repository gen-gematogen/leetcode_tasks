class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>()); //STL SOLUTION
        
        return nums[k - 1];*/
        
        int n = nums.size(); //code not finished
        int l = 0;
        int r = n - 1;
        
        while (true){
            int medPos = split(nums, l, r);
            
            if (medPos == n - k + 1) return medPos;
            
            if (medPos > n - k + 1) r = medPos;
            else l = medPos;
        }
        
        return 0;
    }

private:   
    int split(vector<int>& nums, int l, int r){
        int val = nums[(l + r) / 2];
        
        while (l <= r){
            while (nums[l] < val) l++;
            
            while (nums[r] > val) r--;
            
            if (l >= r) break;
            
            swap(nums[l++], nums[r--]);
        }
        
        return r;
    }
};
