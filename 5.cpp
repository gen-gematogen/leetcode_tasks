class Solution {
public:
    string longestPalindrome(string s) {
        int max_odd = 0;
        int pos_odd;
        int max_even = 0;
        int pos_even;
        int cur_len;

        if (s == ""){
            return s;
        }

        for (int i = 0; i < s.size(); ++i){
            cur_len = 0;

            for (int j = 0; i - j >= 0 && i + j < s.size(); ++j){
                if (s[i - j] != s[i + j])
                    break;
                cur_len += 1;
            }

            if (cur_len > max_odd){
                max_odd = cur_len;
                pos_odd = i;
            }
        }

        for (int i = 0; i < s.size(); ++i){
            cur_len = 0;

            for (int j = 0; i - j - 1 >= 0 && i + j < s.size(); ++j){
                if (s[i - j - 1] != s[i + j])
                    break;
                cur_len += 1;
            }

            if (cur_len > max_even){
                max_even = cur_len;
                pos_even = i;
            }   
        }

        if (max_odd > max_even){
            return s.substr(pos_odd - max_odd + 1, 2 * max_odd - 1);
        }

        return s.substr(pos_even - max_even, 2 * max_even);
    }
};
