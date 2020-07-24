class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) { //not best space solution
        if (!board.size() || !board[0].size()) return;
        
        updateField(board, 0, 0);
    }
    
    void updateField(vector<vector<int>>& board, int x, int y){
        int liveCells = neighbours(board, x, y);

        if (y + 1 < board[0].size()) updateField(board, x, y + 1);
        else if (x + 1 < board.size()) updateField(board, x + 1, 0);
        
        if (liveCells < 2) board[x][y] = 0;
        else if (liveCells == 3) board[x][y] = 1;
        else if (liveCells > 3) board[x][y] = 0;
    }
    
    int neighbours(vector<vector<int>>& board, int x, int y){
        int liveCells = 0;
        
        for (int i = -1; i < 2; ++i){
            for (int j = -1; j < 2; ++j){
                if ((i | j) && x + i >= 0 && y + j >= 0 && x + i < board.size() && y + j < board[0].size() && board[x + i][y + j]) liveCells++;
            }
        }
        
        return liveCells;
    }
};
