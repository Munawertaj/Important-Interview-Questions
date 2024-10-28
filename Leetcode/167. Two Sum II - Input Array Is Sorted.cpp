// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    int search(vector<int>& nums, int target, int low, int high)
    {
        while(high - low > 1)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if(nums[low] == target)
            return low;
        else if(nums[high] == target)
            return high;
        
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int last = numbers.size() - 1;
        for(int i = 0; i < last; ++i)
        {
            int index = search(numbers, target - numbers[i], i + 1, last);
            if(index >= 0)
                return {i + 1, index + 1};   
        }

        return {};
    }
};