class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, distance = 0, htmp;
        stack<int> index_stack;
        stack<int> value_stack;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > 0 && value_stack.empty()) {
                index_stack.push(i);
                value_stack.push(height[i]);
            } else if (height[i] > 0 && !value_stack.empty()) {
                distance = i - index_stack.top() - 1;
                htmp = height[i];
                if (distance == 0) {
                    while (!value_stack.empty() && value_stack.top() < htmp) {
                        htmp -= value_stack.top();
                        value_stack.pop();
                        index_stack.pop();
                        if (!value_stack.empty()) {
                            distance = i - index_stack.top() - 1;
                            sum += min(value_stack.top(), htmp) * distance;
                        }
                    }
                    if (!value_stack.empty())
                        value_stack.top() -= htmp;
                    index_stack.push(i);
                    value_stack.push(height[i]);
                } else {
                    while (!value_stack.empty() && htmp > 0) {
                        distance = i - index_stack.top() - 1;
                        sum += min(value_stack.top(), htmp) * distance;
                        if (value_stack.top() <= htmp) {
                            htmp -= value_stack.top();
                            value_stack.pop();
                            index_stack.pop();
                        } else {
                            value_stack.top() -= htmp;
                            break;
                        } 
                    }
                    index_stack.push(i);
                    value_stack.push(height[i]);
                }
            }
        }
        return sum;
    }
};