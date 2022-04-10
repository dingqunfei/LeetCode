class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> index;

        int n = p.size(), m = s.size();
        if(n > m)
        {
            return index;
        }
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for(int i = 0; i < n; ++i)
        {
            ++cnt1[p[i] - 'a'];
            ++cnt2[s[i] - 'a'];
        }
        if(cnt1 == cnt2)
        {
            index.push_back(0);
        }
        for(int i = n; i < m; ++i)
        {
            ++cnt2[s[i] - 'a'];
            --cnt2[s[i-n] - 'a'];
            if(cnt1 == cnt2)
            {
                index.push_back(i-n+1);
            }
        }
        return index;
    }
}; 