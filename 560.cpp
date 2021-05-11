class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::vector<int> pref_sum;
        std::unordered_map<int, int> count = {{0, 1}};
        
        for (int i = 0; i < nums.size(); ++i){
            pref_sum.push_back(nums[i]);
            if (i){
                pref_sum[i] += pref_sum[i - 1];   
            }
        }
        
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            int diff = pref_sum[i] - k;
            
            if (count.find(diff) != count.end()){
                cnt += count[diff];
            }

            count[pref_sum[i]]++;
        }
        
        return cnt;
    }
};
