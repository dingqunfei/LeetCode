class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> nStack;
        vector<int> ans(temperatures.size(), 0);
        for(int i = temperatures.size()-1; i >= 0; --i)
        {
            while(!nStack.empty() && temperatures[i] >= temperatures[nStack.top()])
            {
                nStack.pop();
            }
            ans[i] = nStack.empty() ? 0 : nStack.top() - i;
            nStack.push(i);
        }
        return ans;
    }
};