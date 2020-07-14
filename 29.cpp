class Solution {
public:
    int divide(int dividend, int divisor){
        if (dividend == numeric_limits<int>::min() && divisor == -1){
            return numeric_limits<int>::max();
        }

        long long divid = labs(dividend);
        long long divis = labs(divisor);
        long long ans = 0;

        while (divid >= divis){
            int k = 1;
            long long tmp_divis = divis;

            while (tmp_divis <= numeric_limits<int>::max() - tmp_divis && divid - (tmp_divis << 1) > 0){
                tmp_divis = tmp_divis << 1;
                k = k << 1;
            }

            divid -= tmp_divis;
            
            ans += k;
        }

        if (dividend >= 0 && divisor > 0 || dividend <= 0 && divisor < 0){
            return (int) ans; 
        }else {
            return (int) -ans;
        }
    }
};
