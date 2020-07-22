class Solution { //may be soved with slow/fast sum
public:
    bool isHappy(int n) {
        unordered_set<int> numbers;
        
        int sum = sumOfSquares(n);
        
        while (numbers.find(sum) == numbers.end() && sum != 1){ 
            numbers.insert(sum);
            
            sum = sumOfSquares(sum);
        }
        
        if (sum == 1){
            return true;
        }
        
        return false;
    }
    
    int sumOfSquares(int n){
        int sum = 0;
        
        while (n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return sum;
    }
};
