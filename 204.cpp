class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        
        vector<bool> numbers(n);
        
        numbers[0] = numbers[1] = 1;
        
        int sqrt = pow(n, 0.5);
        
        for (int i = 2; i <= sqrt; ++i){
            if (numbers[i] == 0){
                for (int j = 2 * i; j < n; j += i) numbers[j] = 1;
            }
        }
        
        int prime = n;
        
        for (int it: numbers) prime -= it;
        
        return prime;
    }
};
