class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        /*int last_seq_start = 0;
        int last_seq_len = 0;
        int cur_seq_start = 0;
        int cur_seq_len = 0;
        int max_len = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i])
            {
                if (i && nums[i - 1] == 0)
                {
                    cur_seq_start = i;
                    cur_seq_len = 0;
                }
                cur_seq_len++;
            }
            else
            {
                if (i && nums[i - 1])
                {
                    if (last_seq_len && last_seq_start + last_seq_len + 1 == cur_seq_start)
                    {
                        max_len = max(max_len, last_seq_len + cur_seq_len);
                    }

                    max_len = max(max_len, cur_seq_len);

                    last_seq_start = cur_seq_start;
                    last_seq_len = cur_seq_len;
                }
            }
        }

        if (last_seq_len && last_seq_start + last_seq_len + 1 == cur_seq_start)
        {
            max_len = max(max_len, last_seq_len + cur_seq_len);
        }

        max_len = max(max_len, cur_seq_len);

        last_seq_start = cur_seq_start;
        last_seq_len = cur_seq_len;
        
        if (max_len == nums.size()){
            max_len--;
        }

        return max_len;*/
        int longest = 0;
        int ones = nums[0];
        int zeros = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            int new_ones, new_zeros;

            if (nums[i])
            {
                new_ones = ones + 1;
                new_zeros = zeros + 1;
            }
            else
            {
                new_ones = 0;
                new_zeros = ones;
            }

            zeros = new_zeros;
            ones = new_ones;
            longest = max(longest, max(zeros, ones - 1));
        }

        return longest;
    }
};
