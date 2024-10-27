// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        
        string prefix = strs[0];

        for(string& st : strs)
        {
            while(st.find(prefix) != 0) 
            {
                prefix.pop_back();
            }
        }
        
        return prefix;
    }
};