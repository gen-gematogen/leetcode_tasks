class Solution {
public:
    string reverseOnlyLetters(string S) {
        int pos = 0;
        int n = S.size();
        int i = n - 1;
        
        while (pos < i){
            while (pos < n && (S[pos] < 'a' || S[pos] > 'z') && (S[pos] < 'A' || S[pos] > 'Z')) pos++;
            
            if (S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z'){
                swap(S[pos++], S[i]);
            }
            i--;
        }
        
        return S;
    }
};
