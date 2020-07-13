class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        genString(ans, "", n, 0);

        return ans;
    }

private:
    void genString(vector<string>& ans, string cur, int n, int m){
        if (n == 0 && m == 0){
            ans.push_back(cur);
            return;
        }

        if (n){
            genString(ans, cur + "(", n - 1, m + 1);
        } if (m){
            genString(ans, cur + ")", n, m - 1);
        }
    }
};
