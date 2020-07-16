class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0){
            return {};
        }

        vector<pair<int, int>> brackets;

        for (int i = 0; i < intervals.size(); ++i){
            brackets.push_back(make_pair(intervals[i][0], 0)); //begining of interval
            brackets.push_back(make_pair(intervals[i][1], 1)); //ending of interval
        }

        sort(brackets.begin(), brackets.end());

        int opened = 0;
        int beg_of_int = 0;
        vector<vector<int>> merged_int;

        for (int i = 0; i < intervals.size() * 2; ++i){
            if (brackets[i].second == 0){
                opened++;

                if (opened == 1){
                    beg_of_int = i;
                }
            } else{
                opened--;

                if (opened == 0){
                    merged_int.push_back({brackets[beg_of_int].first, brackets[i].first});
                }
            }
        }

        return merged_int;
    }
};
