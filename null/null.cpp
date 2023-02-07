class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto carry = 1;
        for (int i = digits.size()-1; carry == 1 && i >= 0; --i) {
            digits[i] += carry;
            if (digits[i] < 10) {
                carry = 0;
            } else {
                digits[i] = 0;
            }
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};