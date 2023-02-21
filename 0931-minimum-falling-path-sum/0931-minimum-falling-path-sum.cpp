class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (j == 0) {
                    matrix[i][j] += min(matrix[i - 1][j + 1], matrix[i - 1][j]);
                } else if (j == matrix[0].size() - 1) {
                    matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
                } else {
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
                }
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};