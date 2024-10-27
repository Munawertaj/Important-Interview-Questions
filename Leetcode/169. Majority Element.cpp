// https://leetcode.com/problems/majority-element/description/

// ----------------- Approach - 01 (Using hashMap) ------------------

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unorderd_map<int,int> count;
        int maximum = 0, ans;
        for(int val : nums)
        {
            count[val]++;
            if(count[val] > maximum)
            {
                maximum = count[val];
                ans = val;
            }
        }
        return ans;
    }
};

// ----------------- Approach - 02 (Using sort) ------------------

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// ----------------- Approach - 03 ( Boyer-Moore Majority Vote algorithm ) ------------------

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, majority = 0;

        for(int val : nums)
        {
            if(majority == 0)
                ans = val;
            
            majority += (ans == val ? 1 : -1);
        }

        return ans;
    }
};