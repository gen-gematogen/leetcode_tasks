class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
            return "";

        string pref = "";
        int min_len = strs[0].size();

        for (int i = 1; i < strs.size(); ++i){
            min_len = min(min_len, (int) strs[i].size());
        }

        for (int i = 0; i < min_len; ++i){
            char cur = strs[0][i];

            for (int j = 1; j < strs.size(); ++j){
                if (cur != strs[j][i])
                    return pref;
            }

            pref += cur;
        }

        return pref;
    }
};
