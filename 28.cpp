class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;

        string s = needle + "#" + haystack;   

        vector<int> substr_len(s.size());
        int l = 0;
        int r = 0;

        for (int i = 1; i < s.size(); ++i){
            substr_len[i] = max(0, min(r - i + 1, substr_len[i - l]));

            for (int j = i + substr_len[i]; j < s.size(); ++j){
                if (s[j] == s[j - i]){
                    substr_len[i]++;
                    r = j;
                    l = i;
                } else
                    break;
            }
        }

        for (int i = 0; i < s.size(); ++i){
            if (substr_len[i] == needle.size()){
                return i - needle.size() - 1;
            }
        }

        return -1;
    }
};
