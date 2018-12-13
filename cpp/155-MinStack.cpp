class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        value_stack.push(x);
        if (min_stack.empty())
            min_stack.push(x);
        else
            min_stack.push(min_stack.top() < x? min_stack.top(): x);
    }
    
    void pop() {
        value_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return value_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private: 
    stack<int> value_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */