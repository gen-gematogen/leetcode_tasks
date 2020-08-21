class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        char letter;
        int pos;
        
        for (int i = 0; i < n; ++i){
            if (indices[i] >= 0){
                letter = s[i];
                pos = indices[i];
                indices[i] = -1;
                
                while (pos >= 0){
                    int tmp = pos;
                    
                    swap(letter, s[pos]);
                    pos = indices[pos];
                    indices[tmp] = -1;
                }
            }
            
            /*for (int it: indices) cout << it << ' ';
            cout << '\n';
            
            cout << s;
            cout << '\n';*/
        }
        
        return s;
    }
};
