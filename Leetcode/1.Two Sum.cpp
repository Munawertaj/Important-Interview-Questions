class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int len = nums.size();
        unordered_map<int, int> check;
        
        for(int i = 0 ; i < len ; i++)
        {
            int val = target- nums[i];
            
            if(check[val])
                return {i, check[val] - 1};

            check[nums[i]] = i + 1;
        }
        
        return {};
    }
};