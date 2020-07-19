class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int add = n / 5;

        while (add){
            ans += add;
            
            add /= 5;
        }
        
        return ans;
    }
};
