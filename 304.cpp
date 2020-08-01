class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        precnt.resize(n + 1, vector<int> (m + 1));
        
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                precnt[i][j] = matrix[i - 1][j - 1] + precnt[i - 1][j] + precnt[i][j - 1] - precnt[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (precnt.size() == 0 || precnt[0].size() == 0) return 0;
        
        return precnt[row2 + 1][col2 + 1] + precnt[row1][col1] - precnt[row2 + 1][col1] - precnt[row1][col2 + 1];
    }
    
private:
    vector<vector<int>> precnt;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
