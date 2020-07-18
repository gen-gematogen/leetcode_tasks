class Solution {
public:
    int numDecodings(string s) {
        vector<char> v(s.size());

        for (int i = 0; i < s.size(); ++i){
            v[i] = s[i];
        }

        return cntNum(v, 0);
    }

private:
    int cntNum(vector<char>& s, int pos){
        if (s.size() - pos == 1){
            return s[pos] == '0' ? 0 : 1;
        }

        if (s.size() - pos == 0){
            return 1;
        }

        if (s[pos] == '1' || (s[pos] == '2' && s[pos + 1] <= '6')){
            return cntNum(s, pos + 1) + cntNum(s, pos + 2);
        }
        
        if (s[pos] == '0' || s[pos + 1] == '0'){
            return 0;
        }

        return cntNum(s, pos + 1);
    }
};
