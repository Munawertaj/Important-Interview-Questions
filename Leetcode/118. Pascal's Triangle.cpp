// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        pascalTriangle.push_back({1});

        for(int i = 1; i < numRows; ++i)
        {
            vector<int> row;
            row.push_back(1);

            for(int j = 0; j < pascalTriangle[i - 1].size() - 1; ++j)
            {
                row.push_back(pascalTriangle[i-1][j] + pascalTriangle[i - 1][j + 1]);
            }

            row.push_back(1);
            pascalTriangle.push_back(row);
        }

        return pascalTriangle;
    }
};