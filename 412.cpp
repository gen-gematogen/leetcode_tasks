class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> nums(n);
        string f = "Fizz";
        string b = "Buzz";
        
        for (int i = 1; i <= n; ++i){
            if (i % 15 == 0)
            {
                nums[i - 1] = f + b;
            } else if (i % 5 == 0)
            {
                nums[i - 1] = b;
            } else if (i % 3 == 0)
            {
                nums[i - 1] = f;
            } else
            {
                nums[i - 1] = to_string(i);
            }
        }

        return nums;
    }
};
