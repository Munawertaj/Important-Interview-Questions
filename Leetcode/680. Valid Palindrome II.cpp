// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool isPalindrome(string& s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right)
        {
            if(s[left] != s[right])
            {
                if(isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1))
                    return true;
                else
                    return false;
            }

            left++;
            right--;
        }

        return true;
    } 
};