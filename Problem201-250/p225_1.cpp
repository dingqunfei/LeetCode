class MyStack {
public:
    queue<int> data;
    int top_elem;
public:
    MyStack() {
        top_elem = 0;
    }
    
    void push(int x) {
        data.push(x);
        top_elem = x;
    }
    
    int pop() {
        int size = data.size();
        int value = 0;
        while(size > 2)
        {
            value = data.front();
            data.pop();
            data.push(value);
            --size;
        }
        top_elem = data.front();
        data.pop();
        data.push(top_elem);

        value = data.front();
        data.pop();
        return value;
    }
    
    int top() {
        return top_elem;
    }
    
    bool empty() {
        return data.empty();
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