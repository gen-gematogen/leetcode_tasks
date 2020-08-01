class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        bool validFl = true;
        
        for (int i = 1; i < n; ++i){
            if ((isupper(word[i]) && !isupper(word[i - 1])) || (!isupper(word[i]) && isupper(word[i - 1]) && i > 1)){
                validFl = false;
                break;
            }
        }
        
        return validFl;
    }
};
