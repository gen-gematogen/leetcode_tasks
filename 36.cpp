class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<vector<bool>>> cells (3, vector<vector<bool>> (3, vector<bool> (9))); //checking cells 3x3

        for (int i = 0; i < 9; ++i){ //checking lines
            vector<bool> used(9);

            for (int j = 0; j < 9; ++j){
                if (board[i][j] != '.'){
                    if (used[board[i][j] - '1'] == false)
                        used[board[i][j] - '1'] = true;
                    else 
                        return false;

                    if (cells[i / 3][j / 3][board[i][j] - '1'] == false)
                        cells[i / 3][j / 3][board[i][j] - '1'] = true;
                    else 
                        return false;
                }
            }
        }

        for (int i = 0; i < 9; ++i){ //checking columns
            vector<bool> used(9);

            for (int j = 0; j < 9; ++j){
                if (board[j][i] != '.'){
                    if (used[board[j][i] - '1'] == false)
                        used[board[j][i] - '1'] = true;
                    else 
                        return false;
                }
            }
        }

        return true;
    }
};
