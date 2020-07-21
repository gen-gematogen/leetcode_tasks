class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> symbols(26);
        
        for (char c: chars) symbols[c - 'a']++;
        
        int ans = 0;
        
        for (string s: words){
            vector<int> cur(26);
            
            for (char c: s) cur[c - 'a']++;
            
            for (int i = 0; i < 26; ++i){
                if (cur[i] > symbols[i]){
                    ans -= s.size();
                    break;
                }
            }
            
            ans += s.size();
        }
        
        return ans;
    }
};
