class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()){
            return {};
        }

        std::unordered_map<char, int> letters;

        for (char& c: p){
            letters[c]++;
        }

        std::unordered_map<char, int> cur_letters;

        for (int i = 0; i < p.size() - 1; ++i){
            cur_letters[s[i]]++;
        }

        vector<int> result;

        for (int i = p.size() - 1; i < s.size(); ++i){
            cur_letters[s[i]]++;

            if (i >= p.size()){
                cur_letters[s[i - p.size()]]--;
            }

            bool check = true;

            for (auto it: cur_letters){
                if (it.second != letters[it.first]){
                    check = false;
                    break;
                }
            }

            if (check){
                result.push_back(i - p.size() + 1);
            }
        }

        return result;
    }
};
