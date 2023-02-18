class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> zeroRows(matrix.size());
        vector<bool> zeroColumns(matrix[0].size());
        for (auto rowIdx = 0; rowIdx < matrix.size(); ++rowIdx)
        {
            auto& row = matrix[rowIdx];
            for (auto columnIdx = 0; columnIdx < row.size(); ++columnIdx)
            {
                zeroRows[rowIdx] = zeroRows[rowIdx] || (row[columnIdx] == 0);
                zeroColumns[columnIdx] = zeroColumns[columnIdx] || (row[columnIdx] == 0);
            }
        }
        for (auto rowIdx = 0; rowIdx < zeroRows.size(); ++rowIdx)
        {
            if (zeroRows[rowIdx])
            {
                std::fill(std::begin(matrix[rowIdx]), std::end(matrix[rowIdx]), 0);
            }
        }
        for (auto colIdx = 0; colIdx < zeroColumns.size(); ++colIdx)
        {
            if (zeroColumns[colIdx])
            {
                for (auto rowIdx = 0; rowIdx < matrix.size(); ++rowIdx)
                {
                    matrix[rowIdx][colIdx] = 0;
                }
            }
        }
    }
};