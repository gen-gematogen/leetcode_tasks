class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vect_of_num = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        if (digits.size() == 0)
            return ans;

        stringGen(vect_of_num, ans, digits, "", 0);

        return ans;
    }

private:
    void stringGen(vector<string>& vect_of_num, vector<string>& ans, string digits, string cur_str, int pos){
        if (pos >= digits.size()){
            ans.push_back(cur_str);
            return;
        }
        
        for (int i = 0; i < vect_of_num[digits[pos] - '2'].size(); ++i){
            stringGen(vect_of_num, ans, digits, cur_str + vect_of_num[digits[pos] - '2'][i], pos + 1);
        }
    }
};
