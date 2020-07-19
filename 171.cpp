class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int mult = 1;

        for (int i = s.size() - 1; i >= 0; --i){
            ans += (s[i] - 'A' + 1) * mult;
            
            if (mult <= INT_MAX / 26){
                mult *= 26;
            }
        }

        return ans;
    }
};
