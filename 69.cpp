class Solution {
public:
    int mySqrt(int x) {
        int result = 0;

        while(2*result + 1 <= x - result * result)
            result++;

        return result;
    }
};
