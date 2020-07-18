class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       for (int i = 0; i < board.size(); ++i){
           for (int j = 0; j < board[0].size(); ++j){
               if (search(board, word, i, j, 0)){
                   return true;
               }
           }
        }

        return false; 
    }

private:
    bool search(vector<vector<char>>& board, string word, int x, int y, int len){
        if (word.size() == len){
            return true;
        }

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[len]){
            return false;
        }

        board[x][y] += 26;

        bool ans =  search(board, word, x - 1, y, len + 1) || search(board, word, x + 1, y, len + 1) ||
        search(board, word, x, y - 1, len + 1) || search(board, word, x, y + 1, len + 1);

        board[x][y] -= 26;

        return ans;
    }
};
