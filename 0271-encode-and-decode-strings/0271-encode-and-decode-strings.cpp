class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(const vector<string>& strs) {
        std::string encodedStr;
        for (const auto& s : strs) {
            encodedStr += std::to_string(s.size()) + "#" + s;
        }
        return encodedStr;
    }

// Decodes a single string to a list of strings.
    std::vector<std::string> decode(string s) {
        std::vector<std::string> decodedStrs;
        auto i = 0;
        while (i < s.size()) {
            auto j = i;
            while (s[j] != '#') {
                ++j;
            }
            auto currentLength = std::stoi(s.substr(i, j));
            decodedStrs.emplace_back(s.substr(j+1, currentLength));
            i = j+1+currentLength;
        }
        return decodedStrs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));