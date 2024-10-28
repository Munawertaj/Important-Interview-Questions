// https://leetcode.com/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> negative, ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            int square = nums[i] * nums[i];
            if(nums[i] < 0)
                negative.push_back(square);
            else
            {
                if(negative.size() && negative.back() < square)
                {
                    ans.push_back(negative.back());
                    negative.pop_back();
                    i--;
                }
                else
                    ans.push_back(square);
            }
        }

        int index = negative.size() - 1;
        while(index >= 0)
        {
            ans.push_back(negative[index]);
            index--;
        }
        
        return ans;
    }
};