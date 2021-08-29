/**
 * @file p155_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-29
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        stores.push(val);
        minStack.push(min(val, minStack.top()));
    }
    
    void pop() {
        stores.pop();
        minStack.pop();
    }
    
    int top() {
        return stores.top();
    }
    
    int getMin() {
        return minStack.top();
    }
public:
    stack<int> stores;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */