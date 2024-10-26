class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        
        for(int val : nums)
        {
            sum += val;
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }
        
        return ans;
    }
};