// https://leetcode.com/problems/climbing-stairs/description/

// ------------------ Approach - 01 (Bottom-Up)-----------------------

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for(int position = 2; position <= n; ++position) {
            dp[position] = dp[position - 1] + dp[position - 2];
        }

        return dp[n];
    }
};

// ------------------ Approach - 02(Top-Down)-----------------------

class Solution {
public:
    int helper(vector<int>& dp, int stair)
    {
        if(stair < 2)
            return 1;
        
        if(dp[stair] != -1)
            return dp[stair];
        
        return dp[stair] = helper(dp, stair - 1) + helper(dp, stair - 2);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(dp, n);
    }
};