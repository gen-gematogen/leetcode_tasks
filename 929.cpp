class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> difemls;
        
        for (string s: emails){
            string curemail = "";
            
            for (int i = 0; i < s.size(); ++i){
                if (s[i] == '@'){
                    curemail += s.substr(i, s.size() - i);
                    break;
                } else if (s[i] == '.') continue;
                else if (s[i] == '+'){
                    while (s[i] != '@') i++;
                    i--;
                } else curemail += s[i];
            }
            
            difemls.insert(curemail);
        }
        
        return difemls.size();
    }
};
