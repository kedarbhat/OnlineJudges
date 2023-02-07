using KeyT = std::pair<int, int>;

template<>
struct std::hash<KeyT> {
    std::size_t operator()(const KeyT& aKey) const noexcept {
        std::size_t h1 = std::hash<int>{}(aKey.first);
        std::size_t h2 = std::hash<int>{}(aKey.second);
        return h1 ^ (h2 << 1);
    }
};

class Solution {
    static constexpr auto N {9};
    static constexpr auto EMPTY {'.'};
public:
    bool isValidSudoku(vector<vector<char>>& board) {    
        std::array<std::bitset<N>, N> rows{};
        std::array<std::bitset<N>, N> cols{};
        std::unordered_map<KeyT, std::unordered_set<int>> boxes;
        for (auto i = 0; i < N; ++i) {
            for (auto j = 0; j < N; ++j) {
                if (board[i][j] != EMPTY) {
                    auto entry = board[i][j]-'0';
                    if (rows[i][entry]) {
                        return false;
                    }
                    rows[i][entry] = true;
                    
                    if (cols[j][entry]) {
                        return false;
                    }
                    cols[j][entry] = true;

                    auto key = std::make_pair(i/3, j/3);
                    if (boxes[key].find(entry) != boxes[key].cend()) {
                        return false;
                    }
                    boxes[key].emplace(entry);
                }
            }
        }
        return true;
    }
};