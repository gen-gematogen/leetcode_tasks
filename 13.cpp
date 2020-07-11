class Solution {
public:
    int romanToInt(string s) {
        map<string, int> dict;

        dict.insert(make_pair("I", 1));
        dict.insert(make_pair("V", 5));
        dict.insert(make_pair("X", 10));
        dict.insert(make_pair("L", 50));
        dict.insert(make_pair("C", 100));
        dict.insert(make_pair("D", 500));
        dict.insert(make_pair("M", 1000));
        dict.insert(make_pair("IV", 4));
        dict.insert(make_pair("IX", 9));
        dict.insert(make_pair("XL", 40));
        dict.insert(make_pair("XC", 90));
        dict.insert(make_pair("CD", 400));
        dict.insert(make_pair("CM", 900));

        int sum = 0;
        int i = 0;

        while(i < s.size()){
            if (i + 1 < s.size()){
                string tmp = s.substr(i, 2);

                auto search = dict.find(tmp);
                if (search != dict.end()){
                    sum += search->second;
                    i += 2;
                    continue;
                }
            }

            string tmp = s.substr(i, 1);
            auto search = dict.find(tmp);
            sum += search->second;
            i++;
        }

        return sum;
    }
};
