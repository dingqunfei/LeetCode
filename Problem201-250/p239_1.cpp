
class MonotonicQueue
{
public:
    deque<int> data;
public:
    MonotonicQueue()
    {

    }
    
    void push(int n)
    {
        while(!data.empty() && data.back() < n)
        {
            data.pop_back();
        }
        data.push_back(n);
    }

    int max_value()
    {
        if(!data.empty())
        {
            return data.front();
        }
        return INT_MIN;
    }

    void pop(int n)
    {
        if(!data.empty() && data.front() == n)
        {
            data.pop_front();
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue mQueue;
        vector<int> res;
        for(int i = 0; i < k-1; ++i)
        {
            mQueue.push(nums[i]);
        }
        int i = k-1;
        while(i < nums.size())
        {
            mQueue.push(nums[i]);
            res.push_back(mQueue.max_value());
            mQueue.pop(nums[i-k+1]);
            ++i;
        }
        return res;
    }
};