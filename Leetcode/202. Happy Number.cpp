// https://leetcode.com/problems/happy-number/description/

class Solution {
public:

int digitSquareSum(int num) {

    int sum = 0;
    while (num) {
        int rem = num % 10;
        sum += rem * rem;
        num /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);

    return slow == 1;
}
};