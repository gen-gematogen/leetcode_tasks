class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int it: nums){
            freq[it]++;
        }

        vector<pair<int, int>> sort_freq;

        for (auto it: freq){
            sort_freq.push_back(make_pair(it.second, it.first));
        }

        sort(sort_freq.begin(), sort_freq.end());

        vector<int> ans;

        for (auto i = sort_freq.end() - 1; i >= sort_freq.end() - k; --i){
            ans.push_back(i->second);
        }

        return ans;
    }
};
