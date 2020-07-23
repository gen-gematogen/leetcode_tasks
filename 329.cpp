class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        
        int pathLen = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> counted(n, vector<int> (m));

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                pathLen = max(pathLen, dfs(matrix, counted, i, j));
            }
        }

        return pathLen;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& counted, int x, int y){
        if (counted[x][y]) return counted[x][y];
        
        int way = 0;

        if (x > 0 && matrix[x - 1][y] < matrix[x][y]){
            way = max(way, dfs(matrix, counted, x - 1, y));
        } if (x < matrix.size() - 1 && matrix[x + 1][y] < matrix[x][y]){
            way = max(way, dfs(matrix, counted, x + 1, y));
        } if (y > 0 && matrix[x][y - 1] < matrix[x][y]){
            way = max(way, dfs(matrix, counted, x, y - 1));
        } if (y < matrix[0].size() - 1 && matrix[x][y + 1] < matrix[x][y]) {
            way = max(way, dfs(matrix, counted, x, y + 1));
        }
        
        counted[x][y] = way + 1;

        return way + 1;
    }
};
