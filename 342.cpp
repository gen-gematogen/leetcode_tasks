class Solution {
public:
    bool isPowerOfFour(int num) {
        if ((!num || (num & 0x55555555) != num) || (num & (num - 1))) return false;
                
        return true;
    }
};
