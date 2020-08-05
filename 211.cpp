class Node{
public:
    Node* next[26];
    bool end;
    
    Node(){
        end = false;
        memset(next, NULL, sizeof(next));
    }
    
    void add(char c) {
        next[c - 'a'] = new Node;
    }
    
    Node* get(char c) {
        return next[c - 'a'];
    }
};

class WordDictionary {
private:
    Node* root = nullptr;
    
    bool find(string word, Node* root, int pos){
        int n = word.size();
        
        for (int i = pos; i < n && root; ++i){
            if (word[i] != '.') root = root->get(word[i]);
            
            else{
                bool fl = false;
                
                for (int j = 0; j < 26; ++j){
                    fl = fl || find(word, root->get('a' + j), i + 1);
                
                    if (fl) break;
                }
                
                return fl;
            }
        }
        
        return root && root->end;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto it = root;
        
        for (char c: word){
            if (!it->get(c)) it->add(c);
            
            it = it->get(c);
        }
        
        it->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
