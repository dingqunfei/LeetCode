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
        while(!data.empty())
        {
            cache.push(data.top());
            data.pop();
        }
        int value = cache.top();
        cache.pop();
        while(!cache.empty())
        {
            data.push(cache.top());
            cache.pop();
        }
        return value;
    }
    
    int peek() {
        while(!data.empty())
        {
            cache.push(data.top());
            data.pop();
        }
        int value = cache.top();
        while(!cache.empty())
        {
            data.push(cache.top());
            cache.pop();
        }
        return value;
    }
    
    bool empty() {
        return data.empty();
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