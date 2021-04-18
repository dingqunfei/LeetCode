/**
 * @file p146_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-18
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


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

    }
    
    void put(int key, int value) {

    }
private:
    DoubleList cache;
    hash_map<int, Node *> lruMap;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */