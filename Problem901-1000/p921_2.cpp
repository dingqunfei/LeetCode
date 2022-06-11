class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> chStack;
        for(char ch: s)
        {
            if(ch == '(')
            {
                chStack.push(ch);
            }
            else if(ch == ')')
            {
                if(!chStack.empty() && chStack.top() == '(')
                {
                    chStack.pop();
                }
                else
                {
                    chStack.push(ch);
                }
            }
        }
        return chStack.size();
    }
};