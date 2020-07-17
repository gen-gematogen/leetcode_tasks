class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0){
            return;
        }

        vector<bool> used_col(matrix[0].size());
        vector<bool> used_ln(matrix.size());

        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (matrix[i][j] == 0){
                    used_col[j] = 1;
                    used_ln[i] = 1;
                }
            }
        }

        for (int i = 0; i < used_col.size(); ++i){
            if (used_col[i]){
                for (int j = 0; j < matrix.size(); ++j){
                    matrix[j][i] = 0;
                }
            }
        }

        for (int i = 0; i < used_ln.size(); ++i){
            if (used_ln[i]){
                for (int j = 0; j < matrix[0].size(); ++j){
                    matrix[i][j] = 0;
                }
            }
        }
    }   
};
