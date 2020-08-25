class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n / 2; ++j){
                swap(A[i][j], A[i][n - j - 1]);
                A[i][j] = 1 - A[i][j];
                A[i][n - j - 1] = 1 - A[i][n - j - 1];
            }
            
            if (n % 2) A[i][n / 2] = 1 - A[i][n / 2]; 
        }
        
        return A;
    }
};
