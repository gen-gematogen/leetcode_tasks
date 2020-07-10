class TrieNode{
public:
    bool end;
    vector<TrieNode*> child;

    TrieNode(){
        end = false;
        child = vector<TrieNode*> (26, NULL);
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(vector<string>& words){
        root = new TrieNode();

        for (int i = 0; i < words.size(); ++i){
            AddWord(words[i]);
        }
    }

    void AddWord(string word){
        TrieNode* cur = root;

        for (int i = 0; i < word.size(); ++i){
            int letter = word[i] - 'a';

            if (!(cur->child[letter])){
                cur->child[letter] = new TrieNode();
            }

            cur = cur->child[letter];
        }

        cur->end = true;
    }

    TrieNode* GetRoot(){
        return root;
    }
}; 

class Solution{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->GetRoot();

        set<string> ans_set;

        for (int i = 0; i < board[0].size(); ++i){
            for (int j = 0; j < board.size(); ++j){
                find(board, board[0].size(), board.size(), i, j, ans_set, root, "");
            }
        }

        vector<string> answer;

        for(auto it:ans_set)
            answer.push_back(it);

        return answer;
    }

private:
    void find(vector<vector<char>>& board, int max_x, int max_y, int x, int y, set<string>& ans, TrieNode* node, string word){
        if (x < 0 || x >= max_x || y < 0 || y >= max_y || board[y][x] == ' ')
            return;
        
        if (node->child[board[y][x] - 'a']){
            word += board[y][x];
            node = node->child[board[y][x] - 'a'];

            if (node->end){
                ans.insert(word);
            }

            char tmp = board[y][x];
            board[y][x] = ' ';

            find(board, max_x, max_y, x + 1, y, ans, node, word);
            find(board, max_x, max_y, x - 1, y, ans, node, word);
            find(board, max_x, max_y, x, y + 1, ans, node, word);
            find(board, max_x, max_y, x, y - 1, ans, node, word);

            board[y][x] = tmp;
        }
    }
}; 
