class StockSpanner {
private:
    stack<pair<int, int>> prevPrice;
    
public:
    int next(int price) {
        int cnt = 1;
        
        while (!prevPrice.empty() && prevPrice.top().first <= price){
            cnt +=  prevPrice.top().second;
            prevPrice.pop();
        }
        
        prevPrice.push({price, cnt});
        
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
