class Solution {
public:
    string countAndSay(int n) {
        if (n == 1){
            return "1";
        }

        string prev = countAndSay(n - 1);
        string cur = "";

        for (int i = 0; i < prev.size();){
            int len = 1;

            for (int j = i + 1; j < prev.size(); ++j){
                if (prev[j - 1] == prev[j]){
                    len++;
                } else
                    break;
            }

            cur = cur + to_string(len) + prev[i];
            i += len;
        }

        return cur;
    }
};
