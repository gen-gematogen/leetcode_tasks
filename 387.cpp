class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> letters;

        for (int i = 0; i < s.size(); ++i){
            if (letters.find(s[i]) != letters.end()){
                letters[s[i]].first++;
            } else{
                letters[s[i]] = make_pair(1, i);
            }
        }

        int pos = s.size();

        for (auto it: letters){
            if (it.second.first == 1){
                pos = min(pos, it.second.second);
            }
        }

        if (pos == s.size()) return -1;

        return pos;
    }
};
