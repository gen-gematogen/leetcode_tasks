class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        uint32_t digit = 1;
        int k = sizeof(uint32_t) * 8;
        
        for (int i = 0; i < k; ++i){
            uint32_t curDigit = (n & digit) >> i;
            reversed = reversed | (curDigit << (k - i - 1));
            digit = digit << 1;
        }
        
        return reversed;
    }
};
