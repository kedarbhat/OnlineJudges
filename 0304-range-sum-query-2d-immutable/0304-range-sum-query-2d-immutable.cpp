class NumMatrix {
    vector<vector<int>> theSummedTable;
public:
    NumMatrix(const vector<vector<int>>& matrix) noexcept : theSummedTable(matrix.size()+1, std::vector<int>(matrix[0].size()+1)) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        for (auto i = 1; i <= numRows; ++i) {
            for (auto j = 1; j <= numCols; ++j) {
                theSummedTable[i][j] = matrix[i-1][j-1] + theSummedTable[i-1][j] + theSummedTable[i][j-1] - theSummedTable[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) const noexcept {
         return theSummedTable[row2+1][col2+1] + theSummedTable[row1][col1] - theSummedTable[row1][col2+1] - theSummedTable[row2+1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */