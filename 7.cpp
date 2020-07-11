class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x){
            int digit = x % 10;
            x /= 10;

            if (std::numeric_limits<int>::max() / 10 < rev)
                return 0;
            if (std::numeric_limits<int>::min() / 10 > rev)
                return 0;

            rev *= 10;

            if (digit > 0 && std::numeric_limits<int>::max() - digit < rev)
                return 0;
            if (digit < 0 && std::numeric_limits<int>::min() - digit > rev)
                return 0;

            rev += digit;
        }

        return rev;
    }
};
