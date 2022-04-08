class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> needs, window;
        for(auto ch: t)
        {
            ++needs[ch];
        }
        int left = 0, right = 0, vaildCount = 0;
        int start = 0, len = INT_MAX;
        while(right < s.size())
        {
            char a = s[right];
            ++right;
            if(needs.count(a))
            {
                ++window[a];
                if(window[a] == needs[a])
                {
                    ++vaildCount;
                }
            }
            while(vaildCount == needs.size())
            {
                if(right - left < len)
                {
                    len = right - left;
                    start = left;
                }
                char d = s[left];
                ++left;
                if(window.count(d))
                {
                    --window[d];
                    if(window[d] < needs[d])
                    {
                        --vaildCount;
                    }
                }
            }

        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};