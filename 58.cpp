class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int ans = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i){
            if (s[i] == ' '){
                 if (cnt){
                    ans = cnt;
                    cnt = 0;
                 }
            } else cnt++;
        }
        
        if (cnt){
            ans = cnt;
        }
        
        return ans;
    }
};
