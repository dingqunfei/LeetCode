class Solution {
public:
    vector<int> index;
    void pancakeSortMax(vector<int>& arr, int right)
    {
        if(right <= 0)
        {
            return;
        }
        auto max_elem = max_element(arr.begin(), arr.begin()+right);
        index.push_back(max_elem - arr.begin() + 1);
        reverse(arr.begin(), max_elem+1);
        index.push_back(right);
        reverse(arr.begin(), arr.begin()+right);
        pancakeSortMax(arr, right-1);
    }

    vector<int> pancakeSort(vector<int>& arr) {
        pancakeSortMax(arr, arr.size());
        return index;
    }
};