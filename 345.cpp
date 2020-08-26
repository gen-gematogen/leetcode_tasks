class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        while (l < r){
            while (l < n && vow.find(s[l]) == vow.end()) l++;
            
            while (r >= 0 && vow.find(s[r]) == vow.end()) r--;
            
            if (l >= r) break;
            
            swap(s[l++], s[r--]);
        }
        
        return s;
    }
};
