class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        
        while (!que.empty()){
            tmp.push(que.top());
            que.pop();
        }
        
        que.push(x);
        
        while (!tmp.empty()){
            que.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = que.top();
        
        que.pop();
        
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return que.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return que.empty();
    }
    
private:
    stack<int> que;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
