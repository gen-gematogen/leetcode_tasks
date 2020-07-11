class Solution {
public:
    int myAtoi(string str) {
        int pos = 0;
        int num = 0;
        int sign = 1;

        while (pos < str.size() && str[pos] == ' ')
            pos++;

        if (pos >= str.size() || (str[pos] != '-' && str[pos] != '+' && (str[pos] - '0' < 0 || str[pos] - '0' > 9)))
            return 0;

        if (str[pos] == '-'){
            sign = -1;
            pos++;
        } else if (str[pos] == '+'){
            pos++;
        }

        while (pos < str.size() && str[pos] - '0' >= 0 && str[pos] - '0' <= 9){
            int digit = str[pos] - '0';

            digit *= sign;

            if (sign == 1){
                if (INT_MAX / 10 < num)
                    return INT_MAX;

                num *= 10;

                if (INT_MAX - digit < num)
                    return INT_MAX;
            } else{
                if (INT_MIN / 10 > num)
                    return INT_MIN;

                num *= 10;

                if (INT_MIN - digit > num)
                    return INT_MIN;
            }

            num += digit;
            pos++;
        }

        return num;
    }
};
