class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        if (numRows == 0) {
            return result;
        }        
        
        for (auto row = 0; row < std::min(2, numRows); ++row) {
            result.emplace_back(std::vector<int>(row+1, 1));    
        }
        
        // Recurrence: (n-1, k-1) + (n-1, k) == (n, k)
        for (auto row = 2; row < numRows; ++row) {
            std::vector<int> row_vector(row+1, 1);
            const auto& previous_row = result[row-1];
            for (auto column = 1; column < row; ++column) {
                row_vector[column] = previous_row[column-1] + previous_row[column];
            }
            result.emplace_back(row_vector);
        }
        
        return result;        
    }
};