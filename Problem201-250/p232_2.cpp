class MyQueue {
public:
    stack<int> data;
    stack<int> cache;

public:
    MyQueue() {
    }
    
    void push(int x) {
        data.push(x);
    }
    
    int pop() {
        int value = peek();
        cache.pop();
        return value;
    }
    
    int peek() {
        if(cache.empty())
        {
            while(!data.empty())
            {
                cache.push(data.top());
                data.pop();
            }
        }
        
        return cache.top();
    }
    
    bool empty() {
        return data.empty() && cache.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */