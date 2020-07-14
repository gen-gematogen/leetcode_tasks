class Solution {
public:
    int divide(int dividend, int divisor){
        stack<pair<int, int>> num;
        int ans = 0;
        int sum = 0;

        if (dividend >= 0 && divisor > 0){
            num.push(make_pair(divisor, 1));

            while (!num.empty()){
                if (num.top().first <= numeric_limits<int>::max() - sum && sum + num.top().first <= dividend){
                    if (num.top().second > numeric_limits<int>::max() - ans){
                        return numeric_limits<int>::max();
                    }

                    sum += num.top().first;
                    ans += num.top().second;

                    if (num.top().first <= numeric_limits<int>::max() - num.top().first &&
                    num.top().second <= numeric_limits<int>::max() - num.top().second){
                        num.push(make_pair(num.top().first + num.top().first, num.top().second + num.top().second));
                    }
                } else{
                    num.pop();
                }
            }
        } else if (dividend <= 0 && divisor < 0){
            num.push(make_pair(divisor, 1));

            while (!num.empty()){
                if (num.top().first >= numeric_limits<int>::min() - sum && sum + num.top().first >= dividend){
                    if (num.top().second > numeric_limits<int>::max() - ans){
                        return numeric_limits<int>::max();
                    }

                    sum += num.top().first;
                    ans += num.top().second;

                    if (num.top().first >= numeric_limits<int>::min() - num.top().first &&
                    num.top().second <= numeric_limits<int>::max() - num.top().second){
                        num.push(make_pair(num.top().first + num.top().first, num.top().second + num.top().second));
                    }
                } else{
                    num.pop();
                }
            }
        } else if (dividend >= 0 && divisor < 0){
            num.push(make_pair(divisor, -1));

            while (!num.empty()){
                if (num.top().first > numeric_limits<int>::min() - sum && -(sum + num.top().first) <= dividend){
                    if (num.top().second < numeric_limits<int>::min() - ans){
                        return numeric_limits<int>::max();
                    }

                    sum += num.top().first;
                    ans += num.top().second;

                    if (num.top().first > numeric_limits<int>::min() - num.top().first &&
                    num.top().second > numeric_limits<int>::min() - num.top().second){
                        num.push(make_pair(num.top().first + num.top().first, num.top().second + num.top().second));
                    }
                } else{
                    num.pop();
                }
            }
        } else{
            num.push(make_pair(-divisor, -1));

            while (!num.empty()){
                if (num.top().first >= numeric_limits<int>::min() - sum && sum + num.top().first >= dividend){
                    if (num.top().second < numeric_limits<int>::min() - ans){
                        return numeric_limits<int>::max();
                    }

                    sum += num.top().first;
                    ans += num.top().second;

                    if (num.top().first >= numeric_limits<int>::min() - num.top().first &&
                    num.top().second > numeric_limits<int>::min() - num.top().second){
                        num.push(make_pair(num.top().first + num.top().first, num.top().second + num.top().second));
                    }
                } else{
                    num.pop();
                }
            }
        }

        return ans;
    }
};
