class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AB;

        for (int a: A){
            for (int b: B){
                AB[a+b]++;
            }
        }

        unordered_map<int, int> CD;

        for (int c: C){
            for (int d: D){
                CD[c+d]++;
            }
        }
        
        int ans = 0;

        for (auto i: AB){
            ans += i.second * CD[-i.first];
        }

        return ans;
    }
};
