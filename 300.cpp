class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*int n = nums.size(); o(n^2) dynamics
        
        if (!n) return 0;
        
        vector<int> seq(n);
        int maxSeq = 0;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (nums[j] < nums[i]) seq[i] = max(seq[i], seq[j]);
            }
            
            seq[i] += 1;
            
            maxSeq = max(maxSeq, seq[i]);
        }
        
        return maxSeq;*/
        
        int n = nums.size(); //O(nlogn) monster
        
        if (!n) return 0;
        
        vector<int> seqLen(n + 1, INT_MAX);
        int maxLen = 0;
        
        seqLen[0] = INT_MIN;
        
        for (int i = 0; i < n; ++i){
            auto pos = lower_bound(seqLen.begin(), seqLen.end(), nums[i]);
            
            if (*pos > nums[i]){
                *pos = nums[i];
                maxLen = max(maxLen, (int) (pos - seqLen.begin()));
            } 
        }
        
        return maxLen;
    }
};
