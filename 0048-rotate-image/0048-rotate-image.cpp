class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (auto i = 0; i < matrix.size(); ++i)
        {
            for (auto j = i; j < matrix[i].size(); ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
            std::reverse(std::begin(matrix[i]), std::end(matrix[i]));
        }
    }
};