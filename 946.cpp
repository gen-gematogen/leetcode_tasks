class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
    int n = pushed.size();

    if (n == 0){
        return true;
    }    
        
    vector<bool> pushedNow(1000);
    stack<int> st;
    int pos = 0;
    
    for (int i: popped){
        if (pushedNow[i] == 1 && st.top() != i){
            return false;
        } if (pushedNow[i] == 0){
            while (pushed[pos] != i){
                pushedNow[pushed[pos]] = 1;
                st.push(pushed[pos]);
                pos++;
            }
            
            pushedNow[pushed[pos]] = 1;
            st.push(pushed[pos]);
            pos++;
        }
        
        pushedNow[i] = 0;
        st.pop();
    }
        
    return true;
}
};
