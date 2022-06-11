class Solution {
public:
    int minAddToMakeValid(string s) {
        int need = 0, res = 0;
        for(char ch: s)
        {
            if(ch == '(')
            {
                ++need;
            }
            else if(ch == ')')
            {
                --need;
                if(need == -1)
                {
                    need = 0;
                    ++res;
                }
            }
        }
        return need+res;
    }
};