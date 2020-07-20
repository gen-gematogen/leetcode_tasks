class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        pair<int, int> lowGreat = make_pair(l, r);

        while (r > l){
            int m = (r + l) / 2;

            int loweq = find(matrix, lowGreat, m);

            if (loweq == k){
                return lowGreat.first;
            }

            if (loweq < k){
                l = lowGreat.second;
                lowGreat.second = matrix[n - 1][n - 1];
            } else{
                r = lowGreat.first;
                lowGreat.first = matrix[0][0];
            }
        }

        return l;
    }

private:
    int find(vector<vector<int>>& matrix, pair<int, int>& lowGreat, int m){
        int n = matrix.size();
        int loweq = 0;
        int col = 0;
        int ln = n - 1;

        while (col < n && ln >= 0){
            if (matrix[ln][col] <= m){
                lowGreat.first = max(lowGreat.first, matrix[ln][col]);
                loweq += ln + 1;
                col++;
            } else{
                lowGreat.second = min(lowGreat.second, matrix[ln][col]);
                ln--;
            }
        }

        return loweq;
    }
};
