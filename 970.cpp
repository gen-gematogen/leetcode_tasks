class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> x_pwr {1};
        vector<int> y_pwr {1};
        vector<int> ans;
        
        int i = 0;
        
        while ((x != 1) && (x_pwr[i] * x <= bound)){
            x_pwr.push_back(x_pwr[i++] * x);
        }
        
        i = 0;
        
        while ((y != 1) && (y_pwr[i] * y <= bound)){
            y_pwr.push_back(y_pwr[i++] * y);
        }
        
        vector<int> used(bound + 1);
        
        for (int i = 0; i < x_pwr.size(); ++i){
            for (int j = 0; j < y_pwr.size(); ++j){
                if ((x_pwr[i] + y_pwr[j] <= bound) && !used[x_pwr[i] + y_pwr[j]]){
                    used[x_pwr[i] + y_pwr[j]] = 1;
                    ans.push_back(x_pwr[i] + y_pwr[j]);
                }
            }
        }
        return ans;
    }
};
