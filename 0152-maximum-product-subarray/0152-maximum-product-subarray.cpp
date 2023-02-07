
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        auto minProduct = nums[0];
        auto maxProduct = nums[0];
        auto result = nums[0];
        for (auto i = 1u; i < nums.size(); ++i) {
            auto prevMaxProduct = maxProduct;
            auto prevMinProduct = minProduct;
            minProduct = std::min({nums[i], prevMaxProduct*nums[i], prevMinProduct*nums[i]});
            maxProduct = std::max({nums[i], prevMaxProduct*nums[i], prevMinProduct*nums[i]});
            result = std::max(maxProduct, result);
        }
        return result;
        
    }
};