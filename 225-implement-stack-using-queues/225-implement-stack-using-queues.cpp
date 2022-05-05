class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int ans;
        while (!q1.empty()) {
            int temp = q1.front();
            q1.pop();
            if (q1.empty()) 
                ans = temp;
            else
                q2.push(temp);
        }
        
        while (!q2.empty()) {
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        
        return ans;
    }
    
    int top() {
        int ans;
        while (!q1.empty()) {
            int temp = q1.front();
            q1.pop();
            if (q1.empty()) ans = temp;
            q2.push(temp);
        }
        
        while (!q2.empty()) {
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        
        return ans;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */