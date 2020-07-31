class Solution {
public:
    /*bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n - 1][m - 1];
        
        while (r > target && l < target){
            int m = (l + r) / 2;
            
            pair<int, int> newBounds = find(matrix, m);
            
            if (newBounds.first == l && newBounds.second == r) break;
            
            if (newBounds.second <= target) l = newBounds.second;
            else if (newBounds.first >= target) r = newBounds.first;
            else {
                l = newBounds.first;
                r = newBounds.second;
            }
        }
        
        if (l == target || r == target) return true;
        
        return false;
    }
    
    pair<int, int> find(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        int col = 0;
        int line = n - 1;
        int lowOrEq = INT_MIN;
        int greatOrEq = INT_MAX;
        
        while (col < m && line >= 0 && lowOrEq < greatOrEq){
            if (matrix[line][col] <= target) lowOrEq = max(lowOrEq, matrix[line][col++]);          
            else if (matrix[line][col] >= target) greatOrEq = min(greatOrEq, matrix[line--][col]);
        }
        
        return {lowOrEq, greatOrEq};
    }*/
    
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if (!matrix.size() || !matrix[0].size()) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int line = n - 1;
        int col = 0;
        
        while (line >= 0 && col < m){
            if (matrix[line][col] == target) return true;
            else if (matrix[line][col] > target) line--;
            else col++;
        }
        
        return false;
    }
};
