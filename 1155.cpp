class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {        
        vector<vector<int>> ways(d, vector<int> (target));
        
        f = min(f, target);
        
        for (int i = 0; i < f; ++i){
            ways[0][i] = 1;
        }
        
        for (int i = 1; i < d; ++i){
            for (int j = i; j < target; ++j){
                for (int k = 1; k <= f; ++k){
                    if (j >= k){
                        ways[i][j] += ways[i - 1][j - k];
                        ways[i][j] %= 1000000007;
                    }
                }
            }
        }
        
        return ways[d - 1][target - 1];
    }
};
