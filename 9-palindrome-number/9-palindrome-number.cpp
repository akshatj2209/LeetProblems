class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        unsigned int rev = 0;
        while(x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev == num;
        
        
    }
};