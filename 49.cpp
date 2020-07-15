class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>*> anagrams;

        for (auto cur_str: strs){
            vector<char> used_leters(26);

            for (auto let:cur_str){
                used_leters[let - 'a'] += 1;
            }

            string key = "";

            for (auto it:used_leters){
                key += 'a' + it;
            }

            auto it = anagrams.find(key);

            if (it != anagrams.end()){
                it->second->push_back(cur_str);              
            } else{
                vector<string>* v = new vector<string> ();
                v->push_back(cur_str);
                anagrams.insert(make_pair(key, v));
            }
        }

        vector<vector<string>> ans;

        for (auto it: anagrams){
            ans.push_back({});
            for (auto word: *(it.second)){
                ans[ans.size() - 1].push_back(word);
            }
        }
        
        return ans;
    }
};
