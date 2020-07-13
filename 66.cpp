class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overfl = 0;

        digits[digits.size() - 1]++;

        for (int i = digits.size() - 1; i >= 0; --i){
            digits[i] += overfl;

            overfl = digits[i] / 10;
            digits[i] %= 10;
        }

        if (overfl)
            digits.insert(digits.begin(), overfl);

        return digits;
    }
};
