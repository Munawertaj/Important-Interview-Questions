// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        long num = x, rev = 0;
        while(num > 0)
        {
            rev = rev * 10 + num % 10;
            num /= 10;
        }

        return rev == x;
    }
};