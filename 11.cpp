class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_capacity = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j){
            max_capacity = max(max_capacity, (j - i) * min(height[i], height[j]));

            if (height[i] < height[j])
                i++;
            else{
                j--;
            }
        }

        return max_capacity;
    }
};
