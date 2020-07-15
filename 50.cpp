class Solution {
public:
    double myPow(double x, int n) {
        if (n >= 0){
            return fastPow(x, n);
        }
        
        return 1/fastPow(x, labs(n));   
    }

private:
    double fastPow(double x, long n){
        if (n == 0){
            return 1;
        }
        if (n == 1){
            return x;
        }

        if (n % 2){
            return x * fastPow(x, n - 1);
        }

        double tmp = fastPow(x, n / 2);
        return tmp * tmp;   
    }
};
