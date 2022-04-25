class DLinkNode
{
public:
    int key;
    int value;
    DLinkNode *prev;
    DLinkNode *next;

public:
    DLinkNode():key(0), value(0), prev(nullptr), next(nullptr) {};
    DLinkNode(int key_, int value_):key(key_), value(value_), prev(nullptr), next(nullptr) {};
};


class LRUCache {
public:
    LRUCache(int capacity_) {
        size = 0;
        capacity = capacity_;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.count(key))
        {
            DLinkNode* target = cache[key];
            moveToHead(target);
            return target->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
            DLinkNode* pNode = cache[key];
            pNode->value = value;
            moveToHead(pNode);
        }
        else
        {
            DLinkNode* pNode = new DLinkNode(key, value);
            addToHead(pNode);
            cache[key] = pNode;
            ++size;
            if(size > capacity)
            {
                DLinkNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
    }

    void moveToHead(DLinkNode* node)
    {
        remove(node);
        addToHead(node);
    }
    void remove(DLinkNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToHead(DLinkNode* node)
    {
        node->next = head->next;
        node->prev = head;
        
        head->next->prev = node;
        head->next = node;
    }
    DLinkNode* removeTail()
    {
        // if(tail->prev == head)
        // {
        //     return nullptr;
        // }
        DLinkNode* node = tail->prev;
        remove(node);
        return node;
    }

public:
    unordered_map<int, DLinkNode*> cache;
    DLinkNode* head;
    DLinkNode* tail;
    int size;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */