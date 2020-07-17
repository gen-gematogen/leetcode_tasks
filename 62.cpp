class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0){
            return 0;
        }

        vector<vector<int>> field(m, vector<int> (n));

        for (int i = 0; i < m; ++i){
            field[i][0] = 1;
        }

        for (int j = 1; j < n; ++j){
            field[0][j] = 1;
        }

        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                field[i][j] = field[i - 1][j] + field[i][j - 1];
            }
        }

        return field[m - 1][n - 1];
    }
};
