class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        bool k = 1;
        
        while (fast != slow || k){
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
            k = 0;
        }
        
        slow = nums[0];
        
        while (fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
        
    }
};
