class Solution {
public:
    string largestNumber(vector<int> &num) {
        if (all_of(num.begin(), num.end(), [](int i){ return i == 0; })) { return "0"; }
        vector<string> vec;
        for (auto i : num) {
            vec.emplace_back(to_string(i));
        }
        
        sort(vec.begin(), vec.end(), [](const string& s1, const string& s2) {
            return s1+s2 > s2+s1;
        });
        
        string s_out = "";
        for (const auto& s : vec) {
            s_out += s;
        }
        return s_out;
    }
};