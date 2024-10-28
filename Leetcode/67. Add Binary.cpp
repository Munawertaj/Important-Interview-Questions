// https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string add(string& num1, string& num2)
    {
        int index = num1.size() - 1;
        int carry = 0;
        string sum(index + 1, '0');
        
        while(index >= 0)
        {
            int digit = num1[index] - '0' + num2[index] - '0' + carry;
            carry = digit / 2;
            sum[index] += digit % 2;
            index--;
        }

        if(carry)
            sum = to_string(carry) + sum;
        
        return sum;
    }

    string addBinary(string a, string b) {

        int len1 = a.size(), len2 = b.size();
        string zeros(abs(len1-len2), '0');
        len1 < len2 ? a = zeros + a : b = zeros + b;
        
        return add(a, b);
    }
};