// https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        for(int num = 1; num <= n; ++num)
        {
            if(num & 1)
                ans[num] = ans[num - 1] + 1;
            else
                ans[num] = ans[num / 2];
        }

        return ans;
    }
};