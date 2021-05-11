class Solution {
    int sum = 0;
    vector<int> pref_sum;
public:
    Solution(vector<int>& w) {
        srand(time(0));
        
        for (int i = 0; i < w.size(); ++i){
            sum += w[i];
            
            pref_sum.push_back(w[i]);
            
            if (i){
                pref_sum[i] += pref_sum[i - 1];
            } 
        }
    }
    
    int pickIndex() {
        int random = rand() % sum;

        return distance(pref_sum.begin(), upper_bound(pref_sum.begin(), pref_sum.end(), random));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
