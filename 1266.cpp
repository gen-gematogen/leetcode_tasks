class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        
        for (int i = 1; i < n; ++i){
            time += max(abs(points[i - 1][0] - points[i][0]), abs(points[i - 1][1] - points[i][1]));
        }
        
        return time;
    }
};
