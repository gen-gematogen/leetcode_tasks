class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                if (st.empty())
                    return false;

                char cur = st.top();
                st.pop();

                if (cur == '(' && s[i] == ')' || cur == '{' && s[i] == '}' || cur == '[' && s[i] == ']')
                    continue;
                return false;
            }
        }

        if (st.empty())
            return true;

        return false;
    }
};
