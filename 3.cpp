class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == ""){
            return 0;
        }

        int l = 0;
        int r = 1;
        int len = 1;

        vector<int> used(200);

        used[s[l]] = 1;

        while (r < s.size()){
            while (r < s.size() && !used[s[r]]){
                used[s[r++]] = 1;
            }

            len = max(len, r - l);

            while (r < s.size()  && s[l] != s[r]){
                used[s[l++]] = 0;               
            }

            l++;
            r++;
        }

        len = max(len, r - l);

        return len;
    }
};
