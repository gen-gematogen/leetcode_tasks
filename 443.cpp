class Solution
{
public:
    int compress(std::vector<char> &chars)
    {
        if (!chars.size())
        {
            return 0;
        }

        char prev = -1;
        int cnt = 0;
        int pos = 0;

        for (int i = 0; i < chars.size(); ++i)
        {
            if (prev != -1 && chars[i] != prev)
            {
                chars[pos++] = prev;
                if (cnt > 1)
                {
                    for (char c : std::to_string(cnt))
                    {
                        chars[pos++] = c;
                    }
                }
                cnt = 1;
            }
            else
            {
                cnt++;
            }

            prev = chars[i];
        }

        chars[pos++] = prev;

        if (cnt > 1)
        {
            for (char c : std::to_string(cnt))
            {
                chars[pos++] = c;
            }
        }

        return pos;
    }
};
