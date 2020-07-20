class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int sum = 0;

        for (int i = 0; i < sizeof(int) * 8; ++i){
            sum = sum | ((a ^ b ^ (carry << i)) & (1 << i));
            carry = (((a & b) | (a & (carry << i)) | (b & (carry << i))) >> i) & 1;
        }

        return sum;
    }
};
