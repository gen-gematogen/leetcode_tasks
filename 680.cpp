class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        
        while (l < r){
            if (s[l] == s[r]){
                l++;
                r--;
            } else{
                if (isPalindrome(&s[l + 1], &s[r]) || isPalindrome(&s[l], &s[r - 1])) return true;
                
                return false;
            }
        }
        
        return true;
    }

private:
    bool isPalindrome(char* begin, char* end){
        while (begin < end){
            if (*begin != *end){
                return false;
            }
            
            begin++;
            end--;
        }
        
        return true;
    }
};
