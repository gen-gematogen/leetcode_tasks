class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()){
            return {};
        }
        
        std::vector<string> result;
        std::string tmp;

        int counter = 1;

        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] == nums[i - 1] + 1){
                counter++;
            } else{
                if (counter > 1){
                    tmp += std::to_string(nums[i - 1] - (counter - 1)) + "->";
                }

                tmp += std::to_string(nums[i - 1]);
                counter = 1;
                result.push_back(tmp);
                tmp = "";
            }
        }
        
        if (counter > 1){
            tmp += std::to_string(nums[nums.size() - 1] - counter + 1) + "->";
        }

        tmp += std::to_string(nums[nums.size() - 1]);
    
        result.push_back(tmp);
        
        return result;
    }
};
