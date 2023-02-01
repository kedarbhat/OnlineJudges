class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int numDigits = static_cast<int>(std::log10(x))+1;
        auto myResult = 0;
        for (auto i{0}, len=numDigits/2; i < len; ++i)
        {
            myResult = myResult*10 + (x%10);
            x /= 10;
        }
        if (numDigits % 2 == 1)
        {
            x /= 10;
        }
        return myResult == x;
    }
};