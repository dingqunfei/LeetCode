class Solution {
public:
    string smallestSubsequence(string s) {
        bool bInStack[256] = {false};
        int nCharNum[256] = {0};
        for(auto ch: s)
        {
            ++nCharNum[ch];
        }
        stack<char> charStack;
        for(auto ch: s)
        {
            --nCharNum[ch];
            if(bInStack[ch])
            {
                continue;
            }
            while(!charStack.empty() && charStack.top() > ch)
            {
                char topChar = charStack.top();
                if(nCharNum[topChar] == 0)
                {
                    break;
                }
                charStack.pop();
                bInStack[topChar] = false;
            }
            charStack.push(ch);
            bInStack[ch] = true;
        }
        string res;
        while(!charStack.empty())
        {
            res.insert(0, 1, charStack.top());
            charStack.pop();
        }
        return res;
    }
};