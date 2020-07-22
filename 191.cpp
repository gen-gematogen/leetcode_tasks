class Solution { //another solution with bit shifts (slower)
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        
        while(n){
            weight++;
            n = n & (n - 1);
        }
        
        return weight;
    }
};
