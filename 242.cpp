class Solution {
public:
    /*bool isAnagram(string s, string t) { //USING USED ARRAY
        vector<int> lettersC(26);
        vector<int> lettersT(26);
        
        for (char c: s) lettersC[c - 'a']++;
        
        for (char c: t) lettersT[c - 'a']++;
        
        for (int i = 0; i < 26; ++i){
            if (lettersC[i] != lettersT[i]) return false;
        }
        
        return true;
    }*/
    
    bool isAnagram(string s, string t){
        unordered_map<char, int> lettersC;
        unordered_map<char, int> lettersT;
        
        for (char c: s) lettersC[c]++;
        
        for (char c: t) lettersT[c]++;
        
        for (auto it: lettersC){
            if (it.second != lettersT[it.first]) return false;
            
            lettersT.erase(it.first);
        }
        
        if (lettersT.size()) return false;
        
        return true;
    }
};
