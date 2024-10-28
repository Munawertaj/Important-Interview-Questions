// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> values;
        vector<int> ans;

        for(int& num : nums1)
        {
            values[num]++;
        }
        
        for(int& num : nums2)
        {
            if(values[num])
            {
                ans.push_back(num);
                values[num]--;
            }
        }
        return ans;
    }
};