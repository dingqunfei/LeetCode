/**
 * @file p215_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-30
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-30
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

//随机打乱数据，取得初始pivot
class Solution {
private:

    /*
    int partition(vector<int> &nums, int left, int right)
    {
        if(left == right)
        {
            return left;
        }
        int pviot = nums[left];
        int low = left, high = right;
        while(low < right)
        {
            while(nums[low] < pviot)
            {
                ++low;
            }
            while(nums[high] > pviot)
            {
                --high;
            }
            swap(nums, low, high);
        }
        swap(nums, left, low);
        return low;
    }
    */
    
    int partition(vector<int> &nums, int lo, int hi) {
        if (lo == hi) return lo;
        // 将 nums[lo] 作为默认分界点 pivot
        int k = rand() % (hi - lo + 1) + lo;
        std::swap(nums[k], nums[hi]);
        int pivot = nums[lo];
        // j = hi + 1 因为 while 中会先执行 --
        int i = lo, j = hi + 1;
        while (true) {
            // 保证 nums[lo..i] 都小于 pivot
            while (nums[++i] < pivot) {
                if (i == hi) break;
            }
            // 保证 nums[j..hi] 都大于 pivot
            while (nums[--j] > pivot) {
                if (j == lo) break;
            }
            if (i >= j) break;
            // 如果走到这里，一定有：
            // nums[i] > pivot && nums[j] < pivot
            // 所以需要交换 nums[i] 和 nums[j]，
            // 保证 nums[lo..i] < pivot < nums[j..hi]
            swap(nums, i, j);
        }
        // 将 pivot 值交换到正确的位置
        swap(nums, j, lo);
        // 现在 nums[lo..j-1] < nums[j] < nums[j+1..hi]
        return j;
    }
    

    // 交换数组中的两个元素
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void quickselect(vector<int> &nums, int left, int right, int k)
    {
        if(k < 0 || right - left + 1 < k || left >= right)
        {
            return;
        }
        int p = partition(nums, left, right);
        quickselect(nums, left, p-1, k - (right - p + 1));
        quickselect(nums, p + 1, right, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        quickselect(nums, 0, size - 1, k);
        return nums[size-k];
    }
};