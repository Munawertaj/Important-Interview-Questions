// https://leetcode.com/problems/min-cost-climbing-stairs/description/

// ------- Approach - 01 (Bottom-UP) ---------

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int total = cost.size();
        vector<int> dp(total + 1, 0);

        for(int i = 2; i <= total; ++i)
        {
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }

        return dp[total];
    }
};

// ------- Approach - 02 (Top-Down Iterative) ---------

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int total = cost.size();
        vector<int> dp(total + 1, 0);

        for(int i = total - 2; i >= 0; --i)
        {
            dp[i] = min(cost[i] + dp[i+1], cost[i+1] + dp[i+2]);
        }

        return dp[0];
    }
};

// ------- Approach - 02 (Top-Down Recursive) ---------

class Solution {
public:
    int helper(vector<int>& dp, vector<int>& cost, int index)
    {
        if(index < 2)
            return cost[index];
        
        if(dp[index] != -1)
            return dp[index];
        
        return dp[index] = min(cost[index] + helper(dp, cost, index - 1), cost[index] + helper(dp, cost, index - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int total = cost.size();
        vector<int> dp(total + 1, -1);

        return min(helper(dp, cost, total - 1), helper(dp, cost, total - 2));
    }
};