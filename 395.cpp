class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k || s.size() == 0){
            return 0;
        }

        if (k == 0){
            return s.size();
        }

        unordered_map<char, int> letters;

        for (char i: s){
            letters[i]++;
        }

        int pos = 0;
        while (pos < s.size() && letters[s[pos]] >= k) pos++;

        if (pos == s.size()){
            return s.size();
        }

        int left = longestSubstring(s.substr(0, pos), k);

        while (pos < s.size() && letters[s[pos]] < k) pos++;
        
        if (pos == s.size()){
            return left;
        }

        int right = longestSubstring(s.substr(pos), k);

        return max(left, right);
    }
};
