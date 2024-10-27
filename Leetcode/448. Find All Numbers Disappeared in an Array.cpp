// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        for(int val : nums)
        {
            val = abs(val);
            if(nums[val - 1] > 0)
                nums[val - 1] = -nums[val - 1];
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }
        
        return ans;
    }
};