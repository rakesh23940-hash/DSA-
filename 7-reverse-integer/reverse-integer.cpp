class Solution {
public:
    int reverse(int x) {

        int reverseNumber = 0;

        while(x != 0) {

            int digit = x % 10;
            if(reverseNumber > INT_MAX / 10 ||
               reverseNumber < INT_MIN / 10) {
                return 0;
            }

            reverseNumber = reverseNumber * 10 + digit;

            x = x / 10;
        }

        return reverseNumber;
    }
};