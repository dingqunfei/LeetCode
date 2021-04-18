class Node{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int a, int b):
        key(a), 
        val(b),
        prev(nullptr),
        next(nullptr)
    {

    }
};

class DoubleList{
public:
    DoubleList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addLast(Node *x)
    {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        ++size;
    }

    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        --size;
    }

    Node *removeFirst()
    {
        if(head->next == tail)
            return nullptr;
        Node *first = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        --size;
        return first;
    }

    int get_size() const
    {
        return size;
    }

private:
    Node *head;
    Node *tail;
    int size;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;


    }
    
    int get(int key) {
        //不存在
        if(lruMap.find(key) == lruMap.end())
        {
            return -1;
        }
        
        makeRecently(key);
        return lruMap[key]->val;
    }
    
    void put(int key, int value) {
        //存在
        if(lruMap.find(key) != lruMap.end())
        {
            deleteKey(key);
            addRecently(key, value);
        }
        else
        {
            addRecently(key, value);
            if(cache.get_size() > cap)
            {
                removeLeastRecently();
            }
        }

    }

private:
    void makeRecently(int key)
    {
        Node *x = lruMap[key];
        cache.remove(x);
        cache.addLast(x);
    }

    void addRecently(int key, int val)
    {
        Node *x = new Node(key, val);
        lruMap.insert(make_pair(key, x));
        cache.addLast(x);
    }

    void deleteKey(int key)
    {
        Node *x = lruMap[key];
        cache.remove(x);
        lruMap.erase(key);
    }

    void removeLeastRecently()
    {
        Node *delNode = cache.removeFirst();
        int key = delNode->key;
        lruMap.erase(key);
    }

private:
    DoubleList cache;
    map<int, Node *> lruMap;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */