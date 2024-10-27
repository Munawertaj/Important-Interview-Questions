// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> bracket = {{')', '('}, {'}', '{'}, {']', '['}};

        for(char ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);

            else if(st.empty() || bracket[ch] != st.top())
                return false;
            
            else
                st.pop();
        }

        return st.empty();
    }
};