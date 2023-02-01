class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        
        if (needle.size() == haystack.size()) {
            return needle == haystack ? 0 : -1;
        }
        
        auto start = std::cbegin(haystack);
        auto finish = std::cbegin(haystack) + static_cast<int>(needle.size());
        while (std::distance(finish, std::cend(haystack)) >= 0) {
            if (std::string(start, finish) == needle) {
                return std::distance(std::cbegin(haystack), start);
            } else {
                std::advance(start, 1);
                std::advance(finish, 1);
            }
        }
        return -1;        
    }
};