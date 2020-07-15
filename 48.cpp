class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i){
            for (int j = i; j < n - i - 1; ++j){
                int tmp1, tmp2;

                tmp1 = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = matrix[i][j];

                tmp2 = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = tmp1;

                tmp1 = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = tmp2;

                matrix[i][j] = tmp1;
            }
        }
    }
};
