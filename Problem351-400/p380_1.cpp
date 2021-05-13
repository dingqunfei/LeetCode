/**
 * @file p380_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-22
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {


    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(keyIndex.count(val))
        {
            return false;
        }
        data.push_back(val);
        keyIndex[val] = data.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(keyIndex.count(val))
        {
            int index = keyIndex[val];
            keyIndex[data.back()] = index;
            swap(data[index], data.back());
            data.pop_back();
            keyIndex.erase(val);
            return true;
        }
        return false;

    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(data.empty()) return -1;
        int randNumber = rand()%data.size();
        return data[randNumber];
    }


private:
    unordered_map<int, int> keyIndex;
    vector<int> data;
    //int *data;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */