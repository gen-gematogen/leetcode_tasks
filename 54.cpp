class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }

        vector<int> spiral;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < (min(m, n) + 1) / 2; ++i){
            for (int j = i; j < n - i; ++j){
                spiral.push_back(matrix[i][j]);
            }

            for (int j = i + 1; j < m - i; ++j){
                spiral.push_back(matrix[j][n - i - 1]);
            }

            if (m % 2 == 0 || i != m / 2){
                for (int j = n - i - 2; j >= i; --j){
                    spiral.push_back(matrix[m - i - 1][j]);
                }
            }

            if (n % 2 == 0 || i != n / 2){
                for (int j = m - i - 2; j > i; --j){
                spiral.push_back(matrix[j][i]);
                }
            }
        }

        return spiral;
    }
};
