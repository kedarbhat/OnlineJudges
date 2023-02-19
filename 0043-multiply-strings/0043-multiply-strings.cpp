class Solution {
 public:
  std::string multiply(std::string_view num1, std::string_view num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    std::string result(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; --i) {
      for (int j = num2.size() - 1; j >= 0; --j) {
        const auto sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
        result[i + j + 1] = sum % 10 + '0';
        result[i + j] += sum / 10;
      }
    }
    if (result[0] == '0') {
      result.erase(0, 1);
    }
    return result;
  }
};