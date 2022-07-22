
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> index;
        int n = nums2.size();
        for(int i = 0; i < n; ++i)
        {
            index.push_back({nums2[i], i});
        }
        sort(nums1.begin(), nums1.end());
        sort(index.begin(), index.end(), [](auto &a, auto &b){return a.first < b.first;});

        int a = n-1, b = n-1;
        int aStart = 0;
        vector<int> vec(n, INT_MAX);
        while(a >= 0 && b >= 0 && aStart < n)
        {
              if(nums1[a] > index[b].first)
              {
                  vec[index[b].second] = nums1[a];
                  --a;
                  --b;
              }
              else
              {
                  vec[index[b].second] = nums1[aStart];
                  ++aStart;
                  --b;
              }
        }
        
        return vec;
    }
};


class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        vector<pair<int, int>> newnum;
        for(int i = 0; i < n; ++i)
        {
            newnum.push_back(pair<int, int>(nums2[i], i));
        }
        sort(newnum.begin(), newnum.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;});
        vector<int> res(n, INT_MIN);
        int a = n-1, b = n-1;
        while(a >= 0 && b >= 0)
        {
            if(nums1[a] > newnum[b].first)
            {
                res[newnum[b].second] = nums1[a];
                --a;
                --b;
            }
            else
            {
                --b;
            }
        }
        int i = 0;
        while(a >= 0 && i < n)
        {
            if(res[i] == INT_MIN)
            {
                res[i] = nums1[a];
                --a;
            }
            ++i;
        }
        return res;

    }
};